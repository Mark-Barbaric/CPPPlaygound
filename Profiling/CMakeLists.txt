project(Profiling)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUSE_TIMER)

add_library(Profiling STATIC ScopedTimer.h)
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:>
)
set_target_properties(Profiling PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(Examples)