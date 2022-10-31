cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_definitions(-DUSE_TIMER)

enable_testing()

set(TEST_SOURCES TrappingWaterTests.cpp ThreeSumTests.cpp)
add_executable(ArrayAlgorithmTests ${TEST_SOURCES})
add_test(NAME AlgorithmTests COMMAND ArrayAlgorithmTests)

target_link_libraries(ArrayAlgorithmTests
        ArrayAlgorithms
        CONAN_PKG::gtest)