#include "poker_hand.h"
#include <unordered_map>
#include <sstream>
#include <vector>

namespace PokerHands {

    PokerHand::PokerHand(std::string_view hand)
    :PokerHandBase(hand)
    {

    }

    Comparison PokerHand::CompareHand(const PokerHandBase& base) {

        return Comparison::NotImplemented;
    }

    HandRank PokerHand::GetHandRank() const noexcept {

        return HandRank::Unclassified;
    }

    void PokerHand::AnalyzeHand() {
        
        std::vector<std::string> result;
        std::stringstream ss (m_hand);
        std::string curHand;

        while (std::getline (ss, curHand, ' ')) {
            //result.push_back (item);
            if(!IsPokerCardValid(curHand)){
                throw std::logic_error("Invalid hand provided: " + curHand);
            }
        }
        

    }
}