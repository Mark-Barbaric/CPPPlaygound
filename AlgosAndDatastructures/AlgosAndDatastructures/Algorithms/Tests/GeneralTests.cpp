#include "../../catch.hpp"
#include "../GeneralAlgorithms.h"

TEST_CASE("General Algorithm Tests")
{
    GeneralAlgorithms generalAlgorithms;

    SECTION("Simple Tests")
    {
        std::vector<int> v {1,2,3,4};
        std::vector<int> result = {24, 12, 8, 6};
        REQUIRE(generalAlgorithms.productExceptSelf(v, v.size()) == result);
    }

}

