#include "GenerateurNombreAleatoire.h"

 
GenerateurNombreAleatoire::GenerateurNombreAleatoire(unsigned int dim){
    std::cout << "Constructeur dim" << std::endl;
    this->dimension = dim;
}
 
unsigned int GenerateurNombreAleatoire::getDimension() const{
    return this->dimension;
}

Dvector* GenerateurNombreAleatoire::generateDvector(){
    Dvector* dvec = new Dvector(this->dimension);
    for(unsigned int i=0; i<this->dimension; i++){
        (*dvec)(i) = this->generate();
    }
    return dvec;
}
