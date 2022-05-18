#include <gtest/gtest.h>
#include "ReverseWordsInAString.h"

namespace Algorithms::StringAlgorithms{
    TEST(StringAlgorithms, ReverseWordsInAString){
        std::string s = "abc def ghi jkl";

        ASSERT_EQ(reverseWordsTraverse(s), "cba fed ihg lkh");
        ASSERT_EQ(reverseWordsStringStream(s), "cba fed ihg lkh");

    }
}