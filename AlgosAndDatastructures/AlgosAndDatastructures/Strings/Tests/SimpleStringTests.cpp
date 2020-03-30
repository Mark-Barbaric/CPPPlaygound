#include "../../../Catch2/single_include/catch2/catch.hpp"
#include "../SimpleStringAlgorithms.h"

TEST_CASE("Parenthesis Checks")
{
    SimpleStringAlgorithms simpleStringAlgorithms;

    SECTION("Basic Tests")
    {
        std::string s1 = "{[()]}";
        CHECK(simpleStringAlgorithms.isValidParenthesis(s1));

        std::string s2 = "[](}";
        CHECK(!simpleStringAlgorithms.isValidParenthesis(s2));

        std::string s3 = "(]";
        CHECK(!simpleStringAlgorithms.isValidParenthesis(s3));

    }
}

//
// Created by Mark Barbaric on 28/10/2019.
//

