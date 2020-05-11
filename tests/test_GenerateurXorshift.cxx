#include "gtest/gtest.h"
#include "GenerateurXorshift.h"
#include <fstream>

#include <chrono>

class GenerateurXorshiftTest: public ::testing::Test{
    protected:
        virtual void SetUp(){
        }

        virtual void TearDown(){
        }
};

TEST_F(GenerateurXorshiftTest, constructorDefault){
    GenerateurXorshift genXorshift(3, 1, 21, 35, 4);
    std::stringstream str;
    for(unsigned int i=0; i<3; i++){
        str<<genXorshift.generate()<<std::endl;
    }
    EXPECT_EQ("35651601\n1130297953386881\n9242588279455355187\n", str.str());
}

TEST_F(GenerateurXorshiftTest, ConstructeurRecopie){
    GenerateurXorshift g1(3, 1, 21, 35, 4);
    GenerateurXorshift g2(g1);
    for(unsigned int i=0; i<1000; i++){
        EXPECT_EQ(g1.generate(), g2.generate());
    }
}

TEST_F(GenerateurXorshiftTest, clone){
    GenerateurXorshift g1(3, 1, 21, 35, 4);
    GenerateurXorshift* g2 = g1.clone();
    for(unsigned int i=0; i<1000; i++){
        EXPECT_EQ(g1.generate(), g2->generate());
    }
    delete g2;
}

TEST_F(GenerateurXorshiftTest, set_getSeed){
    GenerateurXorshift g(3, 1, 21, 35, 4);
    g.set_seed(5);
    EXPECT_EQ(g.get_seed(),5);
}

TEST_F(GenerateurXorshiftTest, resetSeed){
    GenerateurXorshift g(3, 1, 20, 41, 5);;
    unsigned int a1 = g.generate();
    unsigned int a2 = g.generate();
    g.reset_seed();
    unsigned int b1 = g.generate();
    unsigned int b2 = g.generate();
    EXPECT_EQ(a1,b1);
    EXPECT_EQ(a2,b2);
}

TEST_F(GenerateurXorshiftTest, generateDvector){
    GenerateurXorshift g(3, 1, 21, 35, 4);
    Dvector* dvec = g.generateDvector();
    std::stringstream str;
    dvec->display(str);
    EXPECT_EQ("35651601\n1130297953386881\n9242588279455354880\n", str.str());
    delete dvec;
}

/*
TEST_F(GenerateurXorshiftTest, performance){
    auto t1 = std::chrono::high_resolution_clock::now();
    GenerateurXorshift genXorshift(100000000, 1, 21, 35, 4);
    genXorshift.generateDvector();
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout<<duration<<std::endl;
}*/

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
