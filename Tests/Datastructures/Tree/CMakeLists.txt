project(TreeTests)

set(SOURCES NodeTests.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
CONAN_PKG::gtest
Tree)