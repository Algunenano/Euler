#include <gtest/gtest.h>
#include "Euler9.h"

class Euler9Spec : public testing::Test
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

TEST_F(Euler9Spec, triplet12)
{
    EXPECT_EQ(pytagTripletProduct(12), 60);
}

TEST_F(Euler9Spec, triplet1000)
{
    EXPECT_EQ(pytagTripletProduct(1000), 31875000);
}
