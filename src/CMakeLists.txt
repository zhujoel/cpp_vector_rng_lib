add_library(Dvector STATIC Dvector.cpp) # On lie la librarie au cpp

add_library(GenerateurNombreAleatoire STATIC GenerateurNombreAleatoire.cpp)
add_library(GenerateurParkMiller STATIC GenerateurParkMiller.cpp)
add_library(GenerateurXorshift STATIC GenerateurXorshift.cpp)

add_library(Distribution STATIC Distribution.cpp)
add_library(DistributionNormale STATIC DistributionNormale.cpp)
