#include "BigInt.h"
#include <gtest/gtest.h>

TEST(BigIntTests, BasicFunctionalityTests)
{
    const std::string num1 = "1239081023";
    BigInt bigInt1(num1);
    EXPECT_EQ(bigInt1.to_string(), num1);
    EXPECT_EQ(bigInt1.size(), 10);
    const std::string num2 = "1";
    BigInt bigInt2(num2);
    EXPECT_EQ(bigInt2.to_string(), num2);
    EXPECT_EQ(bigInt2.size(), 1);
    BigInt bigInt3("1345");
    EXPECT_EQ(bigInt3.to_string(), "1345");
    EXPECT_EQ(bigInt3.size(), 4);

}

TEST(BigIntTests, AdditionTests)
{
    BigInt bigInt1("1001");
    BigInt bigInt2("1");
    const auto ans1 = bigInt1 + bigInt2;
    EXPECT_EQ(ans1.size(), 4);
    EXPECT_EQ(ans1.to_string(), "1002");
    BigInt bigInt3("99");
    const auto ans2 = bigInt2 + bigInt3;
    EXPECT_EQ(ans2.size(), 3);
    EXPECT_EQ(ans2.to_string(), "100");
    BigInt bigInt4("999");
    BigInt bigInt5("999");
    const auto ans3 = bigInt4 + bigInt5;
    EXPECT_EQ(ans3.size(), 4);
    EXPECT_EQ(ans3.to_string(), "1998");
}