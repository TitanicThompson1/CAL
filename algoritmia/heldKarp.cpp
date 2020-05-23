//
// Created by Joao on 5/19/2020.
//

#include "heldKarp.h"
/*
void heldKarpAlgorithm(const FarmFresh2You &farm, Graph<int> graph, const string &filename, const string &resultFilename) {
    int start, end, cabaz, dist, min_dist = -1, min_i = -1, min_cabaz;
    start = farm.getFarm();
    end = farm.getGarage();

    cout << "Start: " << start << " " << "End: " << end << endl;

    vector<Basket> baskets = readBasketsFromFile(filename);

    vector<int> route;
    route.push_back(start);

    int size = baskets.size();

    for(int j = 0; j < size; j++) {
        min_dist = -1;
        min_i = -1;
        for(int i = 0; i < baskets.size(); i++) {
            start = route.back();
            cabaz = baskets.at(i).getDest();
            graph.aStarAlgorithm(start, cabaz);

            dist = dist = graph.calculatePathsize(start, cabaz);

            cout << "From " << start << " to " << cabaz << ": " << dist << endl;
            if(dist < min_dist || min_i == -1) {
                min_dist = dist;
                min_i = i;
                min_cabaz = cabaz;
            }
        }
        route.push_back(min_cabaz);
        baskets.erase(baskets.begin() + min_i);
        graph.exportResultsToFile(resultFilename, start, min_cabaz);
    }

    start = route.back();
    graph.aStarAlgorithm(start, end);
    dist = graph.calculatePathsize(start, end);
    cout << "From " << start << " to " << end << ": " << dist << endl;
    route.push_back(end);
    graph.exportResultsToFile(resultFilename, start, end);

    for(int i = 0; i < route.size(); i++) {
        if(i == route.size() - 1)
            cout << route.at(i) << endl;
        else
            cout << route.at(i) << " -> ";
    }
}*/

void heldKarpAlgorithm(const FarmFresh2You &farm, Graph<int> graph, const string &filename, const string &resultFilename) {
    int start, end;
    start = farm.getFarm();
    end = farm.getGarage();
    cout << "Start: " << start << " " << "End: " << end << endl;
    vector<Basket> baskets = readBasketsFromFile(filename);
    heldKarpCore(start, end, baskets, graph,resultFilename);
}
void heldKarpCore(int startVertex, int endVertex, vector<Basket> allBaskets, Graph<int> &graph, const string &resultFilename) {
    int cabaz, dist, min_dist = -1, min_i = -1, min_cabaz;
    vector<int> route;
    route.push_back(startVertex);
    int size = allBaskets.size();

    for(int j = 0; j < size; j++) {
        min_dist = -1;
        min_i = -1;
        for(int i = 0; i < allBaskets.size(); i++) {
            startVertex = route.back();
            cabaz = allBaskets.at(i).getDest();
            graph.aStarAlgorithm(startVertex, cabaz);

            dist = dist = graph.calculatePathsize(startVertex, cabaz);

            cout << "From " << startVertex << " to " << cabaz << ": " << dist << endl;
            if(dist < min_dist || min_i == -1) {
                min_dist = dist;
                min_i = i;
                min_cabaz = cabaz;
            }
        }
        route.push_back(min_cabaz);
        allBaskets.erase(allBaskets.begin() + min_i);
        graph.exportResultsToFile(resultFilename, startVertex, min_cabaz);
    }
    startVertex = route.back();
    graph.aStarAlgorithm(startVertex, endVertex);
    dist = graph.calculatePathsize(startVertex, endVertex);
    cout << "From " << startVertex << " to " << endVertex << ": " << dist << endl;
    route.push_back(endVertex);
    graph.exportResultsToFile(resultFilename, startVertex, endVertex);

    for(int i = 0; i < route.size(); i++) {
        if(i == route.size() - 1)
            cout << route.at(i) << endl;
        else
            cout << route.at(i) << " -> ";
    }
 }
