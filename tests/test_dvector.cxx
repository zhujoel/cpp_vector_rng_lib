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

TEST_F(DvectorTest, constructorValue){
    Dvector v(3, 2.2);
    EXPECT_EQ(2.2, v(2));
}

TEST_F(DvectorTest, constructorCopieDim){
    Dvector v(2);
    Dvector v2(v);
    EXPECT_EQ(2, v2.size());
}

TEST_F(DvectorTest, constructorAddAValue){
    Dvector v(2, 1);
    Dvector v1(v, 3);
    EXPECT_EQ(3, v1.size());
    EXPECT_EQ(1, v1(1));
    EXPECT_EQ(3, v1(2));
}


TEST_F(DvectorTest, display){
    Dvector v(2, 2.5);
    std::stringstream str;
    v.display(str);
    EXPECT_EQ("2.5\n2.5\n", str.str());
}
/** This test failed
TEST_F(DvectorTest, constructorFile){
    Dvector v("../tests_provided/test1.txt");
    EXPECT_EQ(10, v.size());
}
*/
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
    Dvector v(3, 4.5);
    v += 5.0;
    EXPECT_EQ(9.5, v(0));
    v += 3;
    EXPECT_EQ(12.5, v(0));
    v += -3;
    EXPECT_EQ(9.5, v(0));
}

TEST_F(DvectorTest, operator_plusequals_vector){
    Dvector v(3, 3.125);
    Dvector v2(3, 1.125);
    v += v2;
    EXPECT_EQ(v(1), 4.250);
    v2 -= v;
    EXPECT_EQ(v2(1), -3.125);
}

TEST_F(DvectorTest, operator_plus_reel){
    Dvector v(3, 3.0);
    EXPECT_EQ((v+5+3+2)(1), 13);
}

TEST_F(DvectorTest, operator_mult_reel){
    Dvector v(3, 3.0);
    EXPECT_EQ((v*5*3*2)(1), 90);
}

TEST_F(DvectorTest, operator_plus_externe_reel){
    Dvector v(3, 3.0);
    EXPECT_EQ((5+3+v+2)(1), 13);
}

TEST_F(DvectorTest, operator_minus_externe_reel){
    Dvector v(3, 3.0);
    EXPECT_EQ((5-v)(1), 2);
    EXPECT_EQ((5-v)(2), 2);
}


TEST_F(DvectorTest, operator_plus_vector){
    Dvector v(3, 2.0);
    Dvector v2(3, 1.0);
    EXPECT_EQ((v+v2+v+v)(1), 7);
}

TEST_F(DvectorTest, operator_differents_reel){
    Dvector v(3, 3.0);
    EXPECT_EQ((v*5+3-v/1+v*2)(1), 21);
}

TEST_F(DvectorTest, operator_unaryminus){
    Dvector v(5, -0.25);
    Dvector v2(-v);
    EXPECT_EQ(0.25, v2(4));
}

TEST_F(DvectorTest, operator_bool_equals){
    Dvector v(5, 3);
    Dvector v1(5, 3);
    EXPECT_EQ(true, v==v1);
}
TEST_F(DvectorTest, operator_bool_not_equals){
    Dvector v(5, 3);
    Dvector v1(5, 0.5);
    Dvector v2(2, 3);
    EXPECT_EQ(true, v!=v1);
    EXPECT_EQ(true, v!=v2);
}

TEST_F(DvectorTest, method_resize_smaller){
    Dvector v(5, 3.25);
    v.resize(2);
    EXPECT_EQ(2, v.size());
    v.resize(8);
    EXPECT_EQ(v(6), 0);
    v.resize(10, 3.3);
    EXPECT_EQ(v(9), 3.3);
    EXPECT_NE(v(7), 3.3);
}

TEST_F(DvectorTest, output_operator_display){
    Dvector v(2, 4.25);
    Dvector v1(2, 4);
    std::stringstream str;
    str<<v<<v1;
    EXPECT_EQ("4.25\n4.25\n4\n4\n", str.str());
}

TEST_F(DvectorTest, output_operator_addAValue){
    Dvector v(2, 4.25);
    v << 3 << 2 << 5 << 6;
    EXPECT_EQ(6, v(5));
}

TEST_F(DvectorTest, input_operator){
    Dvector v(3);
    std::stringstream str;
    str<<"4.25\n4.25\n5\n";
    str>>v;
    EXPECT_EQ(4.25, v(1));
    EXPECT_EQ(5, v(2));
}

TEST_F(DvectorTest, both_operator){
    Dvector v(3, 2.5);
    Dvector v2(3);
    std::stringstream str;
    str<<v;
    str>>v2;
    EXPECT_EQ(2.5, v2(1));
    EXPECT_EQ(2.5, v2(2));
}

// TODO: fix le memory leak avec valgrind dû à ce test
TEST_F(DvectorTest, operator_affectation_deepCopy){
    Dvector v(3, 2.5);
    Dvector v2(2, 4.25);
    Dvector v3(99, 1.25);
    v3 = v2 = v;
    EXPECT_EQ(2.5, v2(0));
    EXPECT_EQ(2.5, v3(0));
}

/*
TEST_F(DvectorTest, operator_affect_shared){
    Dvector v(3, 2.5);
    v = Dvector(99, 55);
    EXPECT_EQ(55, v(0));
}
*/
int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}