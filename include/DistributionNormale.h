#ifndef DISTRIBUTIONNORMALE_H
#define DISTRIBUTIONNORMALE_H

#include "Distribution.h"

/**
 * @author Philippe Morais, Joel Zhu
 * @file DistributionNormale.h
 */

/**
 * @class DistributionNormale
 * 
 * Représente la loi de probabilité normale.
 */
class DistributionNormale: public Distribution{
    private:
        double mean;
        double var;
    public:
        DistributionNormale(unsigned long int dim, double mean=0, double var=1);
        DistributionNormale(const DistributionNormale&);
        ~DistributionNormale()=default;

        void random_draws();

        double cdf(double);
        double pdf(double);
	double inv_cdf(double);
};

double RationalApproximation(double t);

#endif
