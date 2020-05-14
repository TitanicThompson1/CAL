//
// Created by Ricardo Nunes on 14/05/2020.
//

#include "Graphio.h"


Graph<int> readGraph(const string nodesFilename, const string edgesFilename) {

    Graph<int> graph();

    ifstream Ninfile(nodesFilename);

    //Importing nodes
    int nNodes;
    Ninfile >> nNodes;
    while(!Ninfile.eof()){
        
    }


}
