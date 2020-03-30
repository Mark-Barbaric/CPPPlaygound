#include "../../../../Catch2/single_include/catch2/catch.hpp"
#include "../ArrayAlgorithms/SimpleArrayAlgorithms.h"

TEST_CASE("Simple Algorithm Tests")
{
    SimpleArrayAlgorithms<int, std::vector<int>> arrayAlgorithms;
    SECTION("Normal Array")
    {
        std::vector<int> v1 {1, 8, 2, 9, 6, 4};
        auto result = arrayAlgorithms.maxFromArray(v1, v1.size());
        CHECK(result == 9);
    }

    SECTION("Array with Negative Numbers")
    {
        std::vector<int> v1 {1, -8, 2, 9, -6, 4, 1, 4};
        auto result = arrayAlgorithms.maxFromArray(v1, v1.size());
        CHECK(result == 9);
    }

    SECTION("Zero Size Array")
    {
        std::vector<int> v1 {};
        auto result = arrayAlgorithms.maxFromArray(v1, v1.size());
        CHECK(result == -1);
    }
}

TEST_CASE("Kadane Max Subarry Tests")
{
    SimpleArrayAlgorithms<int, std::vector<int>> arrayAlgorithms;

    SECTION("Basic Tests")
    {
        std::vector<int> v {-2,1,-3,4,-1,2,1,-5,4};
        CHECK(arrayAlgorithms.maxSubArrayKadane(v, v.size()) == 6);
    }

    SECTION("Single Number Array Tests")
    {
        std::vector<int> v {1};
        CHECK(arrayAlgorithms.maxSubArrayKadane(v, v.size()) == 1);
    }

    SECTION("Empty Array Tests")
    {
        std::vector<int> v{};
        CHECK(arrayAlgorithms.maxSubArrayKadane(v, v.size()) == -1);
    }
}