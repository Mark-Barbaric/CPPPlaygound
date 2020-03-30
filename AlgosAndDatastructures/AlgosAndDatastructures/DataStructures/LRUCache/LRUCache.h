//
// Created by Mark Barbaric on 28/10/2019.
//

#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <map>
#include <list>
#include "Cache.h"

struct LRUZeroSizeException : std::exception
{
    LRUZeroSizeException() = default;

    const char* what() const noexcept override
    {
        return "LRU Cache Can't be zero size";
    }
};


template<typename Data>
class LRUCache : public Cache<Data>
{
    //Data Hiding
    struct Node
    {
        Node(int i, const Data& d)
                :index(i),
                 data(d)
        {

        }

        int index;
        Data data;
    };


    std::list<Node> stack;
    std::map<int, typename std::list<Node>::iterator> map;

    /*
        Set or insert the value if not present.
        When capacity is reached then least recently used item
        should be invalidated.
     */

    void insert(int index, const Data& data) override
    {
        if(map.find(index) != map.end())
        {
            stack.erase(map[index]);
            map.erase(index);
        }

        Node node(index, data);
        stack.push_front(node);
        map[index] = stack.begin();

        if(stack.size() > Cache<Data>::capacity)
        {
            auto last = stack.back();
            stack.pop_back();
            map.erase(last.index);
        }
    }

public:
    LRUCache(const size_t c)
    :Cache<int>(c)
    {
        if(c <= 0)
            throw LRUZeroSizeException();
    }

    void put(int index, const Data& data) override
    {
        insert(index, data);
    }


    Data get(int index) override
    {
        auto it = map.find(index);
        if(it == map.end())
            return -1;

        Node value = *it->second;
        auto data = value.data;
        insert(index, data);
        return data;
    }
};

#endif //BACKTRACKING_LRUCACHE_H
