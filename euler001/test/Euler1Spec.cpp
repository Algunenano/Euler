#include <gtest/gtest.h>
#include "Euler1.h"

class Euler1Spec : public testing::Test
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

TEST_F(Euler1Spec, Upto10)
{
    EXPECT_EQ(sumMultiples35(10), 23);
}

TEST_F(Euler1Spec, Upto1000)
{
    EXPECT_EQ(sumMultiples35(1000), 233168);
}
