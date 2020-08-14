#include "../../catch.hpp"
#include "../GeneralAlgorithms/MediumArrayAlgorithms.h"

TEST_CASE("Subarray Algorithms")
{
    SECTION("Minimum Size Subarray Sum")
    {
        std::vector<int> v {2,3,1,2,4,3};
        REQUIRE(MediumArrayAlgorithms::MinimumSizeContiguousSubarraySum(v, 7) == 2);
        std::vector<int> v1 {1,1,1};
        REQUIRE(MediumArrayAlgorithms::MinimumSizeContiguousSubarraySum(v1, 2) == 2);
        std::vector<int> v2 {1,2,3,1};
        REQUIRE(MediumArrayAlgorithms::MinimumSizeContiguousSubarraySum(v2, 3) == 1);
    }

    SECTION("Subarray Sum Equals K")
    {
        std::vector<int> v1{ 1,1,1 };
        REQUIRE(MediumArrayAlgorithms::SubarraySumEqualsK(v1, 2, v1.size()) == 2);
        std::vector<int> v2{ 1,2,3,1 };
        REQUIRE(MediumArrayAlgorithms::SubarraySumEqualsK(v2, 3, v2.size()) == 2);
    }

	SECTION("Kadane Max Subarray Sum")
    {
        std::vector<int> v1{ -2,1,-3,4,-1,2,1,-5,4 };
        REQUIRE(MediumArrayAlgorithms::KadaneMaxSubArray(v1) == 6);
    }
}

TEST_CASE("Subarray Product Algorithms")
{
    SECTION("Max Product")
    {
        std::vector<int> v1{ 2, 3, -2, 4 };
        REQUIRE(MediumArrayAlgorithms::MaxProduct(v1) == 6);
        std::vector<int> v2{ -2, 0, -1 };
        REQUIRE(MediumArrayAlgorithms::MaxProduct(v2) == 0);
    }

	SECTION("Max Product Except Self")
    {
        std::vector<int> v1{ 1, 2, 3, 4 };
        std::vector<int> ans{ 24, 12, 8, 6 };
        REQUIRE(MediumArrayAlgorithms::ProductExceptSelf(v1) == ans);
    }
}


