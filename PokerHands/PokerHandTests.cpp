#include <gtest/gtest.h>
#include "poker_hand.h"

namespace PokerHands {


    TEST(PokerHandsTests, BasicFunctionalityTests)
    {
        PokerHand hand1 {"AC 2C 3C 4C 10C"};
        EXPECT_EQ(hand1.getHand(), "AC 2C 3C 4C 10C");
    }


    TEST(PokerHandsTest, PokerHandPreprocessingTests)
    {
        ASSERT_FALSE(PokerHand::IsPokerCardValid("101D"));
        ASSERT_FALSE(PokerHand::IsPokerCardValid("TD"));
        ASSERT_TRUE(PokerHand::IsPokerCardValid("AC"));
        ASSERT_FALSE(PokerHand::IsPokerCardValid("QE"));
        ASSERT_TRUE(PokerHand::IsPokerCardValid("10D"));

        PokerHand hand1 {"AC 2C 3C 4C TC"};
        ASSERT_THROW(hand1.AnalyzeHand(), std::logic_error);

        PokerHand hand2 {"AC 2C 3C 4C 101DC"};
        ASSERT_THROW(hand1.AnalyzeHand(), std::logic_error);
    }

}
