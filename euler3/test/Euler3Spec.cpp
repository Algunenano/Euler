#include <gtest/gtest.h>
#include "Euler3.h"

class Euler3Spec : public testing::Test
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

TEST_F(Euler3Spec, check2)
{
    EXPECT_EQ(largestPrimeFactor(2), 2);
}

TEST_F(Euler3Spec, check13)
{
    EXPECT_EQ(largestPrimeFactor(13), 13);
}

TEST_F(Euler3Spec, check39)
{
    EXPECT_EQ(largestPrimeFactor(39), 13);
}

TEST_F(Euler3Spec, check100)
{
    EXPECT_EQ(largestPrimeFactor(100), 5);
}

TEST_F(Euler3Spec, check221)
{
    EXPECT_EQ(largestPrimeFactor(221), 17);
}


TEST_F(Euler3Spec, check600851475143)
{
    EXPECT_EQ(largestPrimeFactor(600851475143), 6857);
}




