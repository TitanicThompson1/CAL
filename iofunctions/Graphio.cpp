//
// Created by Ricardo Nunes on 14/05/2020.
//

#include "Graphio.h"


Graph<int> readGraph(const string nodesFilename, const string edgesFilename) {

    Graph<int> graph;

    ifstream Ninfile(nodesFilename);

    //Importing nodes
    int nNodes; string node, node2, sId, sX, sY;
    int id, x, y;
    getline(Ninfile,node);
    while(getline(Ninfile,node)){
        node2 = node.substr(1, node.size() - 2);

        istringstream part(node2);
        getline(part,sId,',');
        id = stoi(sId);

        getline(part,sX,',');
        x = stoi(sX);

        getline(part,sY,',');
        y = stoi(sY);

        graph.addVertex(id, x, y);
    }

    return graph;
}
