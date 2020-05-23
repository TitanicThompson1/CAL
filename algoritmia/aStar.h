//
// Created by Ricardo Nunes on 17/05/2020.
//

#ifndef CODE_ASTAR_H
#define CODE_ASTAR_H

#include <fstream>
#include "FarmFresh2You.h"
#include "Graph.h"
#include "BasketsIO.h"

/**
 * Algorithm that resolves fase 1 (using A * algorithm)
 * @param farm company that contains the source and destination
 * @param graph graph to performe the algorithm
 * @param filename name of the file that contains the baskets
 * @param resultFilename name of the file to export the results to
 */
void aStarAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filename, const string &resultFilename);

//void aStarAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filename);


#endif //CODE_ASTAR_H
