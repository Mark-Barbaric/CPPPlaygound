cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(GraphAlgorithms)

set(SOURCES CycleAlgorithms.h MSTAlgorithms.h ShortestPathAlgorithms.h UnionFind.h)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(GraphAlgorithmTests.cpp GraphAlgorithmTests.cpp ${SOURCES})
target_link_libraries(GraphAlgorithmTests.cpp CONAN_PKG::gtest)