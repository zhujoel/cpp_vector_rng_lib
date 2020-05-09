#ifndef GENERATEURXORSHIFT_H
#define GENERATEURXORSHIFT_H

#include "GenerateurNombreAleatoire.h"

class GenerateurXorshift : public GenerateurNombreAleatoire{
    private:
        unsigned long int seed;
        unsigned long int initialSeed;

        unsigned int a1;
        unsigned int a2;
        unsigned int a3;
   
 
    public:
        GenerateurXorshift(unsigned long int, unsigned int, unsigned int, unsigned int);
        GenerateurXorshift(const GenerateurXorshift&);
        ~GenerateurXorshift()=default;
 
        GenerateurNombreAleatoire* clone() const;
        void set_seed(unsigned long int);
        unsigned long int get_seed() const;
        void reset_seed();
        unsigned long int generate();

};

#endif
