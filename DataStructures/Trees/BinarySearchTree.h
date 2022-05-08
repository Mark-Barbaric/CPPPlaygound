//
// Created by Mark Barbaric on 01/11/2019.
//

#pragma once

#include "../../Header.h"

template<typename Type>
struct Node
{
    Node(const Type& d)
        :val(d)
    {

    }

    Type val;
    Node* left = nullptr;
    Node* right = nullptr;
};

template<typename Type>
class BinarySearchTree
{
    Node<Type>* root{ nullptr };

	std::string inorderTraversalUtil(Node<Type>* root) const
	{
		if (!root)
		{
			return "";
		}

		auto left = inorderTraversalUtil(root->left);

		if (!left.empty())
		{
			left += ' ';
		}

		auto r = std::to_string(root->val);

		auto right = inorderTraversalUtil(root->right);

		if (!right.empty())
			r += ' ';
		
		return left + r + right;
	}

	Node<Type>* insertNodeUtil(Node<Type>* root, Type val)
	{
		if(!root)
		{
			return new Node<Type>(val);
		}

		if(val < root->val)
		{
			root->left = insertNodeUtil(root->left, val);
		} else
		{
			root->right = insertNodeUtil(root->right, val);
		}

		return root;
	}

	Node<Type>* inorderSuccessorUtil(Node<Type>* root)
	{
		while(root && root->left)
		{
			root = root->left;
		}

		return root;
	}

	Node<Type>* deleteNodeUtil(Node<Type>* root, Type val)
	{
		if(!root)
		{
			return nullptr;
		}

		if(val < root->val)
		{
			root->left = deleteNodeUtil(root->left, val);
		} else if(val > root->val)
		{
			root->right = deleteNodeUtil(root->right, val);
		} else
		{
			//leaf
			if (!root->left && !root->right)
			{
				root = nullptr;
			}


			//left child
			else if (!root->right && root->left)
			{
				root = root->left;
			}


			//right child
			else if (!root->left && root->right)
			{
				root = root->right;
			}

			//two children
			else if(root->left && root->right)
			{
				auto* successor = inorderSuccessorUtil(root->right);
				deleteNode(successor->val);
				root->val = successor->val;
			}
		}

		return root;
	}

	Node<Type>* findNodeUtil(Node<Type>* root, Type val)
	{
		if(!root)
		{
			return root;
		}

		if(val < root->val)
		{
			return findNodeUtil(root->left, val);
		}
		else if(val > root->val)
		{
			return findNodeUtil(root->right, val);
		}

		return root;
	}
	
public:

	BinarySearchTree() = default;

	std::string inorderTraversal() const { return inorderTraversalUtil(root); }
	
	void insertNode(Type val)
	{
		root = insertNodeUtil(root, val);
	}

	void deleteNode(Type val)
	{
		root = deleteNodeUtil(root, val);
	}

	Node<Type>* findNode(Type val)
	{
		return findNodeUtil(root, val);
	}

	Node<Type>* getRoot() { return root; }
};


#endif

