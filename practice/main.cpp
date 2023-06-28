#include <vector>
#include <iostream>
#include <algorithm>

void addMedianToAns(
    int nums[],
    size_t len,
    std::vector<double>& ans){
    const auto m = len / 2;
    double median = 0.0;
    
    if(len % 2 == 0){
        median = (static_cast<double>(nums[m]) + 
        static_cast<double>(nums[m - 1])) 
        / 2.0;
    } else {
        median = static_cast<double>(nums[m]);
    }
    ans.push_back(median);
}

int binarySearch(
    int nums [],
    size_t len,
    int target){
    
    int l = 0, r = len - 1;

    while(l <= r){
        const auto m = l + (r - l) / 2;
        if(nums[m] == target){
            return m;
        }
        if(nums[m] > target){
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

void sortLeft(
    int nums[],
    int s){
    
    while(s >= 1 && nums[s] < nums[s - 1]){
        std::swap(nums[s], nums[s-1]);
        s--;
    }
}

void sortRight(
    int nums[],
    size_t len,
    int s){
    while(s <= len - 2 && nums[s] > nums[s + 1]){
        std::swap(nums[s], nums[s+1]);
        s++;
    }
}

void replaceNum(std::vector<int>& nums, 
int numberToReplace,
int newNum){
    const auto i = binarySearch(nums, numberToReplace);
    nums[i] = newNum;
    
    if(i >= 1 && nums[i] < nums[i - 1]){
        //sort left
        sortLeft(nums, i);
    }

    if(i <= nums.size() - 2 && nums[i] > nums[i + 1]){
        //sort right
        sortRight(nums, i);
    }
}

std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<double> ans;
    std::vector<int> curNums (k, 0);

    for(int i = 0; i < k; ++i){
        curNums[i] = nums[i];
    }

    std::sort(curNums.begin(), curNums.end());
    addMedianToAns(curNums, ans);

    for(int i = k; i < nums.size(); ++i){
        replaceNum(curNums, nums[i - k], nums[i]);
        addMedianToAns(curNums, ans);
    }

    return ans;
}


int main(){
    std::vector<int> i1 = {1,2};
    const auto ans = medianSlidingWindow(i1, 1);
    int test[2];
    for(const auto& a : ans){
        std::cout << a << std::endl;
    }
}