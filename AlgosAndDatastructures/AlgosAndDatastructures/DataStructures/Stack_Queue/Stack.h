//
// Created by Mark Barbaric on 14/10/2019.
//

#ifndef TWO_QUEUE_STACK_H
#define TWO_QUEUE_STACK_H

#include <queue>

template<typename Type>
class TwoQueueStack
{
    std::queue<Type> q1, q2;
    size_t currentSize;

public:
    TwoQueueStack()
    {

    }

    void push(Type s)
    {


    }

    void pop()
    {

    }

    Type top()
    {
		Type t = 0;
		return t;
    }

    size_t size()
    {
        return q1.size();
    }

};

#endif //STACK_QUEUE_STACK_H
