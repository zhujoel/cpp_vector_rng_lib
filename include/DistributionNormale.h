#ifndef DISTRIBUTIONNORMALE_H
#define DISTRIBUTIONNORMALE_H

#include "Distribution.h"

class DistributionNormale: public Distribution{
    public:
        DistributionNormale(unsigned long int dim);
        DistributionNormale(const DistributionNormale&);
        ~DistributionNormale()=default;
 
        double pdf();
	double inv_cdf();
};

#endif
