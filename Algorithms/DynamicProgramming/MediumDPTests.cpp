#include <gtest/gtest.h>
#include "NumCombinations.h"
#include "PalindromeDP.h"

TEST(MediumDPTests, NumCombinationTests)
{
    EXPECT_EQ(MediumDP::numCombinationsTabulated(4, { 1,2,3 }), 7);
    EXPECT_EQ(MediumDP::numCombinationsMemoization(4, { 1,2,3 }), 7);
    EXPECT_EQ(MediumDP::numUniqueCombinationsTabulated(4, { 1,2,3 }), 4);

    const std::vector<std::vector<int>> ans1 = { {1,1,1}, {1,2}, {3} };
    EXPECT_EQ(MediumDP::numCombinationsOutcomes(3, { 1, 2, 3 }), ans1);
}

TEST(MediumDPTests, PalindomeTests)
{
    std::string p1 = "babab";
    EXPECT_EQ(PalindromeDP::IsPalindrome(p1), true);
    std::string p2 = "babad";
    EXPECT_EQ(PalindromeDP::IsPalindrome(p2), false);
    std::string p3 = "ba";
    EXPECT_EQ(PalindromeDP::IsPalindrome(p3), false);
    std::string p4 = "bb";
    EXPECT_EQ(PalindromeDP::IsPalindrome(p4), true);


    std::string w1 = "bb";
    EXPECT_EQ(PalindromeDP::LongestPalindromeBF(w1), 2);
    EXPECT_EQ(PalindromeDP::LongestPalindromeDP(w1), 2);
    std::string w2 = "ac";
    EXPECT_EQ(PalindromeDP::LongestPalindromeBF(w2), 1);
    EXPECT_EQ(PalindromeDP::LongestPalindromeDP(w2), 1);
    std::string word = "babad";
    EXPECT_EQ(PalindromeDP::LongestPalindromeBF(word), 3);
    EXPECT_EQ(PalindromeDP::LongestPalindromeDP(word), 3);
    std::string word2 = "sdabad";
    EXPECT_EQ(PalindromeDP::LongestPalindromeBF(word2), 5);
    EXPECT_EQ(PalindromeDP::LongestPalindromeDP(word2), 5);
    std::string word3 = "aaaaa";
    EXPECT_EQ(PalindromeDP::LongestPalindromeBF(word3), 5);
    EXPECT_EQ(PalindromeDP::LongestPalindromeDP(word3), 5);
    std::string word4 = "aaa";
    EXPECT_EQ(PalindromeDP::LongestPalindromeBF(word4), 3);
    EXPECT_EQ(PalindromeDP::LongestPalindromeDP(word4), 3);
}
