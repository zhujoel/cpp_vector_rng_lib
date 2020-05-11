#ifndef DISTRIBUTIONNORMALE_H
#define DISTRIBUTIONNORMALE_H

#include "Distribution.h"

/**
 * @author Philippe Morais, Joel Zhu
 * @file DistributionNormale.h
 */

/**
 * @class DistributionNormale
 * 
 * Représente la loi de probabilité normale.
 */
class DistributionNormale: public Distribution{
    private:
        double mu; /** < Moyenne de la loi de probabilité. */
        double sigma2; /** < Variance de la loi de probabilité. */
    public:
DistributionNormale()=default;

        /**
         * Constructeur qui initialise la loi de probabilité normale avec ses paramètres. Loi standard par défaut.
         * 
         * @param dim Dimension de l'échantillon.
         * @param mean Moyenne de la loi. 
         * @param var Variance de la loi.
         */
        DistributionNormale(unsigned int dim, double mean=0, double var=1);
        /**
         * Constructeur par copie profonde. Copie l'échantillon et les paramètres.
         * 
         * @param dis Distribution à copier.
         */
        DistributionNormale(const DistributionNormale&);
        /**
         * Destructeur.
         */
        ~DistributionNormale()=default;

        void random_draws(); //Utilise la transformation de Box-Muller

        /**
         * Calcule la fonction de répartition de la loi normale.
         * 
         * @param x Valeur x d'entrée
         * @return Probabilité associée.
         */
        double cdf(double);

        /**
         * Calcule la densité de probabilité.
         * 
         * @param x Valeur x d'entrée
         * @return Densité de probabilité associée.
         */
        double pdf(double);

        /**
         * Calcule la transformée inverse.
         * 
         * @param p Paramètre p d'entré.
         * @return La valeur x associée.
         */
	    double inv_cdf(double);
};

/**
 * Calcule l'approximation rationnelle d'un réel. Utilisée pour approximer la tranformée inverse.
 * 
 * @param t Réel à approximer.
 * @return La valeur approximée.
 */
double RationalApproximation(double t);

#endif
