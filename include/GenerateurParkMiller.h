#ifndef GENERATEURPARKMILLER_H
#define GENERATEURPARKMILLER_H

#include "GenerateurNombreAleatoire.h"
/**
 * @author Philippe Morais, Joel Zhu
 * @file GenerateurParkMiller.h
 */

/**
 * @class GenerateurParkMiller
 * 
 * Représente un générateur de nombres aléatoires implémenté selon l'algorithme de Park-Miller.
 */
class GenerateurParkMiller : public GenerateurNombreAleatoire{
    private:
        unsigned long int seed; /** < Seed courant du générateur. */
        unsigned long int initialSeed; /** < Seed initiale du générateur. */
        unsigned int n; /** < Compteur de nombres générés. */

        unsigned int a; /** < Paramètre a de l'algorithme. */
        unsigned int m; /** < Modulo de l'algorithme. */
        static const unsigned int q = 127773; /** < Paramètre q de l'algorithme. 127773 est une valeur ayant des bonnes propriétés. */
        static const unsigned int r = 2836; /** < Paramètre r de l'algorithme. 2836 est une valeur ayant des bonnes propriétés. */
 
    public:
        /**
         * Constructeur qui initialise la seed du générateur et les valeurs des paramètres.
         * 
         * @param x0 Seed initiale du générateur.
         * @param a Paramètre a du générateur. a = 16807 est une valeur ayant des bonnes propriétés.
         * @param m Paramètre m du générateur. m = 21474836 est une valeur ayant des bonnés propriétés.
         * @throw std::domain_error Si les contraintes sur les paramètres ne sont pas respectées.
         */
        GenerateurParkMiller(unsigned long int x0, unsigned int a=16807, unsigned int m=2147483647);
        /**
         * Constructeur par copie profonde. Recopie les paramètres et la seed d'un autre générateur.
         * 
         * @param gen Générateur à recopier.
         */
        GenerateurParkMiller(const GenerateurParkMiller&);
        /**
         * Destructeur.
         */
        ~GenerateurParkMiller()=default;
 
        /**
         * Retourne une copie profonde du générateur.
         * 
         * @return Pointeur vers le clone du générateur. 
         */
        GenerateurNombreAleatoire* clone() const;
        
        /**
         * Modifie la seed du générateur. Initialise la seed initiale du générateur.
         * 
         * @param seed Seed du générateur.
         * @throw std::domain_error Si la contrainte de la seed n'est pas respectée.
         * @throw std::invalid_argument Si la seed et m ne sont pas premiers entre eux.
         */
        void set_seed(unsigned long int);
        
        /**
         * Accesseur sur la seed du générateur.
         * 
         * @return Seed du générateur.
         */
        unsigned long int get_seed() const;
        /**
         * Réinitialise la seed du générateur à sa valeur initiale (définie à la création).
         */
        void reset_seed();
        /**
         * Calcule la prochaine valeur du générateur Park-Miller et le renvoie. Incrémente le compteur.
         * 
         * @return La prochaine valeur du générateur.
         * @throw std::logic_error Si trop de valeurs ont déjà été générés (n > m).
         */
        unsigned long int generate();

};

#endif
