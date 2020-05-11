#include "gtest/gtest.h"
#include "DistributionNormale.h"

#include <fstream>

class DistributionNormaleTest: public ::testing::Test{
    protected:
        virtual void SetUp(){
        }

        virtual void TearDown(){
        }
};

TEST_F(DistributionNormaleTest, constructorDefault){
    DistributionNormale norm(1000000, 5, 5);
    EXPECT_NEAR(norm.mean(),5,0.01);
    EXPECT_NEAR(norm.var(),5,0.01);
}

TEST_F(DistributionNormaleTest, normalcdf){
    DistributionNormale norm(10);
    EXPECT_NEAR(norm.cdf(-1), 0.15865, 0.0001);
    EXPECT_NEAR(norm.cdf(0), 0.5, 0.0001);
    EXPECT_NEAR(norm.cdf(3), 0.99865, 0.0001);
}


TEST_F(DistributionNormaleTest, normalInv_cdf){
    DistributionNormale norm(10);
    EXPECT_NEAR(norm.inv_cdf(0.15865), -1, 0.0001);
    EXPECT_NEAR(norm.inv_cdf(0.5), 0, 0.0001);
    EXPECT_NEAR(norm.inv_cdf(0.99865), 3, 0.00045);
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
