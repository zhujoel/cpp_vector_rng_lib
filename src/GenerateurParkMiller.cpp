#include <algorithm>

#include "GenerateurParkMiller.h"

GenerateurParkMiller::GenerateurParkMiller(unsigned long int x0, unsigned int a, unsigned int m){
    if (m<=0) {
        throw std::domain_error("m should be greater than 0");
    } 
    if (a<=0 || a>=m){
        throw std::domain_error("a should be greater than 0 and lower than m");
    }
    this->a = a;
    this->m = m;
    set_seed(x0);
}

GenerateurParkMiller::GenerateurParkMiller(const GenerateurParkMiller& gen){
    this->a = gen.a;
    this->m = gen.m;
    set_seed(gen.get_seed());
}

GenerateurNombreAleatoire* GenerateurParkMiller::clone() const{
    return new GenerateurParkMiller(*this);
}

unsigned long int GenerateurParkMiller::generate(){
    if (this->n>=this->m){
        throw std::logic_error("impossible to generate more than m numbers");
    }
    this->n++;
    this->seed = ( this->a *( this->seed - (this->seed /q)*q) - this->r *(this->seed /q) ) % this->m;
    return this->seed;
}

void GenerateurParkMiller::set_seed(unsigned long int seed){
    if (seed<=0 || seed>=m){
        throw std::domain_error("the seed should be greater than 0 and lower then m");
    }
    if (std::__gcd((unsigned long int) this->m, seed)!=1){
        throw std::invalid_argument("the seed and m should be co-prime");
    }
    this->n = 0;
    this->seed = seed;
    this->initialSeed = seed;
}
 
unsigned long int GenerateurParkMiller::get_seed() const{
    return this->seed;
}
 
void GenerateurParkMiller::reset_seed(){
    this->n = 0;
    this->seed = this->initialSeed;
}
