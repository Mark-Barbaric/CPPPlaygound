cmake_minimum_required(VERSION 3.16)
project(Array)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_definitions(-DUSE_TIMER)
set(SOURCES FourSum.h ContainsDuplicate.h ThreeSum.h TrappingWater.h IsRectangle.h)

#add_library(Array SHARED ${SOURCES})
#set_target_properties(Array PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_test(NAME ArrayTests COMMAND ArrayTests)


set(TEST_SOURCES ArrayTests.cpp IsRectangleTests.cpp)
add_executable(ArrayTests ${TEST_SOURCES} ${SOURCES})

target_link_libraries(ArrayTests
        CONAN_PKG::gtest)