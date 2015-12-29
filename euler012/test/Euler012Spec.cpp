#include <gtest/gtest.h>
#include "Euler012.h"

class Euler012Spec : public testing::Test
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

TEST_F(Euler012Spec, tri5)
{
    EXPECT_EQ(triangleDivisors(5), 28);
}


TEST_F(Euler012Spec, tri500)
{
    EXPECT_EQ(triangleDivisors(500), 76576500);
}
