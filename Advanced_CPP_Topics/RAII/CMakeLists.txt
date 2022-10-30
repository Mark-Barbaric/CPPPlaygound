project(RAII)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES main.cpp smart_ptr.h)
add_executable(RAII ${SOURCES})