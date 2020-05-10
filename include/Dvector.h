#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>

/**
 * @author Philippe Morais, Joel Zhu
 */

class Dvector{
    private:
        unsigned int dim; /** < dimension du vecteur */
        double *values; /** < valeurs du vecteur */
    public:
    
        /**
         * Constructeur par défaut.
         */
        Dvector();
        /**
         * Constructeur qui initialise la taille et les valeurs du vecteur.
         * Les valeurs sont à zéro par défaut.
         * 
         * @param dim Dimension du vecteur.
         * @param value Valeurs initiales du vecteur.
         */
        Dvector(unsigned int dim, double value = 0.0);
        /**
         * Constructeur par copie profonde.
         * 
         * @param P Vecteur à copier.
         */
        Dvector(const Dvector& P);
        /**
         * Constructeur par copie profonde avec ajout d'une nouvelle valeur.
         * 
         * @param P Vecteur à copier
         * @param value Valeur à insérer
         */
        Dvector(const Dvector& P, double value);
        /**
         * Constructeur créant le vecteur à partir d'un fichier d'entrée ayant un nombre à chaque ligne.
         * 
         * @param filename Nom du fichier à prendre en entrée.
         */
        Dvector(std::string filename);
        /**
         * Destructeur.
         */
        ~Dvector();
        /**
         * Affiche le vecteur.
         * 
         * @param str Flux dans lequel afficher.
         */
        void display(std::ostream& str) const;
        /**
         * Accesseur sur la dimension du vecteur.
         * 
         * @return La dimension du vecteur.
         */
        unsigned int size() const;
        /**
         * Remplit le vecteur selon un générateur aléatoire donné.
         */
        void fillRandomly();
        
        /**
         * Accède à une valeur du vecteur.
         * 
         * @param index Index de la valeur dans le vecteur. L'index commence par 0.
         * @return Valeur correspondant à l'index dans le vecteur.
         */
        double& operator()(int index) const;
        /**
         * Additionne chaque valeur du vecteur par un réel.
         * 
         * @param d Réel par lequel additioner.
         * @return Le vecteur this modifié.
         */
        Dvector& operator+=(double d);
        /**
         * Soustrait chaque valeur du vecteur par un réel.
         * 
         * @param d Réel par lequel soustraire.
         * @return Le vecteur this modifié.
         */
        Dvector& operator-=(double d);
        /**
         * Multiplie chaque valeur du vecteur par un réel.
         * 
         * @param d Réel par lequel multiplier.
         * @return Le vecteur this modifié.
         */
        Dvector& operator*=(double d);
        /**
         * Divise chaque valeur du vecteur par un réel.
         * 
         * @param d Réel par lequel diviser.
         * @return Le vecteur this modifié.
         */
        Dvector& operator/=(double d);
        /**
         * Additionne chaque valeur coordonnée par coordonnée de deux vecteurs de même taille.
         * 
         * @param Q Vecteur avec lequel additionner.
         * @return Le vecteur this modifié.
         * @throw std::logic_error Si les vecteurs n'ont pas la même taille.
         */
        Dvector& operator+=(const Dvector &Q);
        /**
         * Soustrait chaque valeur coordonnée par coordonnée de deux vecteurs de même taille.
         * 
         * @param Q Vecteur avec lequel soustraire.
         * @return Le vecteur this modifié.
         * @throw std::logic_error Si les vecteurs n'ont pas la même taille.
         */
        Dvector& operator-=(const Dvector &Q);
        
        /**
         * Additionne chaque valeur du vecteur par un réel et renvoie une copie.
         * 
         * @param d Réel par lequel additionner.
         * @return Un nouveau vecteur résultant de l'opération.
         */
        Dvector operator+(double d) const;
        /**
         * Soustrait chaque valeur du vecteur par un réel et renvoie une copie.
         * 
         * @param d Réel par lequel soustraire.
         * @return Un nouveau vecteur résultant de l'opération.
         */
        Dvector operator-(double d) const;
        /**
         * Multiplie chaque valeur du vecteur par un réel et renvoie une copie.
         * 
         * @param d Réel par lequel multiplier.
         * @return Un nouveau vecteur résultante de l'opération.
         */
        Dvector operator*(double d) const;
        /**
         * Divise chaque valeur du vecteur par un réel et renvoie une copie.
         * 
         * @param d Réel par lequel diviser.
         * @return Un nouveau vecteur résultante de l'opération.
         */
        Dvector operator/(double d) const;

