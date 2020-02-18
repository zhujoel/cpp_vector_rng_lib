#include "Dvector.h"
#include <fstream>
#include <sstream>
#include <iomanip>

Dvector::Dvector(){
    std::cout << "Constructeur défaut" << std::endl;
    this->dim = 0;
    this->values = new double[this->dim];
}

Dvector::Dvector(unsigned int dim, double value){
    std::cout << "Constructeur dim/value" << std::endl;
    this->dim = dim;
    this->values = new double[this->dim];
    for(unsigned int i = 0; i < this->dim; ++i){
        this->values[i] = value;
    }
}

Dvector::Dvector(std::string filename){
    std::cout << "Constructeur filename" << std::endl;
    unsigned int dim = 0;
    // flux du fichier
    std::ifstream iFile(filename);
    if (iFile.is_open())
    {
        // ligne du fichier
        std::string line;

        // première passe pour avoir la dimension
        while(getline(iFile, line))
        {
            if(line.empty())
                continue;
            dim++;
        }
        // on ferme puis on le réouvre pour remettre le pointeur au début
        iFile.close();

        this->values = new double[dim];
        // pointeur dans le tableau
        unsigned int i=0;
        std::ifstream iFile(filename);
        // deuxieme passe pour affecter les valeurs
        while(getline(iFile, line))
        {
            if(line.empty())
                continue;
            std::stringstream value(line);
            value >> this->values[i];
            i++;
        }
    }
    // si le fichier n'existe pas
    else {
        std::cerr << "Couldn't open config file for reading.\n";
        this->values = new double[0];
    }
    this->dim = dim;
}

Dvector::~Dvector(){
    std::cout << "Destructeur" << std::endl;
    delete[] this->values;
}

Dvector::Dvector(const Dvector & vec){
    std::cout << "Constructeur par copie" << std::endl;
    this->dim = vec.dim;
    this->values = new double[this->dim];
    for(unsigned int i = 0; i < this->dim; ++i){
        this->values[i] = vec.values[i];
    }
}

void Dvector::display(std::ostream& str){
    for(unsigned int i = 0; i < this->dim; ++i){
        // on affiche les 20 premières decimals
        str << std::setprecision(20) << this->values[i] << std::endl;
    }
}

unsigned int Dvector::size() const{
    return this->dim;
}

void Dvector::fillRandomly(){
    for(unsigned int i = 0; i < this->dim; ++i){
        this->values[i] = ((double)rand() / (RAND_MAX));
    }
}

double& Dvector::operator()(int index) const{
    if(index < 0 || index > (int)this->dim){
        // TODO: Compléter l'exception
        throw;
    }
    return this->values[index];
}

Dvector& Dvector::operator+=(double d){
    for(unsigned int i = 0; i < this->dim; ++i){
        this->values[i] = 5 + d;
    }
    return *this;
}