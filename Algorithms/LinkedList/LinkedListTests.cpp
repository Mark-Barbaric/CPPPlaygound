#include <gtest/gtest.h>
#include "LinkedListAlgorithms.h"

namespace LinkedListAlgorithms{

    Node* createNodeFromArray(std::vector<int> nums){
        if(nums.empty()){
            return nullptr;
        }

        Node* root = new Node(nums[0]), *cur = root;

        for(int i = 1; i < nums.size(); ++i){
            cur->next = new Node(nums[i]);
            cur = cur->next;
        }

        return root;
    }

    std::vector<int> createArrayFromNode(Node* root){
        std::vector<int> ans;

        while(root){
            ans.push_back(root->val);
            root = root->next;
        }
        return ans;
    }

    TEST(LinkedListAlgorithms, RemoveEvenTests){
        auto* node = createNodeFromArray({1,2,3,4});
        auto* oddNode = LinkedListAlgorithms::removeEvenNode(&node);
        std::vector<int> expectedAns1 = {1,3};
        ASSERT_EQ(createArrayFromNode(oddNode), expectedAns1);

        auto* node2 = createNodeFromArray({2,2,2,2,3,4,4,5});
        auto* oddNode2 = LinkedListAlgorithms::removeEvenNode(&node2);
        std::vector<int> expectedAns2 = {3,5};
        ASSERT_EQ(createArrayFromNode(oddNode2), expectedAns2);

        auto* node3 = createNodeFromArray({1,1,1,2,2,2,5,6,7,8});
        auto* oddNode3 = LinkedListAlgorithms::removeEvenNode(&node3);
        std::vector<int> expectedAns3 = {1,1,1,5,7};
        ASSERT_EQ(createArrayFromNode(oddNode3), expectedAns3);
    }
}