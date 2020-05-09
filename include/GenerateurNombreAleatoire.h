#ifndef GENERATEURNOMBREALEATOIRE_H
#define GENERATEURNOMBREALEATOIRE_H

#include <iostream>

class GenerateurNombreAleatoire{
    private:
        // dimensionnalité
        unsigned int dimension;
   
    public:
        GenerateurNombreAleatoire()=default;
        GenerateurNombreAleatoire(unsigned int);
        GenerateurNombreAleatoire(const GenerateurNombreAleatoire&)=delete;
        ~GenerateurNombreAleatoire()=default;
 
        GenerateurNombreAleatoire& operator=(const GenerateurNombreAleatoire&)=delete;
       
        virtual GenerateurNombreAleatoire* clone() const=0;
        unsigned int getDimension() const; // accesseur
 
        virtual void set_seed(unsigned int)=0;
        virtual unsigned int get_seed() const=0;
        virtual void reset_seed()=0;
        virtual unsigned int generate()=0;
       
};
 
#endif
