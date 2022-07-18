#pragma once
#include <chrono>
#include "../include/Header.h"

#if USE_TIMER
#define MEASURE_FUNCTION() Profiling::ScopedTimer timer {__func__}
#else
#define MEASURE_FUNCTION()
#endif

namespace Profiling{
    class ScopedTimer{

        using ClockType = std::chrono::steady_clock;
        const char* m_functionName{};
        const ClockType::time_point m_startPoint;

    public:


        explicit ScopedTimer(const char* func)
        :m_functionName(func),
        m_startPoint(ClockType::now())
        {

        }

        ~ScopedTimer(){
            using namespace std::chrono;
            auto stop = ClockType::now();
            auto duration = (stop - m_startPoint);
            const auto ms = duration_cast<microseconds>(duration).count();
            std::cout  << ms << " microseconds " << m_functionName << "\n";
        }

        ScopedTimer(const ScopedTimer&) = delete;
        ScopedTimer(const ScopedTimer&&) = delete;
        ScopedTimer& operator=(const ScopedTimer&) = delete;
        ScopedTimer& operator=(const ScopedTimer&&) = delete;

    };
}