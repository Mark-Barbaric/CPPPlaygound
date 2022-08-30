set(CMAKE_CXX_STANDARD 20)
project(Behavioral)

set(SOURCES Visitor.cpp Visitor.h main.cpp Element.h)
add_executable(Behavioral ${SOURCES})