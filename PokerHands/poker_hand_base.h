#pragma once
#include <string>
#include <string_view>
#include <unordered_set>

namespace PokerHands {

    enum class Comparison : char {
        Tie = 0,
        Win = 1,
        Loss = 2,
        NotImplemented = 3
    };

    enum class HandRank : char {
        Unclassified = 0,
        HighCard = 1,
        OnePair = 2,
        TwoPair = 3,
        ThreeOfAKind = 4,
        Straight = 5,
        Flush = 6,
        FullHouse = 7,
        FourOfaKind = 8,
        StraightFlush = 9,
        RoyalFlush = 10
    };

    class PokerHandBase {
        protected:

        const std::string m_hand;
        
        public:

        explicit PokerHandBase(std::string_view hand)
        :m_hand(hand)
        {

        }

        virtual Comparison CompareHand(const PokerHandBase& rhs) = 0;
        virtual HandRank GetHandRank() const noexcept = 0;

        [[nodiscard]] const std::string& getHand() const noexcept {return m_hand;}
        
    };
}