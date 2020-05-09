#include <algorithm>

#include "GenerateurParkMiller.h"

GenerateurParkMiller::GenerateurParkMiller(unsigned int x0, unsigned int a, unsigned int m){
    if (m<=0) {
        throw;
    } 
    if (a<=0 || a>=m){
        throw;
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

unsigned int GenerateurParkMiller::generate(){
    if (this->n>=this->m){
        throw;
    }
    this->n++;
    this->seed = ( this->a *( this->seed - (this->seed /q)*q) - this->r *(this->seed /q) ) % this->m;
    return this->seed;
}

void GenerateurParkMiller::set_seed(unsigned int seed){
    if (seed<=0 || seed>=m){
        throw;
    }
    if (std::__gcd(this->m, seed)!=1){
        throw;
    }
    this->n = 0;
    this->seed = seed;
    this->initialSeed = seed;
}
 
unsigned int GenerateurParkMiller::get_seed() const{
    return this->seed;
}
 
void GenerateurParkMiller::reset_seed(){
    this->n = 0;
    this->seed = this->initialSeed;
}
