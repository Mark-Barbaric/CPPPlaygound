#include "../../catch.hpp"
#include "../BST/BinarySearchTree.h"

TEST_CASE("BST Basic Tests")
{
	Node<int>* root = new Node<int>(1);
	root->left = new Node<int>(2);
	root->right = new Node<int>(3);
	root->left->left = new Node<int>(4);
	root->left->right = new Node<int>(5);

	SECTION("Traversal Tests")
	{
		const auto preOrderString = BasicBSTAlgorithms::Traverse(root, BasicBSTAlgorithms::TraversalType::Preorder);
		REQUIRE(preOrderString == "12453");
		const auto inOrderString = BasicBSTAlgorithms::Traverse(root, BasicBSTAlgorithms::TraversalType::Inorder);
		REQUIRE(inOrderString == "42513");
		const auto postOrderString = BasicBSTAlgorithms::Traverse(root, BasicBSTAlgorithms::TraversalType::Postorder);
		REQUIRE(postOrderString == "45231");
	}

	SECTION("Sum and Height Tests")
	{
		REQUIRE(BasicBSTAlgorithms::MaxMinHeight(root, true) == 3);
		REQUIRE(BasicBSTAlgorithms::MaxMinHeight(root, false) == 2);
		REQUIRE(BasicBSTAlgorithms::Sum(root) == 15);
	}
}