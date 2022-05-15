cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(GraphAlgorithms)

add_library(GraphAlgorithms CycleAlgorithms.h MSTAlgorithms.h ShortestPathAlgorithms.h UnionFind.h)