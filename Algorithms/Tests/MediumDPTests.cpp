#include "../../catch.hpp"
#include "../DynamicProgramming/NumCombinations.h"
#include "../DynamicProgramming/Knapsack.h"
#include "../DynamicProgramming/PalindromeDP.h"

TEST_CASE("Score Combination Tests")
{
	SECTION("Num Combination Tests")
	{
		REQUIRE(CombinationDP::numCombinationsTabulated(4, { 1,2,3 }) == 7);
		REQUIRE(CombinationDP::numCombinationsMemoization(4, { 1,2,3 }) == 7);
		REQUIRE(CombinationDP::numUniqueCombinationsTabulated(4, { 1,2,3 }) == 4);

		
		const std::vector<std::vector<int>> ans1 = { {1,1,1}, {1,2}, {3} };
		REQUIRE(CombinationDP::numCombinationsOutcomes(3, { 1, 2, 3 }) == ans1);
	}

}

TEST_CASE("Knapsack Tests")
{
	SECTION("Maximum Value Tests")
	{
		std::vector<knapsack::Item> items = { {6, 5}, {5, 3}, {7, 4}, {3, 2} };
		const auto maxWeight = 5;
		REQUIRE(knapsack::maximumValue(maxWeight, items) == 8);
	}
}

TEST_CASE("Palindrome Tests")
{
	SECTION("IsPalindrome Tests")
	{
		std::string p1 = "babab";
		REQUIRE(PalindromeDP::IsPalindrome(p1) == true);
		std::string p2 = "babad";
		REQUIRE(PalindromeDP::IsPalindrome(p2) == false);
		std::string p3 = "ba";
		REQUIRE(PalindromeDP::IsPalindrome(p3) == false);
		std::string p4 = "bb";
		REQUIRE(PalindromeDP::IsPalindrome(p4) == true);
	}
	
	SECTION("Longest Palindrome Test")
	{
		std::string w1 = "bb";
		REQUIRE(PalindromeDP::LongestPalindromeBF(w1) == 2);
		REQUIRE(PalindromeDP::LongestPalindromeDP(w1) == 2);
		std::string w2 = "ac";
		REQUIRE(PalindromeDP::LongestPalindromeBF(w2) == 1);
		REQUIRE(PalindromeDP::LongestPalindromeDP(w2) == 1);
		std::string word = "babad";
		REQUIRE(PalindromeDP::LongestPalindromeBF(word) == 3);
		REQUIRE(PalindromeDP::LongestPalindromeDP(word) == 3);
		std::string word2 = "sdabad";
		REQUIRE(PalindromeDP::LongestPalindromeBF(word2) == 5);
		REQUIRE(PalindromeDP::LongestPalindromeDP(word2) == 5);
		std::string word3 = "aaaaa";
		REQUIRE(PalindromeDP::LongestPalindromeBF(word3) == 5);
		REQUIRE(PalindromeDP::LongestPalindromeDP(word3) == 5);
		std::string word4 = "aaa";
		REQUIRE(PalindromeDP::LongestPalindromeBF(word4) == 3);
		REQUIRE(PalindromeDP::LongestPalindromeDP(word4) == 3);
	}
}
