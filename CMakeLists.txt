cmake_minimum_required(VERSION 3.10)
project(code)

set(CMAKE_CXX_STANDARD 14)

link_libraries(ws2_32 wsock32)

include_directories(lib)
include_directories(menus)
include_directories(graph)

add_executable(code main.cpp graph/Graph.h graph/MutablePriorityQueue.h iofunctions/Graphio.cpp iofunctions/Graphio.h
        menus/Menus.cpp menus/Menus.h lib/connection.cpp lib/connection.h lib/graphviewer.cpp lib/graphviewer.h lib/edgetype.h)

