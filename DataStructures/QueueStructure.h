#include "../include/Header.h"

namespace DataStructures::Queues{

    template<typename T>
    class QueueStructure {

    protected:

        const size_t m_bufferSize;
        T* m_buffer;
        int m_head {-1};
        int m_tail {-1};

    public:

        explicit QueueStructure(const size_t size)
        :m_bufferSize(size){
            m_buffer = new int[m_bufferSize];
        }

        virtual ~QueueStructure(){
            delete [] m_buffer;
            m_buffer = nullptr;
        }

        [[nodiscard]] virtual bool isEmpty() const noexcept = 0;
        [[nodiscard]] virtual bool isFull() const noexcept = 0;
    };
}