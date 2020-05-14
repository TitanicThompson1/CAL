//
// Created by Ricardo Nunes on 14/05/2020.
//

#ifndef CODE_GRAPHIO_H
#define CODE_GRAPHIO_H

#include "../graph/Graph.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Graph<int> readGraph(const string nodesFilename, const string edgesFilename);


#endif //CODE_GRAPHIO_H
