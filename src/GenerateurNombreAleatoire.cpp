#include "GenerateurNombreAleatoire.h"

 
GenerateurNombreAleatoire::GenerateurNombreAleatoire(unsigned int dim){
    std::cout << "Constructeur dim" << std::endl;
    this->dimension = dim;
}
 
unsigned int GenerateurNombreAleatoire::getDimension() const{
    return this->dimension;
}
