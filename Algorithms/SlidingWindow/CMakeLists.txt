project(SlidingWindowAlgorithms)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

add_library(SlidingWindowAlgorithms include/EasySlidingWindow.h include/MediumSlidingWindow.h include/HardSlidingWindow.h)
target_include_directories(SlidingWindowAlgorithms PUBLIC include)
set_target_properties(SlidingWindowAlgorithms PROPERTIES LINKER_LANGUAGE CXX)
