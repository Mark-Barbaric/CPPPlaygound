project(BigInt)
set(CMAKE_MINIMUM_REQUIRED_VERSION VERSION 3.16)
set(CXX_STANDARD 20)

add_executable("${PROJECT_NAME}_TESTS" BigInt.h Tests.cpp)

target_link_libraries("${PROJECT_NAME}_TESTS"
CONAN_PKG::gtest)