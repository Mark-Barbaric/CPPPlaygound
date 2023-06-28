#include <Node.h>
#include <gtest/gtest.h>

namespace Datastructures::Tree{

    TEST(NodeTests, BasicFunctionalityTests)
    {
        Node<int>* root = new Node<int>(12);
        root->left = new Node<int>(5);
        root->right = new Node<int>(4);
        EXPECT_EQ(root->val, 12);
        EXPECT_EQ(root->left->val, 5);
        EXPECT_EQ(root->right->val, 4);
    }

}