//
// Created by Ricardo Nunes on 19/05/2020.
//
#include "complexityAnalysis.h"





void testAStarPerfomance1() {

    ofstream res("AnalysisResults/resultsAStar.txt");

    //res.precision(32);

    //cout.precision(32);

    res << "vertice1:vertice2; time" << endl;
    
    auto graph = readGraph("maps/PortugalMaps/Porto/porto_strong_nodes_xy.txt", "maps/PortugalMaps/Porto/porto_strong_edges.txt");

    double timeTaken = registerTime(graph,"deliveries/testeCabaz1.txt", "temp.txt");

    res << "1:26" << ";" << timeTaken << setprecision(8) << endl;

    timeTaken = registerTime(graph,"deliveries/testeCabaz2.txt", "temp.txt");

    res << "1:148" << ";" << timeTaken << setprecision(8) << endl;

    timeTaken = registerTime(graph,"deliveries/testeCabaz3.txt", "temp.txt");

    res << "1:500" << ";" << timeTaken << setprecision(8) << endl;

    timeTaken = registerTime(graph,"deliveries/testeCabaz4.txt", "temp.txt");

    res << "1:1100" << ";" << timeTaken << setprecision(8) << endl;

    timeTaken = registerTime(graph,"deliveries/testeCabaz5.txt", "temp.txt");

    res << "1:26844" << ";" << timeTaken << setprecision(8) << endl;

    res.close();
}

void testHeldKarpPerformance() {
    ofstream res("resultsHeldKarp.csv");

    res << "size; time" << endl;

    auto graph = readGraph("maps/GridGraphs/4x4/nodes.txt", "maps/GridGraphs/4x4/edges.txt");

    auto start = std::chrono::high_resolution_clock::now();

    heldKarpAlgorithm(FarmFresh2You(90379359, 90379619), graph, "deliveries/exemploCabaz.txt", "deliveries/resFase2.txt");

    auto finish = std::chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(finish - start).count();

    res << "4x4" << ";" << elapsed << endl;

    res.close();
}


void testAStarPerfomance2() {

    ofstream res("AnalysisResults/resultsAStar3.txt");

    res << "map;time" << endl;

    auto graph = readGraph("maps/GridGraphs/4x4/nodes.txt", "maps/GridGraphs/4x4/edges.txt");

    double timeTaken = registerTime(graph,"deliveries/testeCabaz6.txt", "temp.txt");

    res << "4x4" << ";" << timeTaken << setprecision(8) << endl;

    graph = readGraph("maps/GridGraphs/8x8/nodes.txt", "maps/GridGraphs/8x8/edges.txt");

    timeTaken = registerTime(graph,"deliveries/testeCabaz6.txt", "temp.txt");

    res << "8x8" << ";" << timeTaken << setprecision(8) << endl;

    graph = readGraph("maps/GridGraphs/16x16/nodes.txt", "maps/GridGraphs/16x16/edges.txt");

    timeTaken = registerTime(graph,"deliveries/testeCabaz6.txt", "temp.txt");

    res << "16x16" << ";" << timeTaken << setprecision(8) << endl;

    res.close();

}

double registerTime(Graph<int> graph, const string &input, const string &output) {

    clock_t start, end;

    start = clock();

    aStarAlgorithm(FarmFresh2You(1,26839),graph, input,output);

    end = clock();

    return double(end - start) / double(CLOCKS_PER_SEC);
}

double registerTime3Phase(Graph<int> graph, const string &inputBaskets, const string &inputTrucks, const string &output) {

    clock_t start, end;

    start = clock();

    //thirdPhaseAlgorithm(FarmFresh2You(0,0),graph, inputBaskets, inputTrucks, output);
    //thirdPhaseAlgorithm(FarmFresh2You(90379359,90379359),graph, inputBaskets, inputTrucks, output);
    //thirdPhaseAlgorithm(FarmFresh2You(90379359,281726622),graph, inputBaskets, inputTrucks, output);
    //thirdPhaseAlgorithm(FarmFresh2You(0,24),graph, inputBaskets, inputTrucks, output);
    //thirdPhaseAlgorithm(FarmFresh2You(0,80),graph, inputBaskets, inputTrucks, output);
    //thirdPhaseAlgorithm(FarmFresh2You(0,255),graph, inputBaskets, inputTrucks, output);

    end = clock();

    return double(end - start) / double(CLOCKS_PER_SEC);
}

