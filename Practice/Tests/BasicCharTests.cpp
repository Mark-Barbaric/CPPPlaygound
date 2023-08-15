#include <gtest/gtest.h>
#include "basic_char.h"

TEST(BasicCharTests, AccessorTests)
{
    BasicChar<int> basicChar (4);
    EXPECT_EQ(basicChar.size(), 4);
    basicChar[0] = 22;
    EXPECT_EQ(basicChar[0], 22);
}

TEST(BasicCharTests, PlusEqualTests)
{
    BasicChar<int> basicChar (4);
    for(int i = 0; i < 4; ++i){
        basicChar[i] = i;
    }

    BasicChar<int> basicChar2(2);

    for(int i = 0; i < 2; ++i){
        basicChar[i] = i + (2 * i);
    }

    basicChar += basicChar2;
    EXPECT_EQ(basicChar.size(), 6);
}