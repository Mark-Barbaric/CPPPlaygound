cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(BacktrackingTests)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

enable_testing()
add_test(NAME BacktrackingTests COMMAND BacktrackingTests)

add_executable(BacktrackingTests main.cpp QueensProblem.h NumTiles.h BacktrackingTests.cpp)
target_link_libraries(BacktrackingTests
        CONAN_PKG::gtest)
