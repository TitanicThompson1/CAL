//
// Created by debor on 19/05/2020.
//

#include "conectivityAnalysis.h"


void conectivityAnalysis(const FarmFresh2You &farm, Graph<int> &graph, const string &filename, const string &resultFilename) {

    vector<Basket> baskets = readBasketsFromFile(filename);

//incluir parametro
    graph.dfs();

    //call find

    //calm removeAllUnvisited

    //unir dfs e removeunvisited numa funcao so



}