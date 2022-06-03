project(BinarySearch)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES BinarySearch.h)

set(TEST_SOURCES BinarySearchTests.cpp)

add_executable(BinarySearchTests ${SOURCES}
        ${TEST_SOURCES})
target_link_libraries(BinarySearchTests
        CONAN_PKG::gtest)