#include "ScopedTimer.h"
#include "ModuloImprovements.h"
#include "PreVsPostCrement.h"

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

    std::vector<int> nums(10000000, 1);
    std::cout << "\n\n Profiling Pre Increment.\n";
    preIncrement(nums);
    std::cout << "\n\n Profiling Post Increment.\n";
    postIncrement(nums);

    return 0;

}