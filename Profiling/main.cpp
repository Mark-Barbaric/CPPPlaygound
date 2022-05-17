#include "ScopedTimer.h"
#include "ModuloImprovements.h"
#include "PokerHands/PokerHandAnalyzer.h"
#include "PokerHands/OptimizedPokerHandAnalyzer.h"

void analyzePokerHand(std::string_view string){

    std::cout << "\n\n Analyzing " << string << ".\n";
    Profiling::PokerHandAnalyzer hand1(string);
    hand1.analyzeHand();
}

void analyzeOptimizedPokerHand(std::string_view string){

    std::cout << "\n\n Analyzing " << string << ".\n";
    Profiling::OptimizedPokerHandAnalyzer hand1(string);
    hand1.analyzeHand();
}

int getHandRankBySorting(std::vector<int> arr){
    MEASURE_FUNCTION();
    std::sort(arr.begin(), arr.end());

    auto count = 1, ans = INT_MIN;

    for(int i = 1; i < arr.size(); ++i){
        if(arr[i] == arr[i - 1]){
            count++;
            ans = std::max(ans, count);
        } else {
            count = 1;
        }
    }

    return count;
}

int getHandRankByHashMap(std::vector<int> arr){
    MEASURE_FUNCTION();
   // std::unordered_map<int,int> mp;
    int mp[11];

    auto count = INT_MIN;

    for(const auto& a : arr){
        mp[a]++;
        count = std::max(count, mp[a]);
    }

    return count;
}


int main(int argc, char* argv[]){

    std::cout << "\n\n Profiling modulus optimizations.\n";
    Profiling::runStandardModulus();
    Profiling::runBitwiseModulus();

    std::vector<int> arr {10,2,10,10,10,5,5,6,4,3,2,2,2,1,7};

    std::cout << "\n\n Profiling hand analysis.\n";
    getHandRankBySorting(arr);
    std::cout << "\n\n Profiling hand analysis.\n";
    getHandRankByHashMap(arr);

    std::cout << "\n\n PokerHandAnalyzer.\n";
    analyzePokerHand("AH AD AS AC 9H");

    std::cout << "\n\n PokerHandAnalyzer.\n";
    analyzeOptimizedPokerHand("AH AD AS AC 9H");

    return 0;

}