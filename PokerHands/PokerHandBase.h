#pragma once
#include "PokerHandHelpers.h"

namespace PokerHands{

    class PokerHandBase{

    public:

        // violates Liskov Substitution
        int m_handScore {0};
        HandRank m_handRank {HandRank::Unclassified};

        explicit PokerHandBase(std::string_view hand) :m_hand(hand)
        {

        }

        virtual Comparison compareWith(const PokerHandBase& opponent) = 0;

        [[nodiscard]] HandRank getHandRank() const noexcept {return m_handRank;}

    protected:

        virtual void analyzeCards() = 0;
        const std::string m_hand;

    };

}