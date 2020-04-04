//
// Created by Mark Barbaric on 27/10/2019.
//

#ifndef BACKTRACKING_HELPERS_H
#define BACKTRACKING_HELPERS_H

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

#endif //BACKTRACKING_HELPERS_H
