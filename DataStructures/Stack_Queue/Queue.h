//
// Created by Mark Barbaric on 14/10/2019.
//

#ifndef TWO_STACK_QUEUE_H
#define TWO_STACK_QUEUE_H

#include <stack>
#include <iostream>
#include <exception>

template <typename Type>
class TwoStackQueue
{
    std::stack<Type> s1, s2;

    class QueueEmptyException : public std::exception{

        const char* what() const noexcept override
        {
            return "Queue Cannot Be Empty";
        }

    };

public:
    void enqueue(Type s)
    {
        s1.push(s);
    }

    Type dequeue()
    {
        if(s1.empty() && s2.empty())
        {
            throw QueueEmptyException();
        }

        if(s2.empty()){
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        Type x = s2.top();
        s2.pop();
        return x;
    }

    Type front()
    {

        if(s1.empty() && s2.empty())
            throw QueueEmptyException();

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.top();
            }

        }

        auto x = s2.top();
        return x;
    }

    const size_t size() const
    {
        return s1.size();
    }

    const bool isEmpty() const
    {
        return s1.empty();
    }

};

#endif //STACK_QUEUE_QUEUE_H
