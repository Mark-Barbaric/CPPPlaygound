#include <functional>

class Worker {
    std::function<void()> m_work;

    public:

    void setWork(std::function<void()> work){
        this->m_work = std::move(work);
    }

    void execute() {
        this->m_work();
    }
};
