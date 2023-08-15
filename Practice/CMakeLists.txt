project(Practice)
set(CMAKE_MINIMUM_REQUIRED_VERSION VERSION 3.16)
set(CXX_STANDARD 20)


add_library(${PROJECT_NAME} STATIC user.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
    $<INSTALL_INTERFACE:/)

add_executable("${PROJECT_NAME}_TESTS" Tests/BigIntTests.cpp Tests/UserTests.cpp Tests/BasicCharTests.cpp)

target_link_libraries("${PROJECT_NAME}_TESTS"
Practice
CONAN_PKG::gtest)