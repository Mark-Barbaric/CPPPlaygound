//
// Created by Mark Barbaric on 01/11/2019.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <memory>
#include <iostream>
#include <vector>
#include "Tree.h"

template<typename Data>
class BinarySearchTree : public Tree<Data>
{
    enum TraversalType {PreOrder, InOrder, PostOrder};

    struct Node
    {

        Node(const Data& d)
                :data(d)
        {

        }

        Data data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

    };

    std::unique_ptr<Node> root;

    void insertNode(Node* node, const Data& data)
    {
        if(data < node->data)
        {
            if(node->left)
                insertNode(node->left.get(), data);
            else
                node->left = std::make_unique<Node>(data);
        }

        if(data > node->data)
        {
            if(node->right)
                insertNode(node->right.get(), data);
            else
                node->right = std::make_unique<Node>(data);
        }

    }

    void removeNode(std::unique_ptr<Node>& root, const Data& data, bool successor)
    {
        if(!root)
            return;
        if(data < root->data)
            removeNode(root->left, data, successor);
        else if(data > root->data)
            removeNode(root->right, data, successor);

        else
        {
            //Leaf Node
            if(!root->left && !root->right)
            {
                root.reset();
                return;
            }

            else if(root->left && !root->right)
            {
                auto temp = std::make_unique<Node>(root->left->data);
                root.reset();
                root = std::move(temp);
                return;
            }

            else if(!root->left && root->right)
            {
                auto temp = std::make_unique<Node>(root->right->data);
                root.reset();
                root = std::move(temp);
                return;
            }

            //Successor
            if(successor)
            {


            }
                //Predecessor
            else if(!successor)
            {
                std::unique_ptr<Node> temp = detachRightMost(root->left);
                temp->right = std::move(root->right);
                std::unique_ptr<Node>& leftMost = getLeftMostNode(temp);
                temp->left = std::move(root->left);
                root.reset();
                root = std::move(temp);
            }


        }
    }

    std::unique_ptr<Node> sortedArrayToBSTUtil(std::vector<int>& arr, int l , int r)
    {
        if(l > r)
            return nullptr;

        auto m = l + (r - l) / 2;
        std::unique_ptr<Node> newRoot = std::make_unique<Node>(arr[m]);

        newRoot->left = std::move(sortedArrayToBSTUtil(arr, l, m - 1));
        newRoot->right = std::move(sortedArrayToBSTUtil(arr, m + 1, r));

        return std::move(newRoot);


    }

    void traverseNodes(Node* root, TraversalType type) const
    {
        if(!root)
            return;

        if(type == PreOrder)
            std::cout << root->data << " ";

        traverseNodes(root->left.get(), type);

        if(type == InOrder)
            std::cout << root->data << " ";

        traverseNodes(root->right.get(), type);

        if(type == PostOrder)
            std::cout << root->data << " ";

    }

    std::unique_ptr<Node> detachRightMost(std::unique_ptr<Node> &nodeRef) {
        if (nodeRef->right)
            return detachRightMost(nodeRef->right);

        return std::move(nodeRef);
    }

    std::unique_ptr<Node>& getLeftMostNode(std::unique_ptr<Node>& root) const
    {
        if(root->left)
            return getLeftMostNode(root->left);

        return root;
    }

    bool isValidBSTUtil(Node* root, Node* n1 = nullptr, Node* n2 = nullptr) const
    {
        if(!root)
            return true;
        if(n1 && root->data <= n1->data)
            return false;
        if(n2 && root->data >= n2->data)
            return false;

        return isValidBSTUtil(root->left.get(), n1, root) && isValidBSTUtil(root->right.get(), root, n2);
    }


public:

    void insert(const Data& data) override
    {
        if(!root)
            root = std::make_unique<Node>(data);
        else
            insertNode(root.get(), data);
    }


    void remove(const Data& data) override
    {
        if(root)
            removeNode(root, data, false);
    }

    void inOrderTraversal() const override
    {
        std::cout << "In Order Traversal." << std::endl;
        traverseNodes(root.get(), InOrder);
        std::cout << std::endl;
    }

    void sortedArrayToBST(std::vector<int>& arr)
    {
        root = sortedArrayToBSTUtil(arr, 0, arr.size() - 1);
    }


    bool isValidBST() const override
    {
        return isValidBSTUtil(root.get());
    }


};

#endif //BACKTRACKING_BINARYSEARCHTREE_H
