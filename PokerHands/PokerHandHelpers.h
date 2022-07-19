namespace PokerHands{

    inline int suitToValue(char c){

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

    inline int faceToValue(char c){
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
}