cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(Backtracking)

set(TESTSOURCES CircularQueue.h CircularQueueTests.cpp ${CMAKE_SOURCE_DIR}/include/catch.hpp)
add_executable(CircularQueueTests ${TESTSOURCES})
