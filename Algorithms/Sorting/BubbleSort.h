//
// Created by Mark Barbaric on 27/09/2019.
//

#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

template<typename Type>
class BubbleSort
{
public:
    BubbleSort() = default;

    void sort(std::vector<Type>& vec)
    {
        //with flag Bubble Sort is adaptive
        auto count = 0;
        for(int i = 0; i < vec.size() - 1; ++i)
        {
            auto flag = false;
            for(int j = 0; j < vec.size() - 1 - i; ++j)
            {
                if(vec[j] > vec[j + 1])
                {
                    std::swap(vec[j], vec[j + 1]);
                    flag = true;
                    count++;
                }
            }
            if(!flag)
            {
                break;
            }
        }

    }


};

#endif //SORTING_BUBBLESORT_H
