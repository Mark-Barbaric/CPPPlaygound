//
// Created by Mark Barbaric on 27/10/2019.
//

#ifndef BACKTRACKING_LINKEDLISTALGORITHMS_H
#define BACKTRACKING_LINKEDLISTALGORITHMS_H

#include "LinkedList.h"

namespace LinkedListAlgorithms
{
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
}

#endif //BACKTRACKING_LINKEDLISTALGORITHMS_H
