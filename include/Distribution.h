#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "Dvector.h"

class Distribution{
    private:
        Dvector* vec;
    public:
        Distribution(unsigned int dim);
        Distribution(const Distribution&);
        ~Distribution();
 
        Distribution& operator=(const Distribution&)=delete;
 
        virtual void random_draws()=0;
 
        virtual double cdf(double) = 0;
        double mean();
        double var();
        double stdev();
        virtual double inv_cdf(double) = 0;
 
};
 
#endif
