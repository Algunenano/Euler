#include <gtest/gtest.h>
#include "Euler014.h"

class Euler014Spec : public testing::Test
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

TEST_F(Euler014Spec, longestChain2)
{
    EXPECT_EQ(longestChain(2), 2);
}

TEST_F(Euler014Spec, longestChain1000000)
{
    EXPECT_EQ(longestChain(1000000), 837799);
}

TEST_F(Euler014Spec, longestChain10000000)
{
    EXPECT_EQ(longestChain(10000000), 8400511);
}
