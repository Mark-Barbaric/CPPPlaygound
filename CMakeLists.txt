cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE PATH "Where to place compiled static libraries.")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE PATH "Where to place compiled shared libraries.")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE PATH "Where to place compiled executables.")

project(AlgorithmsAndDatastructures)

include_directories(BEFORE ${PROJECT_SOURCE_DIR})

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.13/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

message(INFO "Binary dir ${CMAKE_BINARY_DIR}")

include(${CMAKE_BINARY_DIR}/conan.cmake)

find_program(CONAN_CMD conan)

if(NOT CONAN_CMD AND CONAN_REQUIRED)
    message(FATAL_ERROR "Conan executable not found!")
endif()

set(CONAN_DISABLE_CHECK_COMPILER True)

set(conan_file "${CMAKE_SOURCE_DIR}/conanfile.py")
set(conan_install_optss "-g cmake --build=missing")

message("CMake Host System Name ${CMAKE_HOST_SYSTEM_NAME}")

set(conan_profile_file "${CMAKE_SOURCE_DIR}/conan_profiles/${CMAKE_HOST_SYSTEM_NAME}.profile")

message("Conan Profile: ${conan_profile_file}")

message(STATUS "conan install ${conan_file} -pr ${conan_profile_file} ${conan_install_optss}")
execute_process(
        COMMAND conan install "${conan_file}"
        -pr ${conan_profile_file}
        ${conan_install_opts}
        -if ${CMAKE_BINARY_DIR}
        OUTPUT_FILE conan_install_output.txt
        ERROR_VARIABLE conan_install_error
        RESULT_VARIABLE conan_result)


add_subdirectory(Algorithms)
add_subdirectory(Advanced_CPP_Topics)
add_subdirectory(DataStructures)
add_subdirectory(Profiling)
add_subdirectory(interview_questions)


enable_testing()
add_subdirectory(Tests)
