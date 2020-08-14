//
// Created by Mark Barbaric on 01/11/2019.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "../../Header.h"

template<typename Type>
struct Node
{
    Node(const Type& d)
        :data(d)
    {

    }

    Type data;
    Node* left = nullptr;
    Node* right = nullptr;
};

#endif

namespace BasicBSTAlgorithms
{
	//Preorder Root/Left/Right || Inorder Left/Root/Right || PostOrder Left/Right/Root
	enum class TraversalType {Preorder = 0, Inorder, Postorder};
	
    template<typename T>
    inline std::string Traverse(Node<T>* root, TraversalType type)
    {
        if (!root)
            return "";

        if (type == Preorder)
            return std::to_string(root->data) + Traverse(root->left, type) + Traverse(root->right, type);

    	if(type == Inorder)
            return Traverse(root->left, type) + std::to_string(root->data) + Traverse(root->right, type);

        if (type == Postorder)
            return Traverse(root->left, type)  + Traverse(root->right, type) + std::to_string(root->data);
    }

	template<typename T>
	inline int MaxMinHeight(Node<T>* root, bool max)
    {
        if (!root)
            return 0;

        return max ? 1 + std::max(MaxMinHeight(root->left, max), MaxMinHeight(root->right, max)) : 1 + std::min(MaxMinHeight(root->left, max), MaxMinHeight(root->right, max));
    }

	template<typename T>
	inline int Sum(Node<T>* root)
    {
        if (!root)
            return 0;

        return root->data + Sum(root->left) + Sum(root->right);
    }
    	
}

//template<typename Data>
//class BinarySearchTree : public Tree<Data>
//{
//    enum TraversalType {PreOrder, InOrder, PostOrder};
//
//
//    std::unique_ptr<Node> root;
//
//    void insertNode(Node* node, const Data& data)
//    {
//        if(data < node->data)
//        {
//            if(node->left)
//                insertNode(node->left.get(), data);
//            else
//                node->left = std::make_unique<Node>(data);
//        }
//
//        if(data > node->data)
//        {
//            if(node->right)
//                insertNode(node->right.get(), data);
//            else
//                node->right = std::make_unique<Node>(data);
//        }
//
//    }
//
//    void removeNode(std::unique_ptr<Node>& root, const Data& data, bool successor)
//    {
//        if(!root)
//            return;
//        if(data < root->data)
//            removeNode(root->left, data, successor);
//        else if(data > root->data)
//            removeNode(root->right, data, successor);
//
//        else
//        {
//            //Leaf Node
//            if(!root->left && !root->right)
//            {
//                root.reset();
//                return;
//            }
//
//            else if(root->left && !root->right)
//            {
//                auto temp = std::make_unique<Node>(root->left->data);
//                root.reset();
//                root = std::move(temp);
//                return;
//            }
//
//            else if(!root->left && root->right)
//            {
//                auto temp = std::make_unique<Node>(root->right->data);
//                root.reset();
//                root = std::move(temp);
//                return;
//            }
//
//            //Successor
//            if(successor)
//            {
//
//
//            }
//                //Predecessor
//            else if(!successor)
//            {
//                std::unique_ptr<Node> temp = detachRightMost(root->left);
//                temp->right = std::move(root->right);
//                std::unique_ptr<Node>& leftMost = getLeftMostNode(temp);
//                temp->left = std::move(root->left);
//                root.reset();
//                root = std::move(temp);
//            }
//
//
//        }
//    }
//
//    std::unique_ptr<Node> sortedArrayToBSTUtil(std::vector<int>& arr, int l , int r)
//    {
//        if(l > r)
//            return nullptr;
//
//        auto m = l + (r - l) / 2;
//        std::unique_ptr<Node> newRoot = std::make_unique<Node>(arr[m]);
//
//        newRoot->left = std::move(sortedArrayToBSTUtil(arr, l, m - 1));
//        newRoot->right = std::move(sortedArrayToBSTUtil(arr, m + 1, r));
//
//        return std::move(newRoot);
//
//
//    }
//
//  //
//    std::unique_ptr<Node> detachRightMost(std::unique_ptr<Node> &nodeRef) {
//        if (nodeRef->right)
//            return detachRightMost(nodeRef->right);
//
//        return std::move(nodeRef);
//    }
//
//    std::unique_ptr<Node>& getLeftMostNode(std::unique_ptr<Node>& root) const
//    {
//        if(root->left)
//            return getLeftMostNode(root->left);
//
//        return root;
//    }
//
//    bool isValidBSTUtil(Node* root, Node* n1 = nullptr, Node* n2 = nullptr) const
//    {
//        if(!root)
//            return true;
//        if(n1 && root->data <= n1->data)
//            return false;
//        if(n2 && root->data >= n2->data)
//            return false;
//
//        return isValidBSTUtil(root->left.get(), n1, root) && isValidBSTUtil(root->right.get(), root, n2);
//    }
//
//
//public:
//
//    void insert(const Data& data) override
//    {
//        if(!root)
//            root = std::make_unique<Node>(data);
//        else
//            insertNode(root.get(), data);
//    }
//
//	int heightUtil(Node<Data>* node)
//    {
//	    
//    }
//
//	int height(Node<Data>* node)
//    {
//        return heightUtil(node);
//    }
//
//
//    void remove(const Data& data) override
//    {
//        if(root)
//            removeNode(root, data, false);
//    }
//
//    void inOrderTraversal() const override
//    {
//        std::cout << "In Order Traversal." << std::endl;
//        traverseNodes(root.get(), InOrder);
//        std::cout << std::endl;
//    }
//
//    void sortedArrayToBST(std::vector<int>& arr)
//    {
//        root = sortedArrayToBSTUtil(arr, 0, arr.size() - 1);
//    }
//
//
//    bool isValidBST() const override
//    {
//        return isValidBSTUtil(root.get());
//    }
//
//
//};
//
//#endif //BACKTRACKING_BINARYSEARCHTREE_H
