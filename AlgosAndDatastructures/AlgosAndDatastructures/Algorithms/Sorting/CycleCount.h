//
// Created by Mark Barbaric on 05/10/2019.
//

#ifndef SORTING_CYCLECOUNT_H
#define SORTING_CYCLECOUNT_H

#include <vector>
#include <algorithm>
#include <map>

template<typename Type>
class CycleCount
{
public:
    CycleCount() = default;

    int minSwaps(std::vector<Type> vec)
    {
        auto n = vec.size();
        std::pair<int,int> p [n];
        std::vector<bool> visited (n, false);

        for(int i = 0; i < n; ++i)
        {
            p[i].first = vec[i];
            p[i].second = i;
        }

        auto ans = 0;
        std::sort(p, p + n);

        for(int i = 0; i < n; ++i)
        {
            if(visited[i] || p[i].second == i)
                continue;

            auto cycle_size = 0;
            auto j = i;

            while(!visited[j])
            {
                visited[j] = true;
                j = p[j].second;
                cycle_size++;
            }

            ans += cycle_size - 1;
        }
        return ans;
    }

};

#endif //SORTING_CYCLECOUNT_H
