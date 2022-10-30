cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(BacktrackingAlgorithms)

add_definitions(-DUSE_TIMER)

set(SOURCES NumTiles.h QueensProblem.h Sudoku.h TowersOfHanoi.h)
add_library(BacktrackingAlgorithms STATIC ${SOURCES})
set_target_properties(BacktrackingAlgorithms PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(BacktrackingAlgorithms PRIVATE ${CMAKE_BINARY_DIR}/lib)
target_link_libraries(BacktrackingAlgorithms
        Profiling)
