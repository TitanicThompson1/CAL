//
// Created by Ricardo Nunes on 14/05/2020.
//

#include "Graphio.h"


Graph<int> readGraph(const string nodesFilename, const string edgesFilename) {

    Graph<int> graph;

    ifstream Ninfile(nodesFilename);

    //Importing nodes
    string node, node2, sId, sX, sY;
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

    ifstream Einfile(edgesFilename);
    //Importing edges
    string sSrc, sDest;
    int src, dest;

    getline(Einfile,node);
    while(getline(Einfile,node)){
        node2 = node.substr(1, node.size() - 2);

        istringstream part(node2);

        getline(part,sSrc,',');
        src = stoi(sSrc);

        getline(part,sDest,',');
        dest = stoi(sDest);

        graph.addEdge(src, dest, -1);
    }
    return graph;
}
