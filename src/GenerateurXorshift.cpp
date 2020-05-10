#include "GenerateurXorshift.h"

GenerateurXorshift::GenerateurXorshift(unsigned long int x, unsigned int a1, unsigned int a2, unsigned int a3){
    this->a1 = a1;
    this->a2 = a2;
    this->a3 = a3;
    set_seed(x);
}

GenerateurXorshift::GenerateurXorshift(const GenerateurXorshift& gen){
    this->a1 = gen.a1;
    this->a2 = gen.a2;
    this->a3 = gen.a3;
    set_seed(gen.get_seed());
}

GenerateurNombreAleatoire* GenerateurXorshift::clone() const{
    return new GenerateurXorshift(*this);
}

unsigned long int GenerateurXorshift::generate(){
    unsigned long int x = this->seed;

    x = x ^ (x<<this->a1);
    x = x ^ (x>>this->a2);
    x = x ^ (x<<this->a3);

    this->seed = x;
    return this->seed;
}

void GenerateurXorshift::set_seed(unsigned long int seed){
    if (seed<=0){
        throw std::domain_error("the seed should be greater than 0");
    }
    this->seed = seed;
    this->initialSeed = seed;
}
 
unsigned long int GenerateurXorshift::get_seed() const{
    return this->seed;
}
 
void GenerateurXorshift::reset_seed(){
    this->seed = this->initialSeed;
}
