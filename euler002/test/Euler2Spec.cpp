#include <gtest/gtest.h>
#include "Euler2.h"

class Euler2Spec : public testing::Test
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

TEST_F(Euler2Spec, upto100)
{
    EXPECT_EQ(fibEvenSum(100), 44);
}

TEST_F(Euler2Spec, upto4000000)
{
    EXPECT_EQ(fibEvenSum(4000000), 4613732);
}