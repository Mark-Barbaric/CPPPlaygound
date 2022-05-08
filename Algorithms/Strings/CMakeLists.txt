cmake_minimum_required(VERSION 3.16)
project(StringTests)
set(CMAKE_CXX_STANDARD 20)

add_executable(StringTests MultiplyStrings.h ../Tests/StringTests.cpp ${CMAKE_SOURCE_DIR}/catch.hpp)