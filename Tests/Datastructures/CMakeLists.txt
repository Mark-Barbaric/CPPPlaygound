cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(Backtracking)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(BSTSOURCES BSTTests.cpp)
add_executable(BSTTests ${BSTSOURCES})

target_include_directories(BSTTests PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(BSTTests
BinarySearchTree
CONAN_PKG::gtest)



set(TESTSOURCES CircularQueueTests.cpp ${CMAKE_SOURCE_DIR}/include/catch.hpp)
add_executable(CircularQueueTests ${TESTSOURCES})

#target_include_directories(CircularQueueTests PUBLIC
 #       ${CMAKE_BINARY_DIR}/lib)
target_link_libraries(CircularQueueTests
        Datastructures)