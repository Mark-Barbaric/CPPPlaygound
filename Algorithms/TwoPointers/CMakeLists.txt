project(TwoPointers)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES include/MediumTwoPointer.h)
add_library(TwoPointerAlgorithms SHARED ${SOURCES})
target_include_directories(TwoPointerAlgorithms PUBLIC include)
set_target_properties(TwoPointerAlgorithms PROPERTIES LINKER_LANGUAGE CXX)