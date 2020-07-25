#include "../../catch.hpp"
#include "../GreedyAlgorithms/MediumGreedyAlgorithms.h"
#include "../GreedyAlgorithms/SimpleGreedyAlgorithms.h"

TEST_CASE("Change Problem")
{
    SimpleGreedyAlgorithms<int, std::vector<int>> simpleGreedyAlgorithms;
    SECTION("Brute Force Tests")
    {
        std::vector<int> change {100, 50, 25, 10, 5, 1};
        REQUIRE(simpleGreedyAlgorithms.getChangeBruteForce(250, change, change.size()) == 3);
    }

    SECTION("Optimised Algorithm Tests")
    {
        std::vector<int> change {100, 50, 25, 10, 5, 1};
        REQUIRE(simpleGreedyAlgorithms.getChangeOptimised(250, change, change.size()) == 3);
    }
}

TEST_CASE("Max Substring")
{
    SimpleGreedyAlgorithms<int, std::vector<int>> simpleGreedyAlgorithms;

    SECTION("Simple Tests")
    {
        REQUIRE(simpleGreedyAlgorithms.optimisedMaximumSubstring("abcabcbb") == 3);
        REQUIRE(simpleGreedyAlgorithms.optimisedMaximumSubstring("bbbbb") == 1);
        REQUIRE(simpleGreedyAlgorithms.optimisedMaximumSubstring("pwwkew") == 3);
    }
}

TEST_CASE("Max Palindromic Substring")
{
    SimpleGreedyAlgorithms<std::string, std::string> simpleGreedyAlgorithms;

    SECTION("Simple Tests")
    {
        REQUIRE(simpleGreedyAlgorithms.longestPalindromicSubstring("babad") == "bab");
        REQUIRE(simpleGreedyAlgorithms.longestPalindromicSubstring("cbbd") == "bb");
        REQUIRE(simpleGreedyAlgorithms.longestPalindromicSubstring("xabax") == "xabax");
    }
}

TEST_CASE("Medium Greedy Algorithms")
{

  SECTION("Container of Water Tests")
  {
      std::vector<int> v {4,1,1,7};
      REQUIRE(MediumGreedyAlgorithms::maximumWaterUnderVerticalLines(v) == 12);
      std::vector<int> v2 {1,8,6,2,5,4,8,3,7};
      REQUIRE(MediumGreedyAlgorithms::maximumWaterUnderVerticalLines(v2) == 49);
  }
  
  SECTION("Two Sum Tests")
  {
    std::vector<int> vec {2, 7, 11, 15};
    std::vector<int> ans = {2, 7};
    REQUIRE(MediumGreedyAlgorithms::twoSum(vec, 9) == ans);
    REQUIRE(MediumGreedyAlgorithms::twoSumTwo(vec, 9) == ans);
  }
  
  SECTION("Three Sum Tests")
  {
    std::vector<int> v {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> ans = {{ -1, -1, 2 }, { -1, 1, 0}};
    REQUIRE(MediumGreedyAlgorithms::threeSum(v) == ans);
    std::vector<int> v2 {0, 0, 0, 0};
    std::vector<std::vector<int>> ans2 = {{0, 0, 0}};
    REQUIRE(MediumGreedyAlgorithms::threeSum(v2) == ans2);
  }

}
