#include "aStar.h"

void aStarAlgorithm(Graph<int> &graph, const string &filename, const string &resultFilename) {

    ifstream infile(filename);

    int farmer, delivery, garage;
    infile >> farmer;
    infile >> delivery;
    infile >> garage;

    graph.aStarAlgorithm(farmer, delivery);

    graph.exportResultsToFile(resultFilename, farmer, delivery);

    infile.close();

}
