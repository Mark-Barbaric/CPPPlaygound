project(TreeAlgorithms)

set(SOURCES TraversalAlgorithms.h)
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:>
)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)