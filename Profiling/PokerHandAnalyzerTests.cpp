#include <gtest/gtest.h>
#include "PokerHandAnalyzer.h"

namespace Profiling{
    TEST(PokerHandAnalyzerTests, HandRankTests){


        PokerHandAnalyzer highCard {"TH JD 9C 7S AH"};
        assert(highCard.getHandRank() == PokerHandAnalyzer::HandRank::HighCard);
        std::cout << "High Card Rank Test Succeeded.\n";

        PokerHandAnalyzer pair {"2H 2S 3D 5S 6H"};
        assert(pair.getHandRank() == PokerHandAnalyzer::HandRank::OnePair);
        std::cout << "Pair Card Rank Test Succeeded.\n";

        PokerHandAnalyzer twoPair {"TH TS 3D 3S AH"};
        assert(twoPair.getHandRank() == PokerHandAnalyzer::HandRank::TwoPair);
        std::cout << "Two Pair Card Rank Test Succeeded.\n";

        PokerHandAnalyzer trips {"TH TS TD 3S AH"};
        assert(trips.getHandRank() == PokerHandAnalyzer::HandRank::ThreeOfAKind);
        std::cout << "Trips Card Rank Test Succeeded.\n";

        PokerHandAnalyzer fullHouse {"TH TS TD 3S 3H"};
        assert(fullHouse.getHandRank() == PokerHandAnalyzer::HandRank::FullHouse);
        std::cout << "FullHouse Card Rank Test Succeeded.\n";

        PokerHandAnalyzer quads {"QH QS QD QC AH"};
        assert(quads.getHandRank() == PokerHandAnalyzer::HandRank::FourOfaKind);
        std::cout << "Quads Card Rank Test Succeeded.\n";

        PokerHandAnalyzer straight {"3H 4D 5D 6S 7D"};
        assert(straight.getHandRank() == PokerHandAnalyzer::HandRank::Straight);
        std::cout << "Straight Card Rank Test Succeeded.\n";

        PokerHandAnalyzer flush {"QH 2H 8H JH AH"};
        assert(flush.getHandRank() == PokerHandAnalyzer::HandRank::Flush);
        std::cout << "Flush Card Type Rank Succeeded.\n";

        PokerHandAnalyzer straightFlush {"9H TH JH QH KH"};
        assert(straightFlush.getHandRank() == PokerHandAnalyzer::HandRank::StraightFlush);
        std::cout << "Straigh Flush Card Rank Test Succeeded.\n";

        PokerHandAnalyzer royalFlush {"TD JD QD KD AD"};

    }
}