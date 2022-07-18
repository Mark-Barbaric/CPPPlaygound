#include "../../include/Header.h"

namespace Datastructures::CircularQueue{
    class CircularQueue {

        const size_t m_bufferSize;
        const int m_head {-1};
        const int m_tail{-1};

    public:

        explicit CircularQueue(const size_t bufferSize):m_bufferSize(bufferSize){

        }

    };
}