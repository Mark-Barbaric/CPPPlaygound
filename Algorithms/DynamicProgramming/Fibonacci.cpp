//
// Created by Mark Barbaric on 23/09/2019.
//

#include "Fibonacci.h"
Fibonacci::Fibonacci()
{
    memorizeTable.resize(100);
    memorizeTable[0] = 0;
    memorizeTable[1] = 1;
}

//head recursion
int Fibonacci::fibonacciMemorize(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    if(memorizeTable[n] != 0){
        return memorizeTable[n];
    }

    else{

        memorizeTable[n] = fibonacciMemorize(n - 1) + fibonacciMemorize(n - 2);
        return memorizeTable[n];
    }
}

int Fibonacci::nativeFibonacci(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return nativeFibonacci(n - 1) + nativeFibonacci(n - 2);
}

int Fibonacci::iterationFibonacci(const int n)
{
	const auto size = n + 1;
    int** f = new int*[size];
    int i;
    *f[0] = 0, *f[1] = 1;

    for(i = 2; i <= n; i++)
        *f[i] = *f[i-1] + *f[i-2];
	const auto res = *f[n];
	delete[] f;
    return res;
}