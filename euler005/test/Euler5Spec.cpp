#include <gtest/gtest.h>
#include "Euler5.h"

class Euler5Spec : public testing::Test
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

TEST_F(Euler5Spec, smallest3)
{
    EXPECT_EQ(smallestMultiple(3), 6);
}

TEST_F(Euler5Spec, smallest4)
{
    EXPECT_EQ(smallestMultiple(4), 12);
}

TEST_F(Euler5Spec, smallest10)
{
    EXPECT_EQ(smallestMultiple(10), 2520);
}

TEST_F(Euler5Spec, smallest20)
{
    EXPECT_EQ(smallestMultiple(20), 232792560);
}
