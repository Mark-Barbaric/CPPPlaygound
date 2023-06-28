#pragma once
#include "PokerHandBase.h"
#include <Profiling/ScopedTimer.h>

namespace PokerHands{
    class PokerHandAnalyzer : public PokerHandBase{

    public:

        explicit PokerHandAnalyzer(std::string_view hand) : PokerHandBase(hand)
        {
            analyzeCards();
        }

        Comparison compareWith(const PokerHandBase& opponent) override{
            if(m_handRank > opponent.m_handRank){
                return Comparison::Win;
            } else if(m_handRank < opponent.m_handRank){
                return Comparison::Loss;
            } else {
                if(m_handScore > opponent.m_handScore){
                    return Comparison::Win;
                } else if (m_handScore < opponent.m_handScore) {
                    return Comparison::Loss;
                } else {
                    return Comparison::Tie;
                }
            }
        }

        void analyzeCards() override
        {
            MEASURE_FUNCTION();
            std::stringstream ss (m_hand);
            std::string pokerHand;

            auto max = INT_MIN, min = INT_MAX, i = 0;

            while(std::getline(ss, pokerHand, ' ')){

                const auto curCard = pokerHand[0];
                const auto curSuit = static_cast<char>(std::tolower(pokerHand[1]));
                m_cards[i] = faceToValue(curCard);
                max = std::max(m_cards[i], max);
                min = std::min(m_cards[i], min);
                m_suitCount[curSuit]++;
                m_cardCount[curCard]++;
                i++;
            }

            m_containsFlush = m_suitCount.size() == 1;
            m_highestCardValue = max;
            m_containsStraight = (max - min + 1) == 5 && m_cardCount.size() == 5;
            setHandRank();
        }

        void setHandRank()
        {
            MEASURE_FUNCTION();
            if(m_containsFlush || m_containsStraight){
                m_handScore = m_highestCardValue * 100000;
                if(m_containsStraight && m_containsFlush){
                    m_handRank = m_highestCardValue == 14 ? HandRank::RoyalFlush : HandRank::StraightFlush;
                } else if(m_containsStraight && !m_containsFlush){
                    m_handRank = HandRank::Straight;
                } else if(!m_containsStraight && m_containsFlush){
                    m_handRank = HandRank::Flush;
                }
            } else {
                analyzeCardCount();
                if(m_numQuads == 0 && m_numTrips == 0 && m_numPairs == 0){
                    m_handRank = HandRank::HighCard;
                } else {
                    if(m_numQuads){
                        m_handRank = HandRank::FourOfaKind;
                    } else if(m_numTrips){
                        m_handRank = m_numPairs ? HandRank::FullHouse : HandRank::ThreeOfAKind;
                    } else if(m_numPairs && !m_numTrips){
                        m_handRank = m_numPairs == 2 ? HandRank::TwoPair : HandRank::OnePair;
                    }
                }
            }
        }

        void analyzeCardCount()
        {
            MEASURE_FUNCTION();
            for(auto& c : m_cardCount){
                if(c.second > 1){
                    if(c.second == 3){
                        m_numTrips++;
                    } else if(c.second == 2){
                        m_numPairs++;
                    } else if(c.second == 4){
                        m_numQuads++;
                    }
                    m_handScore += (faceToValue(c.first) * c.second) * static_cast<int>(std::pow(10, c.second));
                }else {
                    m_handScore += faceToValue(c.first);
                }
            }
        }

        int m_cards[5]{};
        int m_handScore {0};
        bool m_containsStraight {false};
        bool m_containsFlush {false};
        int m_highestCardValue{0};
        std::unordered_map<char,int> m_cardCount;
        std::unordered_map<char,int> m_suitCount;
        int m_numPairs {0};
        int m_numTrips {0};
        int m_numQuads {0};

    };
}