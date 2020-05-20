//
// Created by Ricardo Nunes on 19/05/2020.
//

#include "complexityAnalysis.h"

void testAStarPerfomance() {

    ofstream res("resultsAStar.csv");

    res << "size; time" << endl;
    
    auto graph = readGraph("maps/GridGraphs/16x16/nodes.txt", "maps/GridGraphs/16x16/edges.txt");

    auto start = std::chrono::high_resolution_clock::now();

    aStarAlgorithm(FarmFresh2You(0,288), graph,"deliveries/exemploCabaz.txt");

    auto finish = std::chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(finish - start).count();

    res << "16x16" << ";" << elapsed << endl;

    res.close();
}