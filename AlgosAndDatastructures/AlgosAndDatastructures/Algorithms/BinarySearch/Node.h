//
// Created by Mark Barbaric on 06/09/2019.
//

#ifndef BINARYSEARCH_NODE_H
#define BINARYSEARCH_NODE_H

class Node
{
public:
    Node(Node* leftChild, Node* rightChild, int id)
    {
        this->leftChild = leftChild;
        this->rightChild = rightChild;
        this->id = id;
    }

    Node* getLeftChild() const
    {
        return this->leftChild;
    }

    Node* getRightChild() const
    {
        return this->rightChild;
    }

    int maxDepth(Node* node)
    {
        auto test = this->id;
        static std::deque<Node*> checkedFriends;
        checkedFriends.push_back(node);
        auto test2 = checkedFriends.size();

        if(node == nullptr)
            return 0;

        else
        {
            int l = maxDepth(node->getLeftChild());
            int r = maxDepth(node->getRightChild());
            return 1 + std::max(l, r);
        }
    }
    int height()
    {
        return maxDepth(this) - 1;
    }
private:
    Node* leftChild;
    Node* rightChild;
    int id;
};

#endif //BINARYSEARCH_NODE_H
