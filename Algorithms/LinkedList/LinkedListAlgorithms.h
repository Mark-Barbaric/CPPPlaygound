//
// Created by Mark Barbaric on 27/10/2019.
//

#pragma once
#include "../../DataStructures/LinkedList.h"

namespace LinkedListAlgorithms
{
    struct Node{

        explicit Node(int v):val(v){

        }

        int val;
        Node* next {nullptr};
    };

    Node* removeEvenNode(Node** root){
        Node* cur = *root, *prev = nullptr;

        // iterate till first node is odd
        while(cur && cur->val % 2 == 0){
            prev = cur;
            cur = cur->next;
            *root = cur;
        }

        while(cur){
            if(cur->val % 2 == 0){
                prev->next = cur->next;
            } else {
                prev = cur;
            }

            cur = cur->next;
        }

        return *root;
    }

    ListNode<int>* containsCycle(ListNode<int>* root)
    {
        ListNode<int>* slow = root, * fast = root;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        	
            if (slow == fast)
                return slow;
        }

        return nullptr;
    }
	
    ListNode<int>* findCycleIntersection(ListNode<int>* head)
    {
        auto* intersection = containsCycle(head);

        if (!intersection || !head)
            return nullptr;
    	
        auto* ptr1 = head, * ptr2 = intersection;
    	while(ptr2 != ptr1)
    	{
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
    	}

        return ptr1;
    }
	
    std::string traverseNodesUtil(ListNode<int>* head)
    {
        std::string ans = "";

        while (head)
        {
            if (!ans.empty())
            {
                ans += ' ';
            }

            ans += std::to_string(head->val);
            head = head->next;
        }

        return ans;
    }
	
    ListNode<int>* reverseLinkedList(ListNode<int>* l)
    {
        ListNode<int>* cur = l, *prev = nullptr, *next = nullptr;

        while(cur)
        {
        	//store next pointer
            next = cur->next;

        	//swap next with previous
            cur->next = prev;

            //iterate prev pointer
            prev = cur;
        	//iterate next with stored next pointer
            cur = next;
        }
   	
        return prev;
    }
	
    ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {

        auto* dummyHead = new ListNode<int>(0);
        auto* cur = dummyHead;
        auto remainder = 0;

        while (l1 || l2)
        {
            auto x1 = l1 ? l1->val : 0;
            auto x2 = l2 ? l2->val : 0;

            auto sum = remainder + x1 + x2;
            remainder = sum / 10;
            sum %= 10;

            auto* newNode = new ListNode<int>(sum);
            cur->next = newNode;
            cur = cur->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (remainder)
            cur->next = new ListNode<int>(remainder);

        return dummyHead->next;
    }

	ListNode<int>* addTwoNumbersTwo(ListNode<int>* l1, ListNode<int>* l2)
    {
        std::vector<int> arr1, arr2, arr3;

    	while(l1 || l2)
    	{
            const auto x1 = l1 ? l1->val : 0;
            const auto x2 = l2 ? l2->val : 0;

            if (l1)
            {
                arr1.push_back(x1);
                l1 = l1->next;
            }
            if (l2)
            {

                arr2.push_back(x2);
                l2 = l2->next;
            }  		
    	}

        int i = arr1.size() - 1, j = arr2.size() - 1, remainder = 0;

    	while(i>=0 || j >=0)
    	{
            const auto l1 = i >= 0 ? arr1[i] : 0;
            const auto l2 = j >= 0 ? arr2[j] : 0;

            auto sum = l1 + l2 + remainder;
            remainder = sum / 10;
            sum %= 10;

            arr3.push_back(sum);
    		
            i--;
            j--;
    	}

        ListNode<int>* head = new ListNode<int>(arr3[arr3.size() - 1]);
        ListNode<int>* dummy = head;

    	for(int i = arr3.size() - 2; i >= 0; --i)
    	{
            ListNode<int>* node = new ListNode<int>(arr3[i]);
            dummy->next = node;
            dummy = dummy->next;
    	}

        return head;    	
    }
}