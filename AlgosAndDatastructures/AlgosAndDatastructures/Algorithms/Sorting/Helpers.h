//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>

namespace Helpers
{
    template<typename Container>
    void printVector(Container& vec)
    {
        std::cout << "Vector Elements: ";

        for(size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << ", ";

        std::cout << '\n';
    }
    template<typename Type, size_t N>
    void printVector(Type (&vec)[N])
    {
        std::cout << "Vector Elements: ";

        for(size_t i = 0; i < N; ++i)
            std::cout << vec[i] << ", ";

        std::cout << '\n';
    }


}

#endif //SORTING_HELPERS_H
