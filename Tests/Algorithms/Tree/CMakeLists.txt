project(TreeAlgorithmTests)

set(SOURCES TraversalAlgorithmTests.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
CONAN_PKG::gtest
TreeAlgorithms
Tree)