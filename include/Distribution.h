#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "Dvector.h"

/**
 * @author Philippe Morais, Joel Zhu
 * @file Distribution.h
 */

/**
 * @class Distribution
 * 
 * Représente une loi de probabilité.
 */
class Distribution{
    private:
        
        Dvector* vec; /** < Echantillon de la loi de probabilité */
    public:

        /**
         * Constructeur qui initialise l'échantillon avec une dimension.
         * 
         * @param dim Dimension de l'échantillon.
         */
        Distribution(unsigned int dim);
        /**
         * Constructeur par copie profonde. Copie l'échantillon.
         * 
         * @param dis Distribution à copier.
         */
        Distribution(const Distribution&);
        /**
         * Destructeur.
         */
        ~Distribution();

        /**
         * Copie par affectation. Pas nécessaire ici.
         */
        Distribution& operator=(const Distribution&)=delete;

        /**
         * Transforme une distribution uniforme en une autre distribution.
         */
        virtual void random_draws()=0;
 
        /**
         * Calcule la fonction de répartition.
         * 
         * @param x Valeur x d'entrée
         * @return Probabilité associée.
         */
        virtual double cdf(double) = 0;

        /**
         * Calcule la densité de probabilité.
         * 
         * @param x Valeur x d'entrée
         * @return Densité de probabilité associée.
         */
        virtual double pdf(double) = 0;

        /**
         * Calcule la moyenne empirique.
         * 
         * @return La moyenne empirique de la loi de probabilité.
         */
        double mean();

        /**
         * Calcule la variance empirique.
         * 
         * @return La variance empirique de la loi de probabilité.
         */
        double var();

        /**
         * Calcule l'écart-type empirique.
         * 
         * @return L'écart-type empirique de la loi de probabilité.
         */
        double stdev();

        /**
         * Calcule la transformée inverse.
         * 
         * @param p Paramètre p d'entré.
         * @return La valeur x associée.
         */
        virtual double inv_cdf(double) = 0;
 
};
 
#endif
