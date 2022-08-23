#pragma once
#include "PokerHandBase.h"
#include "Profiling/ScopedTimer.h"
#include <algorithm>

namespace PokerHands{

    class OptimizedPokerHandAnalyzer : public PokerHandBase {

        int m_handValues[5]{0,0,0,0,0};
        int m_suitCount[4]{0,0,0,0};
        int m_highestHandValue{0};
        bool m_containsFlush {true};
        bool m_containsStraight {false};

    public:

        explicit OptimizedPokerHandAnalyzer(std::string_view hand) : PokerHandBase(hand)
        {
            analyzeCards();
        }

        Comparison compareWith(const PokerHandBase& hand) override {

            return Comparison::Tie;
        }


        private:

        void analyzeCards(){

            MEASURE_FUNCTION();
            std::stringstream ss (m_hand);
            std::string pokerHand;
            auto i = 0;
            auto maxSuitValues = INT_MIN;

            while(std::getline(ss, pokerHand, ' ')){

                const auto curCard = pokerHand[0];
                const auto curSuit = pokerHand[1];
                m_handValues[i] = faceToValue(curCard);
                m_suitCount[suitToValue(curSuit)]++;
                m_highestHandValue = std::max(m_highestHandValue, m_handValues[i]);
                maxSuitValues = std::max(maxSuitValues, m_suitCount[suitToValue(curSuit)]);
                i++;
            }

            std::sort(std::begin(m_handValues), std::end(m_handValues));
            m_containsFlush = maxSuitValues == 5;

            size_t pairCount = 0, tripCount = 0, quadCount = 0;

            for(int i = 1; i < 5; ++i){
                if(m_handValues[i] - m_handValues[i - 1] == 1){
                    m_containsStraight = true;
                } else {

                    if(i == 4 && m_handValues[i] == 14 && m_handValues[0] == 2){
                        ///hmmmm
                        m_highestHandValue = 5;
                        m_containsStraight = true;
                        break;
                    }

                    m_containsStraight = false;
                    break;
                }
            }

            setHandRank();
        }

        void setHandRank() {

            MEASURE_FUNCTION();
            if(m_containsFlush || m_containsStraight){
                if(m_containsStraight && m_containsFlush){
                    m_handRank = m_highestHandValue == 14 ? HandRank::RoyalFlush : HandRank::StraightFlush;
                } else if(m_containsStraight && !m_containsFlush){
                    m_handRank = HandRank::Straight;
                } else if(!m_containsStraight && m_containsFlush){
                    m_handRank = HandRank::Flush;
                }

            } else {
                analyzeCardCount();
            }

        }

        void analyzeCardCount() {

            int cardCount[14];
            size_t tripCount = 0, pairCount = 0, quadCount = 0;

            std::for_each(std::begin(m_handValues), std::end(m_handValues), [&](auto& v){
                cardCount[v]++;
            });

            std::for_each(std::begin(cardCount), std::end(cardCount), [&](auto& c){
               if(c == 2){
                   pairCount++;
               } else if(c == 3){
                   tripCount++;
               } else if(c == 4){
                   quadCount++;
               }
            });

            //TODO refactor this!!!!!

            if(quadCount){
                m_handRank = HandRank::FourOfaKind;
                return;
            }

            if(tripCount){
                m_handRank = pairCount ? HandRank::FullHouse : HandRank::ThreeOfAKind;
                return;
            }

            if(pairCount){
                m_handRank = pairCount == 2 ? HandRank::TwoPair : HandRank::OnePair;
                return;
            }

            m_handRank = HandRank::HighCard;
        }

    };


}