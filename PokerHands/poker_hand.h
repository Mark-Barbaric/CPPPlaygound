#pragma once

#include "poker_hand_base.h"
#include <unordered_map>

namespace PokerHands {

    class PokerHand : public PokerHandBase {


        public:
        explicit PokerHand(std::string_view hand);

        void AnalyzeHand();
        
        static bool IsPokerCardValid(const std::string& card) {

            if(card.size() > 3){
                return false;
            }
            std::unordered_set<char> allowedCardSuits = {'C', 'H', 'D', 'S'};
            const char cardSuit = card[card.size() - 1];

            if(allowedCardSuits.find(cardSuit) == allowedCardSuits.end()){
                return false;
            }

            const auto cardHand = card.substr(0, card.size() - 1);
            std::unordered_set <std::string> allowedCardHands = {
                "A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
            };

            return allowedCardHands.find(cardHand) != allowedCardHands.end();
        }
        

        Comparison CompareHand(const PokerHandBase& rhs) override;
        HandRank GetHandRank() const noexcept override;
    };
}