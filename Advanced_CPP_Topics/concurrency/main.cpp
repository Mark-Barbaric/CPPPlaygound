#include "condition_variable.h"
#include "worker.h"

int main(int argc, char** argv){

    std::thread worker(worker_thread);
    std::cout << "pausing" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::lock_guard<std::mutex> lk(global_mutex);
        ready=true;
    }

    std::cout << "Signalling condition_variable" << std::endl;
    cv.notify_one();

    {
        std::unique_lock<std::mutex> lk(global_mutex);
        cv.wait(lk,[]{return processed;});
    }

    worker.join();

    std::thread t([]{
        std::cout << "Main thread sleeping" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    });

    t.join();

    Worker w1;

    w1.setWork([]{std::cout << "test" << std::endl;});
    w1.execute();
    return 0;
}