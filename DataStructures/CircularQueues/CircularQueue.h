#include "../../include/Header.h"

namespace Datastructures::CircularQueue{
    class CircularQueue {

        const size_t m_bufferSize;
        int* m_buffer {nullptr};
        int m_head {-1};
        int m_tail {-1};

    public:

        explicit CircularQueue(const size_t bufferSize):m_bufferSize(bufferSize){
            m_buffer = new int[m_bufferSize];
        }

        ~CircularQueue(){
            delete [] m_buffer;
            m_buffer = nullptr;
        }

        [[nodiscard]] bool push(int newVal){

            if(isFull()){
                return false;
            }

            if(m_head == -1){
                m_tail = 0;
            }

            m_head++;

            if(m_head == m_bufferSize){
                m_head = 0;
            }

            m_buffer[m_head] = newVal;
            return true;
        }

        [[nodiscard]] int pop(){

            if(isEmpty()){
                return -1;
            }

            if(m_tail == m_bufferSize){
                m_tail = 0;
            }

            const auto curVal = m_buffer[m_tail];
            m_buffer[m_tail++] = -1;

            if(m_buffer[m_head] == -1){
                m_head = m_tail = -1;
            }

            return curVal;
        }

        [[nodiscard]] int front() const noexcept {return isEmpty() ? -1 : m_buffer[m_head];}
        [[nodiscard]] int back() const noexcept {return isEmpty() ? -1 : m_buffer[m_tail];}

        [[nodiscard]] bool isEmpty() const noexcept {return m_head == -1;}
        [[nodiscard]] bool isFull() const noexcept {

            if((m_head == m_bufferSize - 1 && m_tail == 0) ||
            m_tail - m_head == 1){
                return true;
            }

            return false;
        }


    };
}