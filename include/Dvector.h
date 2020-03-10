#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>

class Dvector{
    private:
        // dimension du vecteur
        unsigned int dim;
        // valeurs du vecteur
        double *values;
    public:
        Dvector(); // Constructeur par défaut
        Dvector(unsigned int dim, double value = 0.0);
        Dvector(const Dvector &P, double value); //Constructeur par copie profonde avec ajout d'une nouvelle valeur
        Dvector(std::string filename); // Remplit le tableau à partir d'un nom de fichier
        ~Dvector();
        Dvector(const Dvector& vec); // Constructeur par copie profonde
        void display(std::ostream& str) const;
        unsigned int size() const; // accesseur sur la dimension
        // remplit le tableau selon la loi uniforme [0, 1]. utilise la fonction random
        void fillRandomly();
        
        // redéfinition des opérateurs
        // accède à une valeur du tableau. index commence par 0
        double& operator()(int index) const;
        // opération avec un réel. on modifie le this. on transforme chaque valeur du vecteur avec le réel.
        Dvector& operator+=(double d);
        Dvector& operator-=(double d);
        Dvector& operator*=(double d);
        Dvector& operator/=(double d);
        // opération avec un vecteur. on travaille coordonnée à coordonnée des deux vecteurs de même taille.
        Dvector& operator+=(const Dvector &Q);
        Dvector& operator-=(const Dvector &Q);
        
        // operations avec réel et vecteur. on renvoie une copie. on transforme chaque valeur du vecteur avec le réel.
        Dvector operator+(double d) const;
        Dvector operator-(double d) const;
        Dvector operator*(double d) const;
        Dvector operator/(double d) const;
        Dvector operator+(const Dvector &Q) const;
        Dvector operator-(const Dvector &Q) const;

        // opérateur d'affectation
        Dvector& operator=(const Dvector &);
        Dvector& operator=(Dvector &&);

        Dvector& operator-();
        bool operator==(const Dvector &Q) const;
        bool operator!=(const Dvector &Q) const;

        void resize(unsigned int newDim, double value = 0.0);
};

// opérations externes pour pouvoir faire 3*vector.
Dvector operator+(const double &, const Dvector &);
Dvector operator-(const double &, const Dvector &);
Dvector operator*(const double &, const Dvector &);

//operateurs de redirection de flux
std::ostream & operator<<(std::ostream &, const Dvector &); // Affichage
Dvector & operator<<(Dvector &, const double &); // Ajoute une valeur dans le vecteur
std::istream & operator>>(std::istream &, Dvector &); // Remplace les valeurs

#endif