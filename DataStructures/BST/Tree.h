//
// Created by Mark Barbaric on 30/10/2019.
//

#ifndef BACKTRACKING_TREE_H
#define BACKTRACKING_TREE_H

template<typename Data>
struct Tree
{

    virtual void insert(const Data& data) = 0;
    virtual void remove(const Data& data) = 0;
    virtual void inOrderTraversal() const = 0;


    virtual bool isValidBST() const = 0;

};

#endif //BACKTRACKING_TREE_H
