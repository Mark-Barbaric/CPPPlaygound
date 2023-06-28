project(Recursion)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD  20)

add_definitions(-DUSE_TIMER)

set(SOURCES Fibonacci.h)
set(TEST_SOURCES FibonacciTests.cpp)

add_executable(RecursionTests ${SOURCES}
        ${TEST_SOURCES})

target_link_libraries(RecursionTests
        CONAN_PKG::gtest)