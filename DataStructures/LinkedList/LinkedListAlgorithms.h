//
// Created by Mark Barbaric on 27/10/2019.
//

#ifndef LINKEDLISTALGORITHMS_H
#define LINKEDLISTALGORITHMS_H

struct LinkedList {
    int val;
    LinkedList* next;
    LinkedList() : val(0), next(nullptr) {}
    LinkedList(int x) : val(x), next(nullptr) {}
    LinkedList(int x, LinkedList* next) : val(x), next(next) {}
};

namespace LinkedListAlgorithms
{
    LinkedList* deleteNode(LinkedList* l, const int val)
    {
        auto* head = l;
        auto* prev = l;
        auto* node = l->next;

        if (head->val == val)
        {
            head = head->next;
            return head;
        }

    	while(node)
    	{
    		if(node->val == val)
    		{
                prev->next = node->next;
                break;
    		}

            prev = node;
            node = node->next;
    	}

        return head;    	
    }

    LinkedList* reverseLinkedList(LinkedList* l)
    {
        auto* cur = l;
        LinkedList* prev = nullptr;
        LinkedList* next = nullptr;

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

        cur = prev;    	
        return cur;
    }
	
    LinkedList* addTwoNumbers(LinkedList* l1, LinkedList* l2) {

        auto* dummyHead = new LinkedList(0);
        auto* cur = dummyHead;
        auto remainder = 0;

        while (l1 || l2)
        {
            auto x1 = l1 ? l1->val : 0;
            auto x2 = l2 ? l2->val : 0;

            auto sum = remainder + x1 + x2;
            remainder = sum / 10;
            sum %= 10;

            auto* newNode = new LinkedList(sum);
            cur->next = newNode;
            cur = cur->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (remainder)
            cur->next = new LinkedList(remainder);

        return dummyHead->next;
    }

	LinkedList* addTwoNumbersTwo(LinkedList* l1, LinkedList* l2)
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

        LinkedList* head = new LinkedList(arr3[arr3.size() - 1]);
        LinkedList* dummy = head;

    	for(int i = arr3.size() - 2; i >= 0; --i)
    	{
            LinkedList* node = new LinkedList(arr3[i]);
            dummy->next = node;
            dummy = dummy->next;
    	}

        return head;    	
    }
}

#endif //BACKTRACKING_LINKEDLISTALGORITHMS_H
