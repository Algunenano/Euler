#include <gtest/gtest.h>
#include "Euler6.h"

class Euler6Spec : public testing::Test
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

TEST_F(Euler6Spec, diff10)
{
    EXPECT_EQ(sumSquareDiff(10), 2640);
}

TEST_F(Euler6Spec, diff5)
{
    EXPECT_EQ(sumSquareDiff(5), 170);
}

TEST_F(Euler6Spec, diff100)
{
    EXPECT_EQ(sumSquareDiff(100), 25164150);
}