project(Profiling)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUSE_TIMER)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES main.cpp ScopedTimer.h ModuloImprovements.h MicroBenchmarkTest.h PreVsPostCrement.h)
add_executable(Profiling ${SOURCES})
target_link_libraries(Profiling
        CONAN_PKG::gtest)
