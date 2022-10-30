#include "include/catch.hpp"
#include "../String/StringAlgorithms.h"

TEST_CASE("Medium Strings Algorithm Datastructures")
{
	const std::string word1 = "anagram", word2 = "nagaram";

	SECTION("Easy Algorthms")
	{
		REQUIRE(StringAlgorithms::IsAnagram(word1, word2) == true);
	}

	SECTION("Hard Algorithms")
	{
		REQUIRE(StringAlgorithms::FirstUniqueChar("leetcode") == 0);
		REQUIRE(StringAlgorithms::FirstUniqueChar("loveleetcode") == 2);
		REQUIRE(StringAlgorithms::FirstUniqueChar("llee") == -1);
	}
	
}