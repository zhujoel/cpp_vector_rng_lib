
#include <math.h>

#include "DistributionNormale.h"

DistributionNormale::DistributionNormale(unsigned long int dim, double mean, double var):Distribution(dim){
    this->mean = mean;
    this->var = var;
}

DistributionNormale::DistributionNormale(const DistributionNormale& d):Distribution(d){
    this->mean = mean;
    this->var = var;
}

void DistributionNormale::random_draws(){
    //this->vec.fillRandomly(); TODO
}

double DistributionNormale::cdf(double x){
    return erfc(-(x-this->mean)/(sqrt(this->var)*sqrt(2))) /2;
}

double DistributionNormale::pdf(double x){
    return exp(- (0.5 * (x-this->mean) * (x-this->mean) )/ this->var) / sqrt(2*M_PI*this->var);
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
