#ifndef GENERATEURPARKMILLER_H
#define GENERATEURPARKMILLER_H

#include "GenerateurNombreAleatoire.h"

class GenerateurParkMiller : public GenerateurNombreAleatoire{
    private:
        unsigned int seed;
        unsigned int initialSeed;
        unsigned int n;

        unsigned int a;
        unsigned int m;
        static const unsigned int q = 127773;
        static const unsigned int r = 2836;
 
    public:
        GenerateurParkMiller(unsigned int x0, unsigned int a=16807, unsigned int m=2147483647);
        GenerateurParkMiller(const GenerateurParkMiller&);
        ~GenerateurParkMiller()=default;
 
        GenerateurNombreAleatoire* clone() const;
        void set_seed(unsigned int);
        unsigned int get_seed() const;
        void reset_seed();
        unsigned int generate();

};

#endif
