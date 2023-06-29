project(GraphAlgorithmTests)
set(CMAKE_MINIMUM_REQUIRED_VERSION VERSION 20)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES GraphAlgorithmTests.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} 
CONAN_PKG::gtest
GraphAlgorithms
Graph
)