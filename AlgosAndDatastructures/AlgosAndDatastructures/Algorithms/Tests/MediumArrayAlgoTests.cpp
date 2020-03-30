#include "../../catch.hpp"
#include "../ArrayAlgorithms/MediumArrayAlgorithms.h"

TEST_CASE("Minimum Contiguous Sum Tests")
{
    MediumArrayAlgorithms<int, std::vector<int>> mediumArrayAlgorithms;

    SECTION("Basic Tests")
    {
        std::vector<int> v {2,3,1,2,4,3};
        REQUIRE(mediumArrayAlgorithms.minimumSizeContiguousSubarraySum(v, 7, v.size()) == 2);
        std::vector<int> v1 {1,1,1};
        REQUIRE(mediumArrayAlgorithms.minimumSizeContiguousSubarraySum(v1, 2, v1.size()) == 2);
        std::vector<int> v2 {1,2,3,1};
        REQUIRE(mediumArrayAlgorithms.minimumSizeContiguousSubarraySum(v2, 3, v2.size()) == 1);
    }

    SECTION("Empty Array Tests")
    {
        std::vector<int> v {};
        REQUIRE(mediumArrayAlgorithms.minimumSizeContiguousSubarraySum(v, 7, v.size()) == 0);
    }
}

TEST_CASE("Contiguous Subarray Sum Equals K")
{
    MediumArrayAlgorithms<int, std::vector<int>> mediumArrayAlgorithms;

    SECTION("Basic Tests")
    {
        std::vector<int> v1 {1,1,1};
        REQUIRE(mediumArrayAlgorithms.subarraySumEqualsK(v1, 2, v1.size()) == 2);
        std::vector<int> v2 {1,2,3,1};
        REQUIRE(mediumArrayAlgorithms.subarraySumEqualsK(v2, 3, v2.size()) == 2);
    }
}