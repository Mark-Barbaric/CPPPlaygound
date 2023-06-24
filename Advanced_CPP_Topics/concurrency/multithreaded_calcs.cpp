#include <vector>
#include <algorithm>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <Profiling/ScopedTimer.h>

const int numThreads = 4;
bool processed = false;
std::condition_variable cv;
std::mutex m;
int workCount = 0;

void processNums(std::vector<int>& nums, int start, int end, int threadNum){
    
    for(int i = start; i < end; ++i){
        workCount+=1;
        std::cout << "threadNum: " << threadNum <<", workCount: " << workCount << ", updating: i" << i << std::endl; 
        nums.emplace_back(i + 1);
    }
}

int main(int argc, char** argv){

    std::vector<int> nums;
    const int size = 20;
    nums.reserve(size);
    const int chunks = size / numThreads;

    std::vector<std::thread> threads;
    threads.reserve(numThreads);
    auto count = 0;
    
    MEASURE_FUNCTION();
    for(int i = 0; i <= size - chunks; i += chunks){
        count += 1;
        threads.emplace_back(std::thread(processNums, std::ref(nums), i, i + chunks, count));
    }
    std::cout << "joining threads" << std::endl;

    for(auto& t : threads){
        t.join();
    }
    {   
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return workCount == size;});
    }

    std::cout << "work finished " << nums[12] << " size: " << nums.size() << std::endl;
    for(const auto& i : nums){
        std::cout << "i, " << nums[i] << std::endl;
    }

    return 0;
}