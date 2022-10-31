project(Datastructures)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES BinarySearchTree.h
        CircularDeque.h CircularQueue.h
        Graph.h
        HashMap.h HashSet.h
        LinkedList.h
        LRUCache.h
        MedianHeap.h
        Queue.h QueueStructure.h
        Stack.h
        )

add_library(Datastructures STATIC ${SOURCES})
set_target_properties(Datastructures PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(Datastructures PROPERTIES APPEND_STRING PROPERTY 
    COMPILE_FLAGS " ${CMAKE_INCLUDE_SYSTEM_FLAG_CXX} /foo")
add_subdirectory(Tree)