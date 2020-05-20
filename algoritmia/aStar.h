//
// Created by Ricardo Nunes on 17/05/2020.
//

#ifndef CODE_ASTAR_H
#define CODE_ASTAR_H

#include <fstream>
#include "FarmFresh2You.h"
#include "Graph.h"
#include "BasketsIO.h"


void aStarAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filename, const string &resultFilename);

void aStarAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filename);


#endif //CODE_ASTAR_H
