project(condition_variable)
set(CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread)
cmake_minimum_required(VERSION 3.16)

add_executable("multithreaded_calcs" multithreaded_calcs.cpp)

add_subdirectory(ConditionVariable)