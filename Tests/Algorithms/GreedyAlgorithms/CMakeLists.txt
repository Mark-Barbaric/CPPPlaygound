set(TEST_SOURCES GreedyAlgorithmTests.cpp)
add_executable(GreedyAlgorithmTests ${TEST_SOURCES})

target_link_libraries(GreedyAlgorithmTests
CONAN_PKG::gtest
GreedyAlgorithms)