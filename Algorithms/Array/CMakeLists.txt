cmake_minimum_required(VERSION 3.16)
project(Array)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUSE_TIMER)

set(SOURCES Kadane.h FourSum.h ContainsDuplicate.h ThreeSum.h TrappingWater.h)
add_library(ArrayAlgorithms STATIC ${SOURCES})
set_target_properties(ArrayAlgorithms PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(ArrayAlgorithms PUBLIC ${CMAKE_BINARY_DIR}/lib)
target_link_libraries(ArrayAlgorithms
        Profiling)