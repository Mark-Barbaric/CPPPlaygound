project(Profiling)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUSE_TIMER)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(POKER_HAND_SOURCES PokerHandAnalyzer.h PokerHandBase.h OptimizedPokerHandAnalyzer.h)

set(SOURCES main.cpp ScopedTimer.h ModuloImprovements.h MicroBenchmarkTest.h)
add_executable(Profiling ${SOURCES} ${POKER_HAND_SOURCES})
target_link_libraries(Profiling
        CONAN_PKG::benchmark)

set(TEST_SOURCES PokerHandAnalyzerTests.cpp)
add_executable(PokerHandAnalyzerTests ${TEST_SOURCES} ${POKER_HAND_SOURCES})
target_link_libraries(PokerHandAnalyzerTests
        CONAN_PKG::gtest)