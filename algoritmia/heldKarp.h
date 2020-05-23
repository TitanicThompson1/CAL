//
// Created by Joao on 5/19/2020.
//

#ifndef CODE_HELDKARP_H
#define CODE_HELDKARP_H

#include <fstream>
#include "Graph.h"
#include "BasketsIO.h"
#include "../FarmFresh2You/FarmFresh2You.h"


void heldKarpAlgorithm(const FarmFresh2You &farm, Graph<int> graph, const string &filename, const string &resultFilename);

void heldKarpCore(int startVertex, int endVertex, vector<Basket> allBaskets, Graph<int> &graph, const string &resultFilename);

#endif //CODE_HELDKARP_H
