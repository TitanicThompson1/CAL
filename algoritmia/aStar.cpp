#include "aStar.h"

void aStarAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filename, const string &resultFilename) {

    vector<Basket> baskets = readBasketsFromFile(filename);

    graph.aStarAlgorithmGraph(farm.getFarm(), baskets.at(0).getDest());

    graph.exportResultsToFile(resultFilename, farm.getFarm(), baskets.at(0).getDest());

    graph.aStarAlgorithmGraph(baskets.at(0).getDest(), farm.getGarage());

    graph.exportResultsToFile(resultFilename, baskets.at(0).getDest(), farm.getGarage());

}



void aStarAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filename) {

    vector<Basket> baskets = readBasketsFromFile(filename);

    graph.aStarAlgorithmGraph(farm.getFarm(), baskets.at(0).getDest());

    graph.aStarAlgorithmGraph(baskets.at(0).getDest(), farm.getGarage());
}
