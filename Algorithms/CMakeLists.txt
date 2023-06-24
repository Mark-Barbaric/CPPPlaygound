add_subdirectory(Array)
add_subdirectory(Backtracking)
add_subdirectory(BinarySearch)
add_subdirectory(Graph)
add_subdirectory(LinkedList)
add_subdirectory(SlidingWindow)
add_subdirectory(Strings)
add_subdirectory(TwoPointers)


set(GREEDY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/include/GreedyAlgorithms/MediumGreedyAlgorithms.h)

add_library(GreedyAlgorithms SHARED ${GREEDY_SOURCES})
target_include_directories(GreedyAlgorithms INTERFACE include/GreedyAlgorithms)
set_target_properties(GreedyAlgorithms PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS GreedyAlgorithms DESTINATION /usr/lib)
install(FILES ${GREEDY_SOURCES} DESTINATION include)