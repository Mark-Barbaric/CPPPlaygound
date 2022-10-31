cmake_minimum_required(VERSION 3.16)
project(Array)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUSE_TIMER)

set(SOURCES include/Kadane.h include/FourSum.h include/ContainsDuplicate.h include/ThreeSum.h)

add_library(ArrayAlgorithms STATIC ${SOURCES})
target_include_directories(ArrayAlgorithms PUBLIC include)
set_target_properties(ArrayAlgorithms PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(ArrayAlgorithms
        Profiling)