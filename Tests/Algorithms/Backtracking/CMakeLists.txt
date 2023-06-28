cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(BacktrackingTests)

add_definitions(-DUSE_TIMER)

set(TEST_SOURCES BacktrackingTests.cpp)
add_executable(BacktrackingTests ${TEST_SOURCES})
add_test(NAME AlgorithmTests COMMAND BacktrackingTests)

target_include_directories(BacktrackingTests PUBLIC ${CMAKE_BINARY_DIR}/lib)
target_link_libraries(BacktrackingTests
        BacktrackingAlgorithms
        CONAN_PKG::gtest)

