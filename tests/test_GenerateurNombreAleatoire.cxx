#include "gtest/gtest.h"
#include "GenerateurNombreAleatoire.h"
#include <fstream>

class GenerateurNombreAleatoireTest: public ::testing::Test{
    protected:
        virtual void SetUp(){
        }

        virtual void TearDown(){
        }
};

TEST_F(GenerateurNombreAleatoireTest, constructorDefault){
    EXPECT_EQ(0, 0);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
