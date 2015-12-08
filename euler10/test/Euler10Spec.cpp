#include <gtest/gtest.h>
#include "Euler10.h"
#include <iostream>

class Euler10Spec : public testing::Test
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

TEST_F(Euler10Spec, test1000)
{
    EXPECT_EQ(sumPrime(1000), 76127);
}

TEST_F(Euler10Spec, test2M)
{
    EXPECT_EQ(sumPrime(2000000), 142913828922);
}