project(Graph)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES include/Graph.h)
add_library(Graph ${SOURCES})
target_include_directories(Graph PUBLIC include)
set_target_properties(Graph PROPERTIES LINKER_LANGUAGE CXX)
