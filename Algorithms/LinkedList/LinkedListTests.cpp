#include <gtest/gtest.h>
#include "LinkedListAlgorithms.h"

namespace LinkedListAlgorithms{

    Node* createNodeFromArray(std::vector<int>& nums){
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

    TEST(LinkedListAlgorithms, RemoveEvenTests){

    }
}