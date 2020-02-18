#include "gtest/gtest.h"
#include "Dvector.h"
#include <fstream>

class DvectorTest: public ::testing::Test{
    protected:
        virtual void SetUp(){
        }

        virtual void TearDown(){
        }
};

TEST_F(DvectorTest, constructorDefault){
    Dvector v;
    EXPECT_EQ(0, v.size());
}


TEST_F(DvectorTest, constructorDim){
    Dvector v(4);
    EXPECT_EQ(4, v.size());
}

// TODO: Tester constructeur avec une valeur
TEST_F(DvectorTest, constructorValue){
    Dvector v(3, 2.2);
    EXPECT_EQ(2.2, v(2));
}

TEST_F(DvectorTest, constructorCopieDim){
    Dvector v(2);
    Dvector v2(v);
    EXPECT_EQ(2, v2.size());
}

TEST_F(DvectorTest, display){
    Dvector v(2, 2.5);
    std::stringstream str;
    v.display(str);
    EXPECT_EQ("2.5\n2.5\n", str.str());
}

TEST_F(DvectorTest, constructorFile){
    Dvector v("../tests_provided/test1.txt");
    EXPECT_EQ(10, v.size());
}

TEST_F(DvectorTest, constructorFileDisplay){
    Dvector v(5, 45.23654789);
    std::ofstream output("display_output.txt");
    v.display(output);
    Dvector v2("display_output.txt");
    output.close();
    EXPECT_EQ(5, v2.size());
    EXPECT_EQ(45.23654789, v2(2));
}

TEST_F(DvectorTest, operator_parenthesis_read){
    Dvector v(3, 3.3);
    EXPECT_EQ(3.3, v(2));
}

TEST_F(DvectorTest, operator_parenthesis_write){
    Dvector v(3, 3.305);
    v(1) = 503.43;
    EXPECT_EQ(503.43, v(1));
}

TEST_F(DvectorTest, operator_plusequals_double){
    Dvector v(3, 5.123);
    v += 5.0;
    EXPECT_EQ(10, v(0));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}