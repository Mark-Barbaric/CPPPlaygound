set(CMAKE_CXX_STANDARD 20)
project(CreationalPatterns)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES AbstractFactory.h)
set(TESTS AbstractFactoryTests.cpp)

add_executable(CreationalPatternTests ${SOURCES}
        ${TESTS})

target_link_libraries(CreationalPatternTests
        CONAN_PKG::gtest)