        /**
         * Additionne chaque valeur coordonnée par coordonnée de deux vecteurs de même taille et renvoie une copie.
         * 
         * @param Q Vecteur avec lequel additionner.
         * @return Un nouveau vecteur résultante de l'opération.
         * @throw std::logic_error Si les vecteurs n'ont pas la même taille.
         */
        Dvector operator+(const Dvector &Q) const;

        /**
         * Soustrait chaque valeur coordonnée par coordonnée de deux vecteurs de même taille et renvoie une copie.
         * 
         * @param Q Vecteur avec lequel soustraire.
         * @return Un nouveau vecteur résultante de l'opération.
         * @throw std::logic_error Si les vecteurs n'ont pas la même taille.
         */
        Dvector operator-(const Dvector &Q) const;

        /**
         * Affecte un vecteur par copie mémoire. Les tableaux des deux vecteurs peuvent se chevaucher, memmove est donc utilisé.
         * 
         * @param Q Vecteur à copier.
         * @return Pointer this modifié.
         */
        Dvector& operator=(const Dvector &Q);
        /**
         * Recopie par déplacement mémoire. Le vecteur recopié est détruit après le déplacement.
         * 
         * @param Q Vecteur à déplacer.
         * @return Nouveau pointeur du vecteur.
         */
        Dvector& operator=(Dvector &&Q);

        /**
         * Modifie les valeurs du vecteur par leur valeur opposée.
         * 
         * @return Vecteur this modifié.
         */
        Dvector& operator-();

        /**
         * Compare deux vecteurs. Renvoie True si les vecteurs sont de même dimension et ont les mêmes valeurs, False sinon.
         * 
         * @param Q Vecteur avec lequel comparer.
         * @return True si les valeurs sont identiques, faux sinon.
         */
        bool operator==(const Dvector &Q) const;
        /**
         * Compare deux vecteurs. Renvoie True si les vecteurs sont différents, False sinon.
         * 
         * @param Q Vecteur avec lequel comparer.
         * @return True si les valeurs sont identiques, False sinon.
         */
        bool operator!=(const Dvector &Q) const;

        /**
         * Redimensionne le vecteur. Possibilité de définir les nouvelles valeurs lors de la redimension.
         * 
         * @param newDim Nouvelle dimension du vecteur.
         * @param value Nouvelles valeurs du vecteur.
         */
        void resize(unsigned int newDim, double value = 0.0);
};

/**
 * Opérateur d'addition externe. Permet d'écrire : 3+vec.
 * 
 * @param d Réel avec lequel additionner. 
 * @param Q Vecteur à additionner.
 * @return Vecteur modifié.
 * @see operator+(double d)
 */
Dvector operator+(const double &d, const Dvector &Q);
/**
 * Opérateur de soustraction externe. Permet d'écrire : 3-vec.
 * 
 * @param d Réel avec lequel soustraire. 
 * @param Q Vecteur à soustraire.
 * @return Vecteur modifié.
 * @see operator-(double d)
 */
Dvector operator-(const double &d, const Dvector &Q);
/**
 * Opérateur de multiplication externe. Permet d'écrire : 3*vec.
 * 
 * @param d Réel avec lequel multiplier. 
 * @param Q Vecteur à multiplier.
 * @return Vecteur modifié.
 * @see operator*(double d)
 */
Dvector operator*(const double &d, const Dvector &Q);

/**
 * Affiche un vecteur dans un flux.
 * 
 * @param output Flux dans lequel afficher.
 * @param P Vecteur à afficher.
 * @return Flux modifié.
 */
std::ostream & operator<<(std::ostream &output, const Dvector &P);

/**
 * Ajoute un réel dans un vecteur en utilisant l'opérateur de redirection.
 * 
 * @param P Vecteur à modifier.
 * @param d Réel à insérer.
 * @return Vecteur modifié.
 */
Dvector & operator<<(Dvector &P, const double &d);
/**
 * Recrée un vecteur à partir d'un flux d'entrée. Permet de recréer des objets redirigés par l'opérateur <<.
 * 
 * @param input Flux d'entrée.
 * @param P Vecteur à recréer.
 * 
 * @return Flux modifié.
 */
std::istream & operator>>(std::istream &input, Dvector &P); // Remplace les valeurs

#endif