#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include <DataStructures/CircularQueue.h>

namespace DataStructures::Queues{

    TEST_CASE("Circular Queue Datastructures"){

        CircularQueue<int> queue1(3);
        REQUIRE(queue1.pop() == -1);
        REQUIRE(queue1.isEmpty() == true);
        REQUIRE(queue1.push(12) == true);
        REQUIRE(queue1.front() == 12);
        REQUIRE(queue1.push(13) == true);
        REQUIRE(queue1.front() == 13);
        REQUIRE(queue1.push(14) == true);
        REQUIRE(queue1.front() == 14);
        REQUIRE(queue1.isFull() == true);
        REQUIRE(queue1.pop() == 12);
        REQUIRE(queue1.isFull() == false);
        REQUIRE(queue1.push(15) == true);
        REQUIRE(queue1.isFull() == true);
        REQUIRE(queue1.pop() == 13);
        REQUIRE(queue1.pop() == 14);
        REQUIRE(queue1.pop() == 15);
        REQUIRE(queue1.isEmpty() == true);
    }


}