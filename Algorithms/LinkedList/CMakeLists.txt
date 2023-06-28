cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(LinkedListAlgorithms)

set(SOURCES LinkedListAlgorithms.h)

set(TEST_SOURCES LinkedListTests.cpp)
add_executable(LinkedListAlgorithmTests
        ${SOURCES}
        ${TEST_SOURCES})

target_link_libraries(LinkedListAlgorithmTests
        CONAN_PKG::gtest)