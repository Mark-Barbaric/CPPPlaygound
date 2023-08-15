#pragma once
#include <Profiling/ScopedTimer.h>

namespace Algorithms::Recursion{

    int fibonacciMemoizationUtil(int n, std::vector<int>& memo){
        if(n <= 1){
            memo[n] = 1;
        }

        if(memo[n] != -1){
            return memo[n];
        }

        memo[n] = fibonacciMemoizationUtil(n - 1, memo) + fibonacciMemoizationUtil(n - 2, memo);
        return memo[n];
    }

    int fibonacciMemoization(int n){
        MEASURE_FUNCTION();
        std::vector<int> nums(n + 1, -1);
        return fibonacciMemoizationUtil(n, nums);
    }

    int fibonacciIterative(int n){
        MEASURE_FUNCTION();
        int a = 1, b = 1;

        for(int i = 2; i <= n; ++i){
            const auto lastA = a;
            a += b;
            b = lastA;
        }

        return a;
    }
}