#include <Basket.h>
#include "aStar.h"

void aStarAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filename, const string &resultFilename) {

    vector<Basket> baskets = readBasketsFromFile(filename);

    graph.aStarAlgorithm(farm.getFarm(), baskets.at(0).getDest());

    graph.exportResultsToFile(resultFilename, farm.getFarm(), baskets.at(0).getDest());

    graph.aStarAlgorithm(baskets.at(0).getDest(),farm.getGarage());

    graph.exportResultsToFile(resultFilename, baskets.at(0).getDest(), farm.getGarage());

}
