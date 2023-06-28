project(TreeTests)

set(SOURCES NodeTests.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/Datastructures/Tree)

target_link_libraries(${PROJECT_NAME}
CONAN_PKG::gtest
Tree)