//
// Created by Mark Barbaric on 30/10/2019.
//

#ifndef BACKTRACKING_BSTALGORITHMS_H
#define BACKTRACKING_BSTALGORITHMS_H

#include "BinarySearchTree.h"
#include <unordered_map>

namespace BINARY_SEARCH_TREE_ALGOS
{
	template<typename Data>
    Node<Data>* copyLeftRightTrees(Node* root, std::unordered_map<Node*, Node*>& map)
    {
        if (root == nullptr)
            return nullptr;

        map[root] = new Node(root->data);
        map[root]->left = copyLeftRightTrees(root->left, map);
        map[root]->right = copyLeftRightTrees(root->right, map);
        return map[root];
    }

    void copyRandomNodes(Node* root, Node* newTree, std::unordered_map<Node*, Node*>& map)
    {
        if (map[root] == nullptr)
            return;

        newTree->random = map[root]->random;
        copyRandomNodes(root->left, newTree->left, map);
        copyRandomNodes(root->right, newTree->right, map);

    }

    Node* copyLeftRightTrees(Node* root, std::unordered_map<Node*, Node*>& map)
    {
        if (root == nullptr)
            return nullptr;

        map[root] = new Node(root->data);
        map[root]->left = copyLeftRightTrees(root->left, map);
        map[root]->right = copyLeftRightTrees(root->right, map);
        return map[root];
    }

    void copyRandomNodes(Node* root, Node* newTree, std::unordered_map<Node*, Node*>& map)
    {
        if (map[root] == nullptr)
            return;

        newTree->random = map[root]->random;
        copyRandomNodes(root->left, newTree->left, map);
        copyRandomNodes(root->right, newTree->right, map);

    }



    Node* cloneTree(Node* root)
    {
        std::unordered_map<Node*, Node*> map;
        auto* newTree = copyLeftRightTrees(root, map);
        copyRandomNodes(root, newTree, map);
        return newTree;
    }

    Node* cloneTree(Node* root)
    {
        std::unordered_map<Node*, Node*> map;
        auto* newTree = copyLeftRightTrees(root, map);
        copyRandomNodes(root, newTree, map);
        return newTree;
    }

    Node* LCA(Node* root, int n1, int n2)
    {
        if (!root)
            return nullptr;
        if (root->data > n1 && root->data > n2)
            return LCA(root->left, n1, n2);
        if (root->data < n1 && root->data < n2)
            return LCA(root->right, n1, n2);

        return root;
        //Your code here
    }

    void mirror(Node* node)
    {
        if (node == nullptr)
            return;

        else
        {
            mirror(node->left);
            mirror(node->right);

            Node* temp;
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }

    void connect(struct Node* root)
    {
        queue<Node*> q;
        q.push(root);

        q.push(NULL);

        while (!q.empty()) {
            Node* p = q.front();
            q.pop();
            if (p != NULL) {

                p->nextRight = q.front();

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }

            // if queue is not empty, push NULL to mark
            // nodes at this level are visited
            else if (!q.empty())
                q.push(NULL);
        }
    }


    Node* minValueNode(Node* root)
    {
        auto* currentNode = root;

        while (currentNode && currentNode->left)
            currentNode = currentNode->left;

        return currentNode;
    }

    Node* deleteNode(Node* root, int x)
    {
        if (!root)
            return root;

        if (x < root->data)
            root->left = deleteNode(root->left, x);
        else if (x > root->data)
            root->right = deleteNode(root->right, x);
        else
        {
            if (!root->right)
            {
                auto* temp = root->left;
                root = nullptr;
                return temp;
            }

            else if (!root->left)
            {
                auto* temp = root->right;
                root = nullptr;
                return temp;
            }

            auto* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
        // your code goes here
    }

    BalancedStatus isBalancedUtil(Node* root)
    {
        if (!root)
            return { true, -1 };

        auto l = isBalancedUtil(root->left);

        if (!l.balanced)
            return { false, 1 };

        auto r = isBalancedUtil(root->right);

        if (!r.balanced)
            return { false, 1 };

        auto isBalanced = abs(l.height - r.height) <= 1;
        auto height = max(l.height, r.height) + 1;
        return { isBalanced, height };
    }


    bool isBalanced(Node* root)
    {
        return isBalancedUtil(root).balanced;
    }
	
}



#endif //BACKTRACKING_BSTALGORITHMS_H
