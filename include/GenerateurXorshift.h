#ifndef GENERATEURXORSHIFT_H
#define GENERATEURXORSHIFT_H

#include "GenerateurNombreAleatoire.h"
/**
 * @author Philippe Morais, Joel Zhu
 * @file GenerateurXorshift.h
 */

/**
 * @class GenerateurXorshift
 * 
 * Représente un générateur de nombres aléatoires implémenté selon la méthode du XorShift.
 */
class GenerateurXorshift : public GenerateurNombreAleatoire{
    private:
        unsigned long int seed; /** < Seed courant du générateur. */
        unsigned long int initialSeed; /** < Seed initiale du générateur. */

        unsigned int a1; /** < Paramètre a1 du générateur */
        unsigned int a2; /** < Paramètre a2 du générateur */
        unsigned int a3; /** < Paramètre a3 du générateur */
   
 
    public:
        /**
         * Constructeur qui initialise la seed du générateur et les valeurs des paramètres.
         * 
         * @param x0 Seed initiale du générateur.
         * @param a1 Paramètre a1 du générateur.
         * @param a2 Paramètre a2 du générateur.
         * @param a3 Paramètre a3 du générateur.
         */
        GenerateurXorshift(unsigned int, unsigned long int, unsigned int, unsigned int, unsigned int);
        /**
         * Constructeur par copie profonde. Recopie les paramètres et la seed d'un autre générateur.
         * 
         * @param gen Générateur à recopier.
         */
        GenerateurXorshift(const GenerateurXorshift&);
        /**
         * Destructeur.
         */
        ~GenerateurXorshift()=default;
 
        /**
         * Retourne une copie profonde du générateur.
         * 
         * @return Pointeur vers le clone du générateur. 
         */
        GenerateurXorshift* clone() const;

        /**
         * Modifie la seed du générateur. Initialise la seed initiale du générateur.
         * 
         * @param seed Seed du générateur.
         * @throw std::domain_error Si la contrainte de la seed n'est pas respectée.
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
         * Calcule la prochaine valeur du générateur XorShift et le renvoie.
         * 
         * @return La prochaine valeur du générateur.
         */
        unsigned long int generate();

};

#endif
