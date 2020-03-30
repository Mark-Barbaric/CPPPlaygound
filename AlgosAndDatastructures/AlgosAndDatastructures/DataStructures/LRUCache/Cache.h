//
// Created by Mark Barbaric on 28/10/2019.
//

#ifndef CACHE_H
#define CACHE_H

template<typename Data>
struct Cache
{
    const size_t capacity;
    explicit Cache(const size_t c)
            :capacity(c)
    {

    }

    virtual void put(int index, const Data& data) = 0;
    virtual Data get(int index) = 0;
    virtual void insert(int index, const Data& data) = 0;
};


#endif //BACKTRACKING_CACHE_H
