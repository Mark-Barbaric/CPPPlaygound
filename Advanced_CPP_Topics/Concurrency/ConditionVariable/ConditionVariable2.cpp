#include <condition_variable>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>

std::condition_variable cv;
std::mutex mt;
bool ready = false;

void Signals() {
    std::cerr << "Starting signalling thread." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lk(mt);
        std::cerr << "Notifying..." << std::endl;
    }

    cv.notify_all();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    {
        std::lock_guard<std::mutex> lk(mt);
        std::cerr << "Notifying again..." << std::endl;
    }

    ready = true;
    cv.notify_all();
}

void Waits() {
    std::cerr << "Waiting for signal." << std::endl;
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk, []{return ready;});
    std::cerr << "Finished waiting." << std::endl;
}

int main(int argc, char** argv){
    std::vector<std::thread> threads;
    threads.reserve(4);

    threads.emplace_back(std::thread(Signals));
    threads.emplace_back(std::thread(Waits));
    threads.emplace_back(std::thread(Waits));
    threads.emplace_back(std::thread(Waits));

    std::for_each(threads.begin(), threads.end(), [](auto& t){t.join();});

    return 0;
}