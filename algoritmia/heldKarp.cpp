//
// Created by Joao on 5/19/2020.
//

#include "heldKarp.h"

void heldKarpAlgorithm(const FarmFresh2You &farm, Graph<int> graph, const string &filename, const string &resultFilename) {
    int start, end;
    start = farm.getFarm(); // Get Farm position
    end = farm.getGarage(); // Get Garage position
    vector<Basket> baskets = readBasketsFromFile(filename); // Read Baskets from a text file
    heldKarpCore(start, end, baskets, graph,resultFilename);
}
void heldKarpCore(int startVertex, int endVertex, vector<Basket> allBaskets, Graph<int> &graph, const string &resultFilename) {
    // Does HeldKarp Algorithm
    int cabaz, min_i = -1, min_cabaz;
    double dist, min_dist = -1;
    vector<int> route;
    route.push_back(startVertex); // Add farm to the route
    int size = allBaskets.size();

    for(int j = 0; j < size; j++) {
        min_dist = -1;
        min_i = -1;
        for(int i = 0; i < allBaskets.size(); i++) {
            startVertex = route.back();
            cabaz = allBaskets.at(i).getDest();
            graph.aStarAlgorithmGraph(startVertex, cabaz);  // Get the route to a basket
            dist = graph.calculatePathsize(startVertex, cabaz); // Calculate the previous route size

            if(dist < min_dist || min_i == -1) {
                min_dist = dist;
                min_i = i;
                min_cabaz = cabaz;
            }
        }
        route.push_back(min_cabaz); // Add the closest point to the route
        allBaskets.erase(allBaskets.begin() + min_i); // Deletes the closest basket from the baskets vector
        graph.exportResultsToFile(resultFilename, startVertex, min_cabaz);
    }
    startVertex = route.back();
    graph.aStarAlgorithmGraph(startVertex, endVertex);  // Get path from the last basket to the garage
    dist = graph.calculatePathsize(startVertex, endVertex);  // Calculate the previous path size
    route.push_back(endVertex);  // Add the garage to the route
    graph.exportResultsToFile(resultFilename, startVertex, endVertex);
}

