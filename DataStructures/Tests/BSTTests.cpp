#include "../../catch.hpp"
#include "../BST/BinarySearchTree.h"
#include "../BST/BasicBSTAlgorithms.h"

TEST_CASE("BST Basic Tests")
{
	Node<int>* root = new Node<int>(1);

	root->left = new Node<int>(2);
	root->right = new Node<int>(3);
	root->left->left = new Node<int>(4);
	root->left->right = new Node<int>(5);

	
	SECTION("Height Tests")
	{
		REQUIRE(BASIC_BST_ALGORITHMS::height(root) == 3);
	}

	SECTION("Sum Tests")
	{
		REQUIRE(BASIC_BST_ALGORITHMS::sum(root) == 15);
	}
}