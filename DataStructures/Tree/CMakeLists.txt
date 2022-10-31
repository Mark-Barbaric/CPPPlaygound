project(Tree)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES src/BST.cpp include/BST.h include/Node.h)
add_library(BinarySearchTree STATIC ${SOURCES})

target_include_directories(BinarySearchTree PUBLIC include)

#set_target_properties(BinarySearchTree PROPERTIES LINKER_LANGUAGE CXX)
#set_target_properties(BinarySearchTree PROPERTIES INCLUDE_DIRECTORIES "/include")

