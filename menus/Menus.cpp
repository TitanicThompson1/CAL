//
// Created by Ricardo Nunes on 14/05/2020.
//

#include "Menus.h"
#include "aStar.h"

int VisualizeGraphMenu(Graph<int> &graph) {

    newWindow();

    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(800, 800);

    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    //Adding Nodes
    auto vertexSet = graph.getVertexSet();
    for(auto v : vertexSet){
        gv->addNode(v->getInfo(), v->getX(), v->getY());
    }
    //Adding Edges
    int idE = 1;
    for(auto v : vertexSet){
        auto edges = v->getAdj();
        for (auto edge: edges){
            gv->addEdge(idE++, edge.getOrig()->getInfo(), edge.getDest()->getInfo(), EdgeType::DIRECTED);
        }
    }

    gv->setEdgeColor(0, "yellow");

    gv->rearrange();

    int nextMenu;
    cout << "0 - Voltar" << endl;
    cin >> nextMenu;
    return nextMenu;
}

int InitialMenu(Graph<int> &graph) {
    int nextMenu;

    newWindow();

    cout << "1 - See graph" << endl
        << "2 - Calculate first fase" << endl
        << "-1 - Sair" << endl;
    cin >> nextMenu;
    return nextMenu;
}

int FirstFaseMenu(const FarmFresh2You &farm, Graph<int> &graph) {
    newWindow();

    string filename, resFilename;
    cout << "Introduza o nome do ficheiro que contem os cabazes" << endl;
    cin >> filename;

    cout << "Introduza o nome do ficheiro que irá conter os resultados" << endl;
    cin >> resFilename;


    aStarAlgorithm(farm, graph, filename, resFilename);
    newWindow();

    cout << "Algoritmo realizado com sucesso!" << endl
        << "Introduza qualquer caracter para prosseguir" << endl;

    cin >> filename;


    return 0;
}

int SecondFaseMenu(Graph<int> &graph) {
    return 0;
}

int ThirdFaseMenu(Graph<int> &graph) {
    return 0;
}

void newWindow() {
    for (int i = 0; i < 10; i++){
        cout << endl;
    }
}


