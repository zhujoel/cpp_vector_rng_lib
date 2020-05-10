#include "gtest/gtest.h"
#include "GenerateurParkMiller.h"
#include <fstream>

class GenerateurParkMillerTest: public ::testing::Test{
    protected:
        virtual void SetUp(){
        }

        virtual void TearDown(){
        }
};

TEST_F(GenerateurParkMillerTest, constructorDefault){
    GenerateurParkMiller genParkMiller(3,7);
    std::stringstream str;
    for(unsigned int i=0; i<3; i++){
        str<<genParkMiller.generate()<<std::endl;
    }
    EXPECT_EQ("117649\n1977326743\n621132276\n", str.str());
}

TEST_F(GenerateurParkMillerTest, clone){
    GenerateurParkMiller g1(3,19);
    GenerateurNombreAleatoire* g2 = g1.clone();

    for(unsigned int i=0; i<1000; i++){
        EXPECT_EQ(g1.generate(), g2->generate());
    }
}
/*
TEST_F(GenerateurParkMillerTest, exception){
    GenerateurParkMiller g1(3,7,19);
}*/

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
