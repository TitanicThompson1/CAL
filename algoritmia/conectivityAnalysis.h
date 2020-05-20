//
// Created by debor on 19/05/2020.
//

#ifndef CODE_CONECTIVITYANALYSIS_H
#define CODE_CONECTIVITYANALYSIS_H

#include <fstream>
#include "FarmFresh2You.h"
#include "Graph.h"
#include "BasketsIO.h"

void conectivityAnalysis(const FarmFresh2You &farm, Graph<int> &graph, const string &filename, const string &resultFilename);




#endif //CODE_CONECTIVITYANALYSIS_H
