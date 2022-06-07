#include <gtest/gtest.h>
#include "Fibonacci.h"

namespace Algorithms::Recursion{

    TEST(RecursionTests, FibonacciTests){
        std::vector<int> nums (30, -1);
        const auto fibo1 = fibonacciMemoization(20);
        ASSERT_EQ(fibo1, 10946);
        const auto fibo2 = fibonacciIterative(20);
        ASSERT_EQ(fibo2, 10946);
    }
}