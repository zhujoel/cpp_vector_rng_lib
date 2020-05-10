#include <math.h>

#include "Distribution.h"

Distribution::Distribution(unsigned int dim){
    this->vec = new Dvector(dim);
}

Distribution::Distribution(const Distribution& d){
    this->vec = new Dvector(*(d.vec));
}

Distribution::~Distribution(){
    delete this->vec;
}

double Distribution::mean(){
    double somme = 0;
    for(unsigned int i=0; i<this->vec->size(); i++){
        somme += (*(this->vec))(i);
    }
    return somme/this->vec->size();
}

double Distribution::var(){
    double somme = 0;
    double m = this->mean();
    for(unsigned int i=0; i<this->vec->size(); i++){
        somme += ((*(this->vec))(i) - m) * ((*(this->vec))(i) - m);
    }
    return somme/this->vec->size();
}

double Distribution::stdev(){
    return sqrt(this->var());
}



