//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include <memory>
#include <iostream>
#include <exception>
#include <stdexcept>

template<class Data>
class LinkedList : public List<Data>
{
    struct Node
    {
        Data data;
        //unique ptr freed automatically
        std::unique_ptr<Node> nextNode;

        explicit Node(const Data& data_)
                :data(data_)
        {

        }
    };

    int sizeCounter = 0;
    std::unique_ptr<Node> headNode;

public:

    class MissingDataError : public std::runtime_error
    {
    public:
        MissingDataError()
                :std::runtime_error("Missing Data Error")
        {}
    };

    LinkedList() = default;

    void insert(const Data& data) override
    {
        ++sizeCounter;
        insertDataBeginning(data);
    }

    void remove(const Data& data) override
    {
        if(!headNode)
            return;

        //removing first item is very fast O(1).
        //using unique ptrs means you don't have to free memepy;
        if(headNode->data == data)
        {
            auto newHead = std::move(headNode->nextNode);
            headNode = std::move(newHead);
            --sizeCounter;
            return;
        }

        if(!headNode->nextNode)
        {
            throw "Isn't the next node";
        }

        //removing internal node

        Node* prev = headNode.get();
        Node* next = headNode->nextNode.get();

        while(next && next->data != data)
        {
            prev = next;
            next = next->nextNode.get();
        }

        if(!next)
        {
            throw MissingDataError();
        }

        std::unique_ptr<Node> temp = std::move(next->nextNode);
        prev->nextNode = std::move(temp);
    }

    void traverseList() const override {

        //start with the head
        Node *node = headNode.get();

        //while the node is not a NULL we print out the data
        while (node) {
            std::cout << node->data << ' ';
            node = node->nextNode.get();
        }

        std::cout << '\n';
    }

    int size() const override{
        return sizeCounter;
    }

private:

    void insertDataBeginning(const Data& data)
    {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
        newNode->nextNode = std::move(headNode);
        headNode = std::move(newNode);
    }

};

#endif //LINKEDLIST_LINKEDLIST_H
