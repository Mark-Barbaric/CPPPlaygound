#include <gtest/gtest.h>
#include "PokerHandAnalyzer.h"
#include "OptimizedPokerHandAnalyzer.h"

namespace PokerHands{

    TEST(PokerHandAnalyzerTests, StraightAndRoyalFlushTests){

        std::cout << "Straight Flush Tests Succeeded.\n\n\n";
        PokerHandAnalyzer straightFlush {"9H TH JH QH KH"};
        OptimizedPokerHandAnalyzer straightFlush2 {"9H TH JH QH KH"};
        EXPECT_EQ(straightFlush.getHandRank(), HandRank::StraightFlush);
        EXPECT_EQ(straightFlush2.getHandRank(), HandRank::StraightFlush);
        std::cout << "Straight Flush Card Rank Test Succeeded.\n";

        OptimizedPokerHandAnalyzer aceToFiveStraightFlush2 {"AD 2D 3D 4D 5D"};
        EXPECT_EQ(aceToFiveStraightFlush2.getHandRank(), HandRank::StraightFlush);

    }

    TEST(OptimizedPokerHandAnalyzerTests, BasicTests){
        OptimizedPokerHandAnalyzer pair {"AH AC QD TC 4S"};
    }
}