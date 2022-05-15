#ifndef BST_ALGORITHMS_H
#define BST_ALGORITHMS_H

#include "include/Header.h"
#include "../../DataStructures/Trees/BinarySearchTree.h"

namespace BSTAlgorithms
{
	inline std::string nodeKeys(Node<int>* root, std::vector<std::string>& keys)
	{
		if(!root)
		{
			return "";
		}
		
		auto leftKey = nodeKeys(root->left, keys);
		auto rightKey = nodeKeys(root->right, keys);

		auto curKey = std::to_string(root->val) + leftKey + rightKey;
		keys.push_back(curKey);
		
		return curKey;
	}
}



#endif