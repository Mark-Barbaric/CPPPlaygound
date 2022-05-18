project(StringAlgorithms)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
add_definitions(-DUSE_TIMER)

set(SOURCES MultiplyStrings.h ReverseWordsInAString.h)

enable_testing()
add_test(NAME StringAlgorithms COMMAND StringAlgorithms)

set(TEST_SOURCES StringTests.cpp)
add_executable(StringAlgorithmTests ${SOURCES} ${TEST_SOURCES})

target_link_libraries(StringAlgorithmTests
        CONAN_PKG::gtest)