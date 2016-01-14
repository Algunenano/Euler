#include <gtest/gtest.h>
#include "Euler015.h"

class Euler015Spec : public testing::Test
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

TEST_F(Euler015Spec, lat2)
{
    EXPECT_EQ(latticePaths(2), 6);
}

TEST_F(Euler015Spec, lat20)
{
    EXPECT_EQ(latticePaths(20), 137846528820);
}