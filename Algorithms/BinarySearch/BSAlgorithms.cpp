//
// Created by Mark Barbaric on 04/09/2019.
//

#ifndef BINARYSEARCH_SEARCHALGORITHMS_H
#define BINARYSEARCH_SEARCHALGORITHMS_H

#include "BinarySearchHelpers.h"

template<typename T, typename T2>
T2 recursiveBinarySearch(T arr[], T2 l, T2 r, T v)
{
    if(r >= l){
        auto mid = l + (r - l) / 2;

        if(arr[mid] == v)
            return mid;

        //right half
        if(v > arr[mid])
            return recursiveBinarySearch(arr, mid + 1, r, v);

        //left half
        return recursiveBinarySearch(arr, l, mid - 1, v);
    }

    return -1;
}

template<typename T, typename T2>
T2 pivotedRecursiveBinarySearch(T arr[], T2 l, T2 r, T v)
{
    auto pivot = findPivot(arr, l, r);

    if(pivot == -1)
        return recursiveBinarySearch(arr, l, r, v);

    if(arr[pivot] == v)
        return pivot;

    if(arr[0] <=v)
        return recursiveBinarySearch(arr, l, pivot - 1, v);

    return recursiveBinarySearch(arr, pivot + 1, r, v);

}

#endif //BINARYSEARCH_SEARCHALGORITHMS_H
