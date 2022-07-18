#pragma once
#include "../include/Header.h"

namespace Profiling{

    class PokerHandBase{

    public:

        enum class Comparison : char {
            Tie = 0,
            Win = 1,
            Loss = 2
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

        static int suitToValue(char c){

            switch(c){
                case 'D':
                    return 0;
                case 'H':
                    return 1;
                case 'C':
                    return 2;
                case 'S':
                    return 3;
                default:
                    return -1;
            }
        }

        static int faceToValue(char c){
            if(c<='9') {
                return c-'0';
            }
            switch(c){
                case 'T':
                    return 10;
                    case 'J':
                        return 11;
                        case 'Q':
                            return 12;
                            case 'K':
                                return 13;
                                case 'A':
                                    return 14;
                                    default:
                                        return 0;
            }
        }

        explicit PokerHandBase(std::string_view hand) :m_hand(hand)
        {

        }

        Comparison compareWith(const PokerHandBase& opponent)
        {
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

        void analyzeHand(){
            analyzeCards();
        }

    protected:

        virtual void analyzeCards() = 0;
        virtual void setHandRank() = 0;
        virtual void analyzeCardCount() = 0;


        const std::string m_hand;
        HandRank m_handRank {HandRank::Unclassified};
        int m_handScore {0};
    };

}