#include <gtest/gtest.h>
#include "PokerHandAnalyzer.h"
#include "OptimizedPokerHandAnalyzer.h"

namespace PokerHands{

    TEST(PokerHandAnalyzerTests, StraightAndRoyalFlushTests){

        std::cout << "Straight Flush Datastructures Succeeded.\n\n\n";
        PokerHandAnalyzer straightFlush {"9H TH JH QH KH"};
        OptimizedPokerHandAnalyzer straightFlush2 {"9H TH JH QH KH"};
        EXPECT_EQ(straightFlush.getHandRank(), HandRank::StraightFlush);
        EXPECT_EQ(straightFlush2.getHandRank(), HandRank::StraightFlush);
        std::cout << "Straight Flush Card Rank Test Succeeded.\n";

        OptimizedPokerHandAnalyzer aceToFiveStraightFlush2 {"AD 2D 3D 4D 5D"};
        EXPECT_EQ(aceToFiveStraightFlush2.getHandRank(), HandRank::StraightFlush);

    }

    TEST(PokerHandAnalyzerTests, NonRunTests){


        PokerHandAnalyzer highCard {"TH JD 9C 7S AH"};

        assert(highCard.getHandRank() == HandRank::HighCard);
        std::cout << "High Card Rank Test Succeeded.\n";

        PokerHandAnalyzer pair {"2H 2S 3D 5S 6H"};
        assert(pair.getHandRank() == HandRank::OnePair);
        std::cout << "Pair Card Rank Test Succeeded.\n";

        PokerHandAnalyzer twoPair {"TH TS 3D 3S AH"};
        assert(twoPair.getHandRank() == HandRank::TwoPair);
        std::cout << "Two Pair Card Rank Test Succeeded.\n";

    }

    TEST(PokerHandAnalyzerTests, RestOfTests){


        PokerHandAnalyzer highCard {"TH JD 9C 7S AH"};
        assert(highCard.getHandRank() == HandRank::HighCard);
        std::cout << "High Card Rank Test Succeeded.\n";

        PokerHandAnalyzer pair {"2H 2S 3D 5S 6H"};
        assert(pair.getHandRank() == HandRank::OnePair);
        std::cout << "Pair Card Rank Test Succeeded.\n";

        PokerHandAnalyzer twoPair {"TH TS 3D 3S AH"};
        assert(twoPair.getHandRank() == HandRank::TwoPair);
        std::cout << "Two Pair Card Rank Test Succeeded.\n";

        PokerHandAnalyzer trips {"TH TS TD 3S AH"};
        assert(trips.getHandRank() == HandRank::ThreeOfAKind);
        std::cout << "Trips Card Rank Test Succeeded.\n";

        PokerHandAnalyzer fullHouse {"TH TS TD 3S 3H"};
        assert(fullHouse.getHandRank() == HandRank::FullHouse);
        std::cout << "FullHouse Card Rank Test Succeeded.\n";

        PokerHandAnalyzer quads {"QH QS QD QC AH"};
        assert(quads.getHandRank() == HandRank::FourOfaKind);
        std::cout << "Quads Card Rank Test Succeeded.\n";

        PokerHandAnalyzer straight {"3H 4D 5D 6S 7D"};
        assert(straight.getHandRank() == HandRank::Straight);
        std::cout << "Straight Card Rank Test Succeeded.\n";

        PokerHandAnalyzer flush {"QH 2H 8H JH AH"};
        assert(flush.getHandRank() == HandRank::Flush);
        std::cout << "Flush Card Type Rank Succeeded.\n";

        PokerHandAnalyzer straightFlush {"9H TH JH QH KH"};
        assert(straightFlush.getHandRank() == HandRank::StraightFlush);
        std::cout << "Straigh Flush Card Rank Test Succeeded.\n";

        PokerHandAnalyzer royalFlush {"TD JD QD KD AD"};

    }
}