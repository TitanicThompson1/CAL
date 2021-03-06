//
// Created by Ricardo Nunes on 14/05/2020.
//

#include "Graphio.h"


Graph<int> readGraph() {

    Graph<int> graph;

    string nodesFilename, edgesFilename;
    cout << "Introduza o nome do ficheiro dos nos" << endl;
    cin >> nodesFilename;

    //Repeats until it has an valid file
    bool invalid;
    do{
        invalid = false;
        try {
            getNodesFromFile(nodesFilename, graph);
        }catch (FileNotFound fileNotFound){
            invalid = true;
            cout << "O ficheiro '"<< fileNotFound.getFilename() << "' nao existe. Por favor introduza outra vez" << endl;
            cin >> nodesFilename;
        }
    }while(invalid);

    cout << "Introduza o nome do ficheiro das arestas" << endl;
    cin >> edgesFilename;
    do{
        invalid = false;
        try {
            getEdgesFromFile(edgesFilename, graph);
        }catch (FileNotFound fileNotFound){
            invalid = true;
            cout << "O ficheiro '"<< fileNotFound.getFilename() << "' nao existe. Por favor introduza outra vez" << endl;
            cin >> edgesFilename;
        }
    }while(invalid);


    return graph;

}


Graph<int> readGraph(const string &nodesFilename, const string &edgesFilename) {

    Graph<int> graph;

    getNodesFromFile(nodesFilename, graph);

    getEdgesFromFile(edgesFilename, graph);

    return graph;
}


void getNodesFromFile(const string &nodesFilename, Graph<int> &graph) {

    ifstream Ninfile(nodesFilename);

    if(!Ninfile.is_open())
        throw FileNotFound(nodesFilename);

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
        x = stod(sX);

        getline(part,sY,',');
        y = stod(sY);

        graph.addVertex(id, x, y);

    }
}


void getEdgesFromFile(const string &edgesFilename, Graph<int> &graph) {

    ifstream Einfile(edgesFilename);

    if(!Einfile.is_open())
        throw FileNotFound(edgesFilename);

    //Importing edges
    string sSrc, sDest, node, node2;
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

        //For testing: comment otherwise
        graph.addEdge(dest, src, -1);
    }
}
