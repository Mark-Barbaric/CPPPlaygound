//
// Created by Mark Barbaric on 14/10/2019.
//
#include "include/catch.hpp"
#include "../../DataStructures/Queue.h"
#include "../../DataStructures/Stack.h"

SCENARIO("Queue Functionality Datastructures")
{
    TwoStackQueue <int> q;

    REQUIRE(q.isEmpty());

    q.enqueue(1);
    q.enqueue(2);

    REQUIRE(!q.isEmpty());
    REQUIRE(q.size() == 2);
  
  WHEN("Queue is Enqueued")
  {
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    REQUIRE(q.dequeue() == 1);
    REQUIRE(q.front() == 2);
  }
}

TEST_CASE("Queue FIFO Test")
{
    TwoStackQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    REQUIRE(q.dequeue() == 1);
    REQUIRE(q.front() == 2);
}

TEST_CASE("Stack Functionality Checks")
{
    TwoQueueStack<int> s;
    REQUIRE(s.size() == 0);
    s.push(1);
    REQUIRE(s.size() == 1);
    s.pop();
}

TEST_CASE("Stack LIFO Datastructures")
{
    TwoQueueStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    REQUIRE(s.top() == 3);
    s.pop();
    REQUIRE(s.top() == 2);
    REQUIRE(s.size() == 2);
}




