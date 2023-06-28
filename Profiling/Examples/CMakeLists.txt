project(Profiling)

add_definitions(-DUSE_TIMER)

set(SOURCES main.cpp ModuloImprovements.h MicroBenchmarkTest.h)
add_executable(ProfilingPractice ${SOURCES})
target_link_libraries(ProfilingPractice
        CONAN_PKG::gtest
        Profiling)

add_executable(vector_tests vector_tests.cpp)
target_link_libraries(vector_tests Profiling)