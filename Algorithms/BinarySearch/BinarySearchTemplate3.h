#pragma once
#include <Profiling/ScopedTimer.h>

namespace Algorithms::BinarySearch{

    double myPowBinarySearch(double x, int n){
        MEASURE_FUNCTION();
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long long i = N; i ; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }

    double myPowLinear(double x, int n){
        MEASURE_FUNCTION();

        bool isOddPower = std::abs(n) % 2;
        bool isInversePower = n < 0;

        n = std::abs(n) / 2;

        auto basePower = 1.0;

        while(n > 0){
            basePower *= x;
            n--;
        }

        basePower*= basePower;

        if(isOddPower){
            basePower*=x;
        }

        if(isInversePower){
            basePower = 1.0 / basePower;
        }

        return basePower;
    }
}