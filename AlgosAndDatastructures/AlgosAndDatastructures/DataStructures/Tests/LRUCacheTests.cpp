#include "../../../../Catch2/single_include/catch2/catch.hpp"
#include "../LRUCache/LRUCache.h"
// Created by Mark Barbaric on 28/10/2019.
//
TEST_CASE("Basic Testing")
{
    SECTION("Basic Functionality Tests")
    {
        LRUCache<int> lRUCache(2);
        lRUCache.put(1, 1);
        lRUCache.put(2, 4);
        CHECK(lRUCache.get(2) == 4);
        lRUCache.put(3, 3);
        //1 should have been removed.
        auto negativeResponse = lRUCache.get(1);
        CAPTURE(negativeResponse);
        CHECK(negativeResponse == -1);
        CHECK(lRUCache.get(3) == 3);
    }

    SECTION("New Tests")
    {
        LRUCache<int> lRUCache(1);
        lRUCache.put(2, 1);
        CHECK(lRUCache.get(2) == 1);
        lRUCache.put(3, 2);
        CHECK(lRUCache.get(2) == -1);
        CHECK(lRUCache.get(3) == 2);
    }
}
