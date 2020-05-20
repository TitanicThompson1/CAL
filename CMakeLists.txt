cmake_minimum_required(VERSION 3.10)
project(code)

set(CMAKE_CXX_STANDARD 14)

link_libraries(ws2_32 wsock32)

include_directories(lib)
include_directories(menus)
include_directories(graph)
include_directories(iofunctions)
include_directories(algoritmia)
include_directories(FarmFresh2You)


add_executable(code main.cpp graph/Graph.h graph/MutablePriorityQueue.h iofunctions/Graphio.cpp iofunctions/Graphio.h
        menus/Menus.cpp menus/Menus.h lib/connection.cpp lib/connection.h lib/graphviewer.cpp lib/graphviewer.h lib/edgetype.h
        algoritmia/aStar.h algoritmia/aStar.cpp FarmFresh2You/Basket.cpp FarmFresh2You/Basket.h FarmFresh2You/Truck.cpp
        FarmFresh2You/Truck.h iofunctions/BasketsIO.cpp iofunctions/BasketsIO.h FarmFresh2You/FarmFresh2You.cpp
        FarmFresh2You/FarmFresh2You.h iofunctions/FarmerFresh2YouIO.cpp iofunctions/FarmerFresh2YouIO.h
        algoritmia/conectivityAnalysis.cpp algoritmia/conectivityAnalysis.h)

