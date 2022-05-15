#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include "Algorithms/String/MultiplyStrings.h"

TEST_CASE("Multiple Strings Test"){
    REQUIRE("0" == StringAlgorithms::multiplyStrings("0", "0"));
    REQUIRE("147" == StringAlgorithms::multiplyStrings("1", "147"));
    REQUIRE("1442" == StringAlgorithms::multiplyStrings("2", "721"));
    REQUIRE("32445" == StringAlgorithms::multiplyStrings("45", "721"));
    REQUIRE("100940"== StringAlgorithms::multiplyStrings("140", "721"));
    REQUIRE("98901"== StringAlgorithms::multiplyStrings("99", "999"));
    REQUIRE("103896"== StringAlgorithms::multiplyStrings("104", "999"));
    REQUIRE("103896"== StringAlgorithms::multiplyStrings("1000200", "90090090"));
}