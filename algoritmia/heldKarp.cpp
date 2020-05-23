//
// Created by Joao on 5/19/2020.
//

#include "heldKarp.h"

void heldKarpAlgorithm(const FarmFresh2You &farm, Graph<int> graph, const string &filename, const string &resultFilename) {
    // Does HeldKarp Algorithm
    int start, end, cabaz, min_i = -1, min_cabaz;
    double dist, min_dist = -1;

    start = farm.getFarm(); // Get Farm position
    end = farm.getGarage(); // Get Garage position

    vector<Basket> baskets = readBasketsFromFile(filename); // Read Baskets from a text file

    vector<int> route;
    route.push_back(start); // Add farm to the route

    int size = baskets.size();

    for(int j = 0; j < size; j++) {
        min_dist = -1;
        min_i = -1;

        // Get the closest basket (point)
        for(int i = 0; i < baskets.size(); i++) {
            start = route.back();
            cabaz = baskets.at(i).getDest();
            graph.aStarAlgorithm(start, cabaz); // Get the route to a basket

            dist = graph.calculatePathsize(start, cabaz); // Calculate the previous route size

            if(dist < min_dist || min_i == -1) {
                min_dist = dist;
                min_i = i;
                min_cabaz = cabaz;
            }
        }

        route.push_back(min_cabaz); // Add the closest point to the route
        baskets.erase(baskets.begin() + min_i); // Deletes the closest basket from the baskets vector
        graph.exportResultsToFile(resultFilename, start, min_cabaz);
    }

    start = route.back();
<<<<<<< HEAD
    graph.aStarAlgorithm(start, end); // Get path from the last basket to the garage
    dist = graph.calculatePathsize(start, end); // Calculate the previous path size
    route.push_back(end); // Add the garage to the route
=======
    graph.aStarAlgorithmGraph(start, end);
    dist = graph.calculatePathsize(start, end);
    cout << "From " << start << " to " << end << ": " << dist << endl;
    route.push_back(end);
>>>>>>> ricardo
    graph.exportResultsToFile(resultFilename, start, end);
}