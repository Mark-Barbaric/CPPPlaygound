#pragma once
#include "PokerHandBase.h"
#include "Profiling/ScopedTimer.h"

namespace Profiling{

    class OptimizedPokerHandAnalyzer : public PokerHandBase {

        int m_handValues[5]{0,0,0,0,0};
        int m_suitValues[4]{0,0,0,0};
        bool m_containsFlush {false};

    public:

        explicit OptimizedPokerHandAnalyzer(std::string_view hand) : PokerHandBase(hand)
        {

        }
    private:

        void analyzeCards() override{

            MEASURE_FUNCTION();
            std::stringstream ss (m_hand);
            std::string pokerHand;
            auto i = 0;
            auto maxSuitValues = INT_MIN;

            while(std::getline(ss, pokerHand, ' ')){

                const auto curCard = pokerHand[0];
                const auto curSuit = pokerHand[1];
                m_handValues[i] = PokerHandBase::faceToValue(curCard);
                m_suitValues[i] = PokerHandBase::suitToValue(curSuit);
                maxSuitValues = std::max(maxSuitValues, m_suitValues[i]);
                i++;
            }

            std::sort(std::begin(m_handValues), std::end(m_handValues));
            m_containsFlush = maxSuitValues == 5;
        }

        void setHandRank() override {

        }

        void analyzeCardCount() override {

        }

    };


}