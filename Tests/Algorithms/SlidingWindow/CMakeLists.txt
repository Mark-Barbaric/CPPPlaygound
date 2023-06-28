cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(SlidingWindowTests)

set(TEST_SOURCES EasySlidingWindowTests.cpp MediumSlidingWindowTests.cpp HardSlidingWindowTests.cpp)
add_executable(SlidingWindowTests ${TEST_SOURCES})
add_test(NAME AlgorithmTests COMMAND SlidingWindowTests)

#include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Algorithms/SlidingWindow/include)
target_link_libraries(SlidingWindowTests
        SlidingWindowAlgorithms
        CONAN_PKG::gtest)