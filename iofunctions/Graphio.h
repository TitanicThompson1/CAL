//
// Created by Ricardo Nunes on 14/05/2020.
//

#ifndef CODE_GRAPHIO_H
#define CODE_GRAPHIO_H

#include "Graph.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Graph<int> readGraph(const string &nodesFilename, const string &edgesFilename);

void getEdgesFromFile(const string &edgesFilename, Graph<int> &graph);

void getNodesFromFile(const string &nodesFilename, Graph<int> &graph);

#endif //CODE_GRAPHIO_H
