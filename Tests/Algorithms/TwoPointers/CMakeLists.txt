project(TwoPointerTests)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(TEST_SOURCES MediumTwoPointerTests)
add_executable(TwoPointerTests ${TEST_SOURCES})

target_link_libraries(TwoPointerTests
CONAN_PKG::gtest
TwoPointerAlgorithms)