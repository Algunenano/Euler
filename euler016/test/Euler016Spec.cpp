#include <gtest/gtest.h>
#include "Euler016.h"

class Euler016Spec : public testing::Test
{
protected:

    void SetUp()
    {
        
    }

    void TearDown()
    {
        // Teardown ...
    }

};

TEST_F(Euler016Spec, pow15)
{
    EXPECT_EQ(powerDigitSum(15), 26);
}

TEST_F(Euler016Spec, pow1000)
{
    EXPECT_EQ(powerDigitSum(1000), 1366);
}

TEST_F(Euler016Spec, pow1000000)
{
    EXPECT_EQ(powerDigitSum(1000000), 1351546);
}