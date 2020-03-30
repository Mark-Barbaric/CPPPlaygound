//
// Created by Mark Barbaric on 04/09/2019.
//

#ifndef BINARYSEARCH_ALGORITHSM_H
#define BINARYSEARCH_ALGORITHSM_H

template<typename Arr, typename T>
void sortArr(Arr arr[], T size)
{
    for(auto i = 0; i < size; ++i)
    {
        for(auto k = i + 1; k < size; ++k)
        {
            auto val = arr[k];

            if(arr[i] > val)
            {
                arr[k] = arr[i];
                arr[i] = val;
            }
        }
    }
}

template<typename Arr, typename T>
T findPivot(Arr arr[], T low, T high)
{
    // base cases
    if (high < low) return -1;
    if (high == low) return low;

    const auto mid = (low + high)/2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;

    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid-1);

    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid-1);

    return findPivot(arr, mid + 1, high);
}

#endif //BINARYSEARCH_ALGORITHSM_H
