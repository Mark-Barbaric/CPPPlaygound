project(PokerHands)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES poker_hand.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
    $<INSTALL_INTERFACE:/>
)

add_executable("${PROJECT_NAME}_TESTS" PokerHandTests.cpp)
target_link_libraries("${PROJECT_NAME}_TESTS"
${PROJECT_NAME}
CONAN_PKG::gtest
    )