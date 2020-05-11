#ifndef GENERATEURNOMBREALEATOIRE_H
#define GENERATEURNOMBREALEATOIRE_H

#include <iostream>
#include "Dvector.h"

/**
 * @author Philippe Morais, Joel Zhu
 * @file GenerateurNombreAleatoire.h
 */

/**
 * @class GenerateurNombreAleatoire
 * 
 * Représente un générateur de nombres aléatoires.
 */
class GenerateurNombreAleatoire{
    private:
        unsigned int dimension; /** < Dimension du générateur : nombre de valeurs aléatoires à générer. */
   
    public:
        /**
         * Constructeur par défaut.
         */
        GenerateurNombreAleatoire()=default;
        /**
         * Constructeur qui initialise la dimension du générateur.
         */
        GenerateurNombreAleatoire(unsigned int);
        /**
         * Constructeur par copie. Pas nécessaire ici.
         */
        GenerateurNombreAleatoire(const GenerateurNombreAleatoire&)=delete;
        /**
         * Destructeur
         */
        virtual ~GenerateurNombreAleatoire()=default;
    
        /**
         * Copie par affectation. Pas nécessaire ici.
         */
        GenerateurNombreAleatoire& operator=(const GenerateurNombreAleatoire&)=delete;

        /**
         * Retourne une copie profonde du générateur.
         * 
         * @return Pointeur vers le clone du générateur. 
         */
        virtual GenerateurNombreAleatoire* clone() const=0;

        /**
         * Accesseur sur la dimension du générateur.
         * 
         * @return Dimension du générateur.
         */
        unsigned int getDimension() const;
        /**
         * Modifie la seed du générateur. Initialise la seed initiale du générateur.
         * 
         * @param seed Seed du générateur.
         */
        virtual void set_seed(unsigned long int)=0;
        /**
         * Accesseur sur la seed du générateur.
         * 
         * @return Seed du générateur.
         */
        virtual unsigned long int get_seed() const=0;
        /**
         * Réinitialise la seed du générateur à sa valeur initiale (définie à la création).
         */
        virtual void reset_seed()=0;
        /**
         * Génère la prochaine valeur aléatoire du générateur. La seed est modifiée à chaque appel.
         * 
         * @return La prochaine valeur du générateur.
         */
        virtual unsigned long int generate()=0;
        /**
         * Crée un Dvector de taille dimension rempli de nombres aléatoires.
         * 
         * @return Dvector.
         */
        Dvector* generateDvector();
	

       
};
 
#endif
