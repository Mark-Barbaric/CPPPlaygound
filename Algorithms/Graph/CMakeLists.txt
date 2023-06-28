
project(GraphAlgorithms)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES CycleAlgorithms.h MSTAlgorithms.h ShortestPathAlgorithms.h UnionFind.h)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
