cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(Backtracking)

add_executable(Backtracking main.cpp QueensProblem.h ../../include/catch.hpp BacktrackingTests.cpp)
