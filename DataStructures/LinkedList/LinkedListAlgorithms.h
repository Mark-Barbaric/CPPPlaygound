//
// Created by Mark Barbaric on 27/10/2019.
//

#ifndef BACKTRACKING_LINKEDLISTALGORITHMS_H
#define BACKTRACKING_LINKEDLISTALGORITHMS_H

#include "LinkedList.h"q

template<typename ListType>
ListType* addTwoNumbers(ListType* l1, ListType* l2) {

    auto* dummyHead = new ListType(0);
    auto* cur = dummyHead;
    auto carry = 0;

    while(l1 || l2)
    {
        auto x1 = l1 ? l1->val : 0;
        auto x2 = l2 ? l2->val : 0;

        auto sum = carry + x1 + x2;
        carry = sum / 10;

        auto* newNode = new ListType(sum % 10);
        cur->next = newNode;
        cur = cur->next;

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }

    if(carry)
        cur->next = new ListType(carry);

    return dummyHead->next;

}

#endif //BACKTRACKING_LINKEDLISTALGORITHMS_H
