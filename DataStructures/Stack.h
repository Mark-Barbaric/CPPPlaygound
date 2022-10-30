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
    TwoQueueStack() = default;
  
  void push(int x)
  {
    currentSize++;
    q2.push(x);
    
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    
    std::queue<int> q = q1;
    q1 = q2;
    q2 = q;
  }
  
  void pop()
  {
    if (q1.empty())
      return;
    q1.pop();
    currentSize--;
  }
  
  int top()
  {
    if (q1.empty())
      return -1;
    return q1.front();
  }
  
  const size_t size() const noexcept {return currentSize;}
};

#endif //STACK_QUEUE_STACK_H
