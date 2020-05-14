cmake_minimum_required(VERSION 3.10)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp graph/Graph.h graph/MutablePriorityQueue.h iofunctions/Graphio.cpp iofunctions/Graphio.h
        menus/Menus.cpp menus/Menus.h)
