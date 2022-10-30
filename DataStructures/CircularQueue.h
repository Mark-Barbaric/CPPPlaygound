#include "include/Header.h"
#include "QueueStructure.h"

namespace DataStructures::Queues{

    template<typename T>
    class CircularQueue  : public QueueStructure<T>{

        using QueueBase = QueueStructure<T>;

    public:

        explicit CircularQueue(const size_t bufferSize):QueueBase(bufferSize){

        }

        [[nodiscard]] bool push(int newVal){

            if(isFull()){
                return false;
            }

            if(QueueBase::m_head == -1){
                QueueBase::m_tail = 0;
            }

            QueueBase::m_head++;

            if(QueueBase::m_head == QueueBase::m_bufferSize){
                QueueBase::m_head = 0;
            }

            QueueBase::m_buffer[QueueBase::m_head] = newVal;
            return true;
        }

        [[nodiscard]] int pop(){

            if(isEmpty()){
                return -1;
            }

            if(QueueBase::m_tail == QueueBase::m_bufferSize){
                QueueBase::m_tail = 0;
            }

            const auto curVal = QueueBase::m_buffer[QueueBase::m_tail];
            QueueBase::m_buffer[QueueBase::m_tail++] = -1;

            if(QueueBase::m_buffer[QueueBase::m_head] == -1){
                QueueBase::m_head = QueueBase::m_tail = -1;
            }

            return curVal;
        }

        [[nodiscard]] int front() const noexcept {return isEmpty() ? -1 : QueueBase::m_buffer[QueueBase::m_head];}
        [[nodiscard]] int back() const noexcept {return isEmpty() ? -1 : QueueBase::m_buffer[QueueBase::m_tail];}

        [[nodiscard]] bool isEmpty() const noexcept override {return QueueBase::m_head == -1;}
        [[nodiscard]] bool isFull() const noexcept override {

            if((QueueBase::m_head == QueueBase::m_bufferSize - 1 && QueueBase::m_tail == 0) ||
                    QueueBase::m_tail - QueueBase::m_head == 1){
                return true;
            }

            return false;
        }


    };
}