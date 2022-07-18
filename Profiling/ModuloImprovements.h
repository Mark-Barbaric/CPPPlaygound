#pragma once
#include "../include/Header.h"
#include "ScopedTimer.h"

namespace Profiling{

    constexpr int bufferSize = 1024;
    constexpr int value = 1301081;

    inline void runStandardModulus(){

        MEASURE_FUNCTION();

        int remainder;
        int i = 0;
        while (i < 10000000) {
            remainder = value % bufferSize;
            i++;
        }
    }

    inline void runBitwiseModulus(){

        MEASURE_FUNCTION();

        int remainder;
        int divisor = bufferSize - 1;
        int i = 0;
        while (i < 10000000) {
            remainder = (value& divisor);
            i++;
        }
    }
}