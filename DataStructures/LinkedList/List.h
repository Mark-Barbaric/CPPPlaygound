//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef LIST_H
#define LIST_H

template<class Data>
class List
{
public:
    virtual void insert(const Data& data) = 0;
    virtual void remove(const Data& data) = 0;
    virtual void traverseList() const = 0;
    virtual int size() const = 0;
};


#endif //LINKEDLIST_LINKEDLIST_H
