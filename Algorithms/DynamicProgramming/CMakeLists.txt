project(DynamicProgramming)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES EasyDPAlgos.h Knapsack.h NumCombinations.h PalindromeDP.h)
set(TEST_SOURCES EasyDPTests.cpp MediumDPTests.cpp)

add_executable(DPTests
        ${TEST_SOURCES}
        ${SOURCES})

target_link_libraries(CONAN_PKG::gtest)