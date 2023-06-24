#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

std::condition_variable cv;
std::mutex global_mutex;
bool ready=false;
bool processed=false;

void worker_thread()
{
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(global_mutex);    
    cv.wait(lk, []{
        std::cout << "condition_lock" << std::endl;
        return ready;});
    std::cout << "starting work" << std::endl;

    
    std::this_thread::sleep_for(std::chrono::seconds(2));

    processed=true;
    std::cout << "signalling work complete" << std::endl;
    lk.unlock();
    cv.notify_one();
}
