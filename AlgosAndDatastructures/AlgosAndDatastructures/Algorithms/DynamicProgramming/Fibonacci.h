//
// Created by Mark Barbaric on 23/09/2019.
//

#ifndef DYNAMIC_PROGRAMMING_FIBONACCI_H
#define DYNAMIC_PROGRAMMING_FIBONACCI_H
#include <iostream>
#include <vector>

class Fibonacci
{
    std::vector<int> memorizeTable;

public:
    Fibonacci();
    int fibonacciMemorize(int n);
    int nativeFibonacci(int n);
    int iterationFibonacci(const int n);
};
#endif //DYNAMIC_PROGRAMMING_FIBONACCI_H
