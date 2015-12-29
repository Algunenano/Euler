#include <gtest/gtest.h>
#include "Euler4.h"

class Euler4Spec : public testing::Test
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

TEST_F(Euler4Spec, isPalindrome99)
{
    EXPECT_EQ(isPalindrome(99), true);
}

TEST_F(Euler4Spec, isPalindrome100)
{
    EXPECT_EQ(isPalindrome(100), false);
}

TEST_F(Euler4Spec, isPalindrome1001)
{
    EXPECT_EQ(isPalindrome(1001), true);
}

TEST_F(Euler4Spec, isPalindrome9009)
{
    EXPECT_EQ(isPalindrome(9009), true);
}

TEST_F(Euler4Spec, isPalindrome4554)
{
    EXPECT_EQ(isPalindrome(4554), true);
}

TEST_F(Euler4Spec, isPalindrome12345)
{
    EXPECT_EQ(isPalindrome(12345), false);
}

TEST_F(Euler4Spec, digits2)
{
    EXPECT_EQ(largestPalindromeProduct(2), 9009);
}

TEST_F(Euler4Spec, digits3)
{
    EXPECT_EQ(largestPalindromeProduct(3), 906609);
}

TEST_F(Euler4Spec, digits4)
{
    EXPECT_EQ(largestPalindromeProduct(4), 99000099);
}

TEST_F(Euler4Spec, digits5)
{
    EXPECT_EQ(largestPalindromeProduct(5), 9966006699);
}