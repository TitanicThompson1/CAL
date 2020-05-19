//
// Created by Ricardo Nunes on 19/05/2020.
//

#include "complexityAnalysis.h"

void testAStarPerfomance() {

    ofstream res("resultsAStar.csv");

    res << "size; time" << endl;

    res.precision(10);

    for (int i = 0; i < 3; i++) {

        auto graph = readGraph();

        auto start = std::chrono::high_resolution_clock::now();

        aStarAlgorithm(FarmFresh2You(0,24), graph,"deliveries/exemploCabaz.txt","");

        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::microseconds>(finish - start).count();

        if(i == 0)
            res << "4x4";
        else if(i==1)
            res << "8x8";
        else
            res << "16x16";

        res << ";" << elapsed << endl;

    }
    res.close();
}