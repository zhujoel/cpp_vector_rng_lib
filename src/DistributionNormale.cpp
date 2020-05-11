
#include <math.h>

#include "DistributionNormale.h"

DistributionNormale::DistributionNormale(unsigned int dim, double mean, double var):Distribution(dim){
    this->mu = mean;
    this->sigma2 = var;
    this->random_draws();
}

DistributionNormale::DistributionNormale(const DistributionNormale& d):Distribution(d){
    this->mu = d.mu;
    this->sigma2 = d.sigma2;
}

void DistributionNormale::random_draws(){
    Dvector* U = this->getDistribution();
    unsigned int n = (*U).size();
    double tmp = (*U)(n/2);

    // Méthode de Box-Muller
    for(unsigned int i=0; i<n/2; i++){
        double uniform_1 = (*U)(2*i);
        double uniform_2 = (*U)(2*i+1);
        (*U)(2*i) = sqrt(-2.0*log(uniform_1)) * cos(2*M_PI*uniform_2);
        (*U)(2*i+1) = sqrt(-2.0*log(uniform_1)) * sin(2*M_PI*uniform_2);
    }

    // Adaptation dans le cas où le tableau n'a pas un nombre pair d'éléments
    if (n%2!=0){
        double uniform_1 = (*U)(n-1);
        double uniform_2 = tmp;
        (*U)(n) = sqrt(-2.0*log(uniform_1)) * cos(2*M_PI*uniform_2);
    }

    // Transformation affine si la distribution n'est pas centrée réduite
    if (this->mu!=0 || this->sigma2!=1){
        double sigma = sqrt(this->sigma2);
        for(unsigned int i=0; i<n; i++){
            (*U)(i) = sigma * (*U)(i) + this->mu;
        }
    }
}

double DistributionNormale::cdf(double x){
    return erfc(-(x-this->mu)/(sqrt(this->sigma2)*sqrt(2))) /2;
}

double DistributionNormale::pdf(double x){
    return exp(- (0.5 * (x-this->mu) * (x-this->mu) )/ this->sigma2) / sqrt(2*M_PI*this->sigma2);
}

double DistributionNormale::inv_cdf(double p){
    if (p <= 0.0 || p >= 1.0){
        throw std::invalid_argument("p should be greater than 0 an less than 1");
    }
    if (p < 0.5){
        return -RationalApproximation(sqrt(-2.0*log(p)));
    }
    else{
        return RationalApproximation(sqrt(-2.0*log(1-p)));
    }
}

double RationalApproximation(double t){
    // Abramowitz and Stegun formula 26.2.23.
    // The absolute value of the error should be less than 4.5 e-4.
    double c[] = {2.515517, 0.802853, 0.010328};
    double d[] = {1.432788, 0.189269, 0.001308};
    return t - ((c[2]*t + c[1])*t + c[0]) /
        (((d[2]*t + d[1])*t + d[0])*t + 1.0);
}
