#include "gtest/gtest.h"
#include "GenerateurParkMiller.h"
#include <fstream>

#include <chrono>

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

TEST_F(GenerateurParkMillerTest, ConstructeurRecopie){
    GenerateurParkMiller g1(3,19);
    GenerateurParkMiller g2(g1);
    for(unsigned int i=0; i<1000; i++){
        EXPECT_EQ(g1.generate(), g2.generate());
    }
}

TEST_F(GenerateurParkMillerTest, clone){
    GenerateurParkMiller g1(3,19);
    GenerateurParkMiller* g2 = g1.clone();
    for(unsigned int i=0; i<1000; i++){
        EXPECT_EQ(g1.generate(), g2->generate());
    }
    delete g2;
}

TEST_F(GenerateurParkMillerTest, set_getSeed){
    GenerateurParkMiller genParkMiller(1,13);
    genParkMiller.set_seed(5);
    EXPECT_EQ(genParkMiller.get_seed(),5);
}

TEST_F(GenerateurParkMillerTest, resetSeed){
    GenerateurParkMiller genParkMiller(1,13);
    unsigned int a1 = genParkMiller.generate();
    unsigned int a2 = genParkMiller.generate();
    genParkMiller.reset_seed();
    unsigned int b1 = genParkMiller.generate();
    unsigned int b2 = genParkMiller.generate();
    EXPECT_EQ(a1,b1);
    EXPECT_EQ(a2,b2);
}

TEST_F(GenerateurParkMillerTest, generateDvector){
    GenerateurParkMiller genParkMiller(3,7);
    Dvector* dvec = genParkMiller.generateDvector();
    std::stringstream str;
    dvec->display(str);
    EXPECT_EQ("117649\n1977326743\n621132276\n", str.str());
    delete dvec;
}

/*
TEST_F(GenerateurParkMillerTest, performance){
    auto t1 = std::chrono::high_resolution_clock::now();
    GenerateurParkMiller genParkMiller(10000000,23671);
    genParkMiller.generateDvector();
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout<<"Durée pour la génération (microseconds) : "<<duration<<std::endl;
}*/

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
