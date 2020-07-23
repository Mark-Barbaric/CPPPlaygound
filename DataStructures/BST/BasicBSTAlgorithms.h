#ifndef BASIC_BST_ALGORITHMS_H
#define BASIC_BST_ALGORITHMS_H

#include "BinarySearchTree.h"

namespace BASIC_BST_ALGORITHMS
{
	enum TraversalType
	{
		Pre = 0, InOrder, Post
	};
	
	template<typename Data>
	void traverse(Node<Data>* root, TraversalType type, std::vector<int>& vec)
	{
		if (!root)
			return;

		else
		{
			if (type == Pre)
				vec.push_back(root->data);
			
			traverse(root->left);

			if (type == InOrder)
				vec.push_back(root->data);

			traverse(root->right);

			if (type == Post)
				vec.push_back(root->data);
			
		}
		
	}


	
	template<typename Data>
	int sum(Node<Data>* node)
	{
		if (!node)
		{
			return 0;
		}
		else
		{
			const auto bstSum = sum(node->left) + sum(node->right) + node->data;
			return bstSum;
		}
	}

	
	template<typename Data>
	int height(Node<Data>* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		else
		{
			const auto l = height(node->left);
			const auto r = height(node->right);
			return std::max(l + 1, r + 1);
		}
	}

	
}



#endif
