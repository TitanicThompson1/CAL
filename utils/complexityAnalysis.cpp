//
// Created by Ricardo Nunes on 19/05/2020.
//

#include "complexityAnalysis.h"

void testAStarPerfomance() {

    ofstream res("AnalysisResults/resultsAStar.txt");

    //res.precision(32);

    //cout.precision(32);

    res << "vertice1:vertice2; time" << endl;
    
    auto graph = readGraph("maps/PortugalMaps/Porto/porto_strong_nodes_xy.txt", "maps/PortugalMaps/Porto/porto_strong_edges.txt");

    //auto start = std::chrono::high_resolution_clock::now();
    int nStarted = GetMilliCount();

    aStarAlgorithm(FarmFresh2You(1,27796),graph, "deliveries/testeCabaz1.txt","res1.txt");
    //graph.aStarAlgorithmGraph(1,26);

    int nTimeSpan = GetMilliSpan(nStarted);
    //auto finish = std::chrono::high_resolution_clock::now();
    //auto elapsed = chrono::duration_cast<chrono::microseconds>(finish - start).count();

    //cout << start.time_since_epoch().count() << endl;
    //cout << finish.time_since_epoch().count() << endl;
    //cout << elapsed << endl;

    res << "1:26" << ";" << nTimeSpan << endl;

    //start = std::chrono::high_resolution_clock::now();
    nStarted = GetMilliCount();

    aStarAlgorithm(FarmFresh2You(1,27796),graph, "deliveries/testeCabaz2.txt","res2.txt");
    //graph.aStarAlgorithmGraph(1,148);

    //finish = std::chrono::high_resolution_clock::now();
    //elapsed = chrono::duration_cast<chrono::microseconds>(finish - start).count();

    //cout << start.time_since_epoch().count() << endl;
    //cout << finish.time_since_epoch().count() << endl;
    //cout << elapsed << endl;
    nTimeSpan = GetMilliSpan(nStarted);

    res << "1:148" << ";" << nTimeSpan << endl;

    //start = std::chrono::high_resolution_clock::now();

    nStarted = GetMilliCount();

    aStarAlgorithm(FarmFresh2You(1,27796),graph, "deliveries/testeCabaz3.txt","res3.txt");
    //graph.aStarAlgorithmGraph(1,500);

    //finish = std::chrono::high_resolution_clock::now();
    //elapsed = chrono::duration_cast<chrono::microseconds>(finish - start).count();

    //cout << start.time_since_epoch().count() << endl;
    //cout << finish.time_since_epoch().count() << endl;
    //cout << elapsed << endl;

    nTimeSpan = GetMilliSpan(nStarted);
    res << "1:500" << ";" << nTimeSpan << endl;

    //start = std::chrono::high_resolution_clock::now();

    nStarted = GetMilliCount();

    aStarAlgorithm(FarmFresh2You(1,27796),graph, "deliveries/testeCabaz4.txt","res4.txt");
    //graph.aStarAlgorithmGraph(1,1100);

    //finish = std::chrono::high_resolution_clock::now();
    //elapsed = chrono::duration_cast<chrono::microseconds>(finish - start).count();

    //cout << start.time_since_epoch().count() << endl;
    //cout << finish.time_since_epoch().count() << endl;
    //cout << elapsed << endl;
    nTimeSpan = GetMilliSpan(nStarted);

    res << "1:1100" << ";" << nTimeSpan << endl;

    //start = std::chrono::high_resolution_clock::now();
    nStarted = GetMilliCount();

    aStarAlgorithm(FarmFresh2You(1,27796),graph, "deliveries/testeCabaz5.txt","res5.txt");
    //graph.aStarAlgorithmGraph(1,26844);

    //finish = std::chrono::high_resolution_clock::now();
    //elapsed = chrono::duration_cast<chrono::microseconds>(finish - start).count();

    //cout << start.time_since_epoch().count() << endl;
    //cout << finish.time_since_epoch().count() << endl;
    //cout << elapsed << endl;
    nTimeSpan = GetMilliSpan(nStarted);

    res << "1:26844" << ";" << nTimeSpan << endl;

    res.close();
}



int GetMilliCount() {
    timeb tb;
    ftime( &tb );
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}

int GetMilliSpan(int nTimeStart)
{
    int nSpan = GetMilliCount() - nTimeStart;
    if (nSpan < 0)
        nSpan += 0x100000 * 1000;
    return nSpan;
}