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
        Dvector(std::string filename); // Remplit le tableau à partir d'un nom de fichier
        ~Dvector();
        Dvector(const Dvector& vec); // Constructeur par copie profonde
        void display(std::ostream& str);
        unsigned int size() const; // accesseur sur la dimension
        // remplit le tableau selon la loi uniforme [0, 1]
        // utilise la fonction random
        // TODO: ask teacher if it's necessary to put const at the end
        // because we don't change pointer
        void fillRandomly();
        
        // redéfinition des opérateurs
        // accède à une valeur du tableau
        // index commence par 0
        // TODO: ask teacher about valgrind
        double& operator()(int index) const;
        // addition par un réel
        // on ajoute le réel à chaque valeur du tableau
        Dvector& operator+=(double d);
};

#endif