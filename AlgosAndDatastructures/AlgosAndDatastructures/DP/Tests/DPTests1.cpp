#include "catch.hpp"
#include "DPAlgos.h"

TEST_CASE("Game Solution Simple")
{
    auto availableScores = {2, 3, 7};
    SECTION("Tests single score") {
        INFO("Using 12 as Test Score") // Only appears on a FAIL
        auto score = 12;
        auto count = numCombinationsForFinalScore(score, availableScores);
        CAPTURE(count); // Displays this variable on a FAIL
        CHECK(count == 4);

        INFO("Using 9 as Test Score")
        auto score2 = 9;
        auto count2 = numCombinationsForFinalScore(score2, availableScores);
        CAPTURE(count2);
        CHECK(count2 == 3);
    }

    SECTION("Zero Score Tests")
    {
        INFO("Using 0 as Test Score")
        auto score = 0;
        auto count = numCombinationsForFinalScore(score, availableScores);
        CAPTURE(count);
        CHECK(count == 1);
    }
}

TEST_CASE("Standard Combination Sum Test")
{
//    SECTION("Simple Test")
//    {
//        vector<int> scores {1, 2};
//        auto target = 3;
//        auto results = finalScoreCombinations(target, scores);
//        CAPTURE(results);
//        vector<vector<int>> c = {{1,1,1}, {1,2}};
//        REQUIRE(results == c);
//    }

    SECTION("Harder Tests")
    {
        vector<int> scores {10,1,2,7,6,1,5};
        auto target = 8;
        auto results = finalScoreCombinationsNoDups(target, scores);
        CAPTURE(results);
        vector<vector<int>> c = {{2,2,2,2}, {2,3,3}, {3, 5}};
        REQUIRE(results == c);
    }
}

TEST_CASE("Combination Tests 2")
{
    SECTION("Simple Test1")
    {
        auto results = combinations(4, 2);
        vector<vector<int>> c = {{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}};
        REQUIRE(results == c);
    }
    SECTION("Simple Test2")
    {
        auto results = combinations(4, 3);
        vector<vector<int>> c = {{1,2,3}, {1,2,4}, {1,3,4}, {2,3,4}};
        REQUIRE(results == c);
    }

    SECTION("Simple Test3")
    {
        auto results = combinations(2, 1);
        vector<vector<int>> c = {{1}, {2}};
        REQUIRE(results == c);
    }
}

TEST_CASE("Combination Tests 3")
{
    SECTION("Simple Test1")
    {
        auto results = combinations(4, 2);
        vector<vector<int>> c = {{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}};
        REQUIRE(results == c);
    }
    SECTION("Simple Test2")
    {
        auto results = combinations(4, 3);
        vector<vector<int>> c = {{1,2,3}, {1,2,4}, {1,3,4}, {2,3,4}};
        REQUIRE(results == c);
    }

    SECTION("Simple Test3")
    {
        auto results = combinations(2, 1);
        vector<vector<int>> c = {{1}, {2}};
        REQUIRE(results == c);
    }
}

TEST_CASE("Abnormal Combination Sum Tests")
{
    SECTION("No Answer Tests")
    {
        vector<int> scores {5,7};
        auto target = 4;
        auto results = finalScoreCombinations(target, scores);
        CAPTURE(results);
        vector<vector<int>> c = {};
        REQUIRE(results == c);
    }


}


TEST_CASE("Fibonacci Test")
{
    INFO("Checking Fibonacci Algorithm");
    auto f = fibonacci(7);
    CAPTURE(f);
    CHECK(f == 8);

    auto f2 = fibonacci(0);
    CAPTURE(f2);
    CHECK(f2 == 0);

    auto f3 = fibonacci(1);
    CAPTURE(f3);
    CHECK(f3 == 1);

    auto f4 = fibonacci(2);
    CAPTURE(f4);
    CHECK(f4 == 1);
}

TEST_CASE("Modified Fibonacci Test")
{
    SECTION("Basic Tests")
    {
        INFO("Checking Modified Fibonacci Algorithm");
        auto f = fibonacciModified(0, 1, 5);
        CAPTURE(f);
        CHECK(f == 5);
        auto f2 = fibonacciModified(0, 1, 6);
        CAPTURE(f2);
        CHECK(f2 == 27);
    }

}

TEST_CASE("Leveshtein Distance Test")
{
    SECTION("Same String Length")
    {
        INFO("8 Change Check");
        auto s1 = "Carthorse", s2 = "Orchestra";
        auto distance = leveshteinDistance(s1, s2);
        CAPTURE(distance);
        CHECK(distance == 8);
    }

    SECTION("Different String Length")
    {
        INFO("6 Change Check");
        auto s1 = "Cable", s2 = "Caple";
        auto distance = leveshteinDistance(s1, s2);
        CAPTURE(distance);
        CHECK(distance == 1);
    }
}

//TEST_CASE("Modified Leveshtein Distance Test")
//{
//    SECTION("FAIL")
//    {
//        INFO("SHOULD BE LESS THAN 0");
//        CHECK(modifiedLeveshteinDistance("OQSVONTNZMDJAVRZAZCVPKh", "OSVONTNZMDJAVRZAZCVPK") == false);
//        CHECK(modifiedLeveshteinDistance("LDJAN", "LJJM") == false);
//    }
//
//    SECTION("PASS")
//    {
//        INFO("SHOULD BE GREATER THAN 0");
//        CHECK(modifiedLeveshteinDistance("daBcd", "ABC") == true);
//        CHECK(modifiedLeveshteinDistance("beFgH", "EFH") == true);
//    }
//
//    SECTION("SAME")
//    {
//        INFO("SHOULD BE EQUAL TO ZERO");
//        CHECK(modifiedLeveshteinDistance("UMKFW", "UMKFW") == true);
//        CHECK(modifiedLeveshteinDistance("LIT", "LIT") == true);
//    }
//}

TEST_CASE("Max Non Adjacent Sum")
{
    SECTION("Simple Array Test")
    {
        INFO("Positive Number Checks");
        vector<int> arr {3, 7, 4, 6, 5};
        CHECK(maxAdjacentSum(arr) == 13);
    }
}



//
// Created by Mark Barbaric on 16/10/2019.
//

