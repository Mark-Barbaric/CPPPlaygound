project(Profiling)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUSE_TIMER)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_library(Profiling STATIC ScopedTimer.h)

set(SOURCES ../Profiling/main.cpp ../Profiling/ScopedTimer.h ../Profiling/ModuloImprovements.h ../Profiling/MicroBenchmarkTest.h)
add_executable(ProfilingPractice ${SOURCES})
target_link_libraries(ProfilingPractice
        CONAN_PKG::gtest)