void testThirdPhasePerformance() {

    ofstream res("AnalysisResults/results3Phase.txt");

    res << "map;time" << endl;

    auto graph = readGraph("maps/GridGraphs/4x4/nodes.txt", "maps/GridGraphs/4x4/edges.txt");
    double timeTaken = registerTime3Phase(graph,"deliveries/exemploCabaz.txt", "FarmFresh2You/testeTruckFase3.txt", "resultado3Fase.txt");
    res << "4x4" << ";" << timeTaken << setprecision(8) << endl;

    graph = readGraph("maps/GridGraphs/8x8/nodes.txt", "maps/GridGraphs/8x8/edges.txt");
    timeTaken = registerTime3Phase(graph,"deliveries/exemploCabaz.txt", "FarmFresh2You/trucks2.txt", "resultado3Fase.txt");
    res << "8x8" << ";" << timeTaken << setprecision(8) << endl;

    graph = readGraph("maps/GridGraphs/8x8/nodes.txt", "maps/GridGraphs/8x8/edges.txt");
    timeTaken = registerTime3Phase(graph,"deliveries/exemploCabazBig.txt", "FarmFresh2You/testeTruckFase3.txt", "resultado3Fase.txt");
    res << "8x8" << ";" << timeTaken << setprecision(8) << endl;

    graph = readGraph("maps/GridGraphs/16x16/nodes.txt", "maps/GridGraphs/16x16/edges.txt");
    timeTaken = registerTime3Phase(graph,"deliveries/exemploCabaz.txt", "FarmFresh2You/trucks2.txt", "resultado3Fase.txt");
    res << "16x16" << ";" << timeTaken << setprecision(8) << endl;

    graph = readGraph("maps/GridGraphs/16x16/nodes.txt", "maps/GridGraphs/16x16/edges.txt");
    timeTaken = registerTime3Phase(graph,"deliveries/exemploCabazBig.txt", "FarmFresh2You/testeTruckFase3.txt", "resultado3Fase.txt");
    res << "16x16" << ";" << timeTaken << setprecision(8) << endl;

    //res.precision(32);

    //cout.precision(32);

    res << "vertice1:vertice2; time" << endl;

    graph = readGraph("maps/PortugalMaps/Porto/nodes_x_y_porto.txt", "maps/PortugalMaps/Porto/edges_porto.txt");

    timeTaken = registerTime3Phase(graph,"deliveries/exemploCabazBig.txt", "FarmFresh2You/testeTruckFase3.txt", "resultado3Fase.txt");

    res << "Mapa Porto" << ";" << timeTaken << setprecision(8) << endl;


    res.close();
}

void testConnectivity(){
    ofstream res("AnalysisResults/resultsConnectivity.txt");

    res << "map;time" << endl;


    auto graph = readGraph("maps/GridGraphs/8x8/nodes.txt", "maps/GridGraphs/8x8/edges.txt");

    double timeTaken = registerTimeConnectivity(graph);

    res << "8x8" << ";" << timeTaken << setprecision(8) << endl;


    graph = readGraph("maps/GridGraphs/16x16/nodes.txt", "maps/GridGraphs/16x16/edges.txt");

    timeTaken = registerTimeConnectivity(graph);

    res << "16x16" << ";" << timeTaken << setprecision(8) << endl;

    graph = readGraph("maps/PortugalMaps/Porto/porto_full_nodes_xy.txt", "maps/PortugalMaps/Porto/porto_full_edges.txt");

    timeTaken = registerTimeConnectivity(graph);

    res << "Porto" << ";" << timeTaken << setprecision(8) << endl;



}

double registerTimeConnectivity(Graph<int> &graph) {

    clock_t start, end;

    start = clock();

    graph.dfsRemoveUnvisited(1);

    end = clock();

    return double(end - start) / double(CLOCKS_PER_SEC);
}



