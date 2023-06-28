#include <Node.h>
#include <TraversalAlgorithms.h>
#include <gtest/gtest.h>

namespace Algorithms::Tree{

    Node<int>* getRootNode() {
        auto root = new Node<int>(12);
        root->left = new Node<int>(3);
        root->right = new Node<int>(5);
        root->left->left = new Node<int>(7);
        return root;
    }
    
    TEST(TreeAlgorithmTests, TraversalAlgorithmTests)
    {
        const auto* rootNode = getRootNode();
        const auto inorderResult = InorderTraversalRecursive(rootNode);
        EXPECT_EQ(inorderResult, "7,5,3,12");
    }
}