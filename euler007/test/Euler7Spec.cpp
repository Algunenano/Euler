#include <gtest/gtest.h>
#include "Euler7.h"

class Euler7Spec : public testing::Test
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

TEST_F(Euler7Spec, prime4)
{
    EXPECT_EQ(primeN(4), 7);
}

TEST_F(Euler7Spec, prime6)
{
    EXPECT_EQ(primeN(6), 13);
}

TEST_F(Euler7Spec, prime10001)
{
    EXPECT_EQ(primeN(10001), 104743);
}


