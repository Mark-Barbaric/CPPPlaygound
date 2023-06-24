#include <vector>

namespace Algorithms::TwoPointer::Medium{

    int doubleZeroes(std::vector<int>& nums){

        int r = static_cast<int> (nums.size()) - 1, l = r, zeroCount = 0;

        while (l >= 0){


            while(nums[l] == 0){
                zeroCount += 2;
                l--;
            }

            while(l < r && zeroCount > 0){
                
                l++;
                zeroCount++;
            }
            

            l--;
        }

        return 0;
    }
}