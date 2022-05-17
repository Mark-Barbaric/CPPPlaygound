cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(BacktrackingTests)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_definitions(-DUSE_TIMER)
add_test(NAME BacktrackingTests COMMAND BacktrackingTests)

add_executable(BacktrackingTests QueensProblem.h NumTiles.h BacktrackingTests.cpp)
target_link_libraries(BacktrackingTests
        CONAN_PKG::gtest)
