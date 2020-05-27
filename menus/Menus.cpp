//
// Created by Ricardo Nunes on 14/05/2020.
//

#include "Menus.h"

int VisualizeGraphMenu(Graph<int> &graph) {

    newWindow();

    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(8000, 8000);

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

    //Setting the edge color to yellow
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

    cout << "1 - Ver grafo" << endl
        << "2 - Calcular primeira fase" << endl
        << "3 - Calcular segunda fase" << endl
        << "4 - Calcular terceira fase" << endl
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

    newWindow();

    try {
        aStarAlgorithm(farm, graph, filename, resFilename);
    }catch (FileNotFound f){
        cout << "Não foi possivel encontrar o ficheiro " << f.getFilename() << "." << endl;
        cout << "Introduza qualquer caracter para prosseguir" << endl;

        cin >> filename;
        return 0;
    }catch (VerticeNotFound<int> v){
        cout << "O vertice de id " << to_string(v.getInfo()) << "não existe." << endl;
        cout << "Introduza qualquer caracter para prosseguir" << endl;
        cin >> filename;
        return 0;
    }

    cout << "Algoritmo realizado com sucesso!" << endl
        << "Introduza qualquer caracter para prosseguir" << endl;

    cin >> filename;

    return 0;
}

int SecondFaseMenu(const FarmFresh2You &farm, Graph<int> &graph) {

    newWindow();

    string filename, resFilename;
    cout << "Introduza o nome do ficheiro que contem os cabazes: ";
    cin >> filename;

    cout << "Introduza o nome do ficheiro que irá conter os resultados: ";
    cin >> resFilename;

    newWindow();

    try {
        heldKarpAlgorithm(farm, graph, filename, resFilename);
    }catch (FileNotFound f){
        cout << "Não foi possivel encontrar o ficheiro " << f.getFilename() << "." << endl;
        cout << "Introduza qualquer caracter para prosseguir" << endl;

        cin >> filename;
        return 0;
    }catch (VerticeNotFound<int> v){
        cout << "O vertice de id " << to_string(v.getInfo()) << "não existe." << endl;
        cout << "Introduza qualquer caracter para prosseguir" << endl;
        cin >> filename;
        return 0;
    }

    cout << "Algoritmo realizado com sucesso!" << endl
         << "Introduza qualquer caracter para prosseguir" << endl;

    cin >> filename;

    return 0;
}

int ThirdFaseMenu(const FarmFresh2You &farm, Graph<int> &graph) {

    newWindow();

    string filenameBaskets, filenameTrucks, resFilename, any;
    cout << "Introduza o nome do ficheiro que contem os cabazes" << endl;
    cin >> filenameBaskets;

    cout << "Introduza o nome do ficheiro que contem os camioes" << endl;
    cin >> filenameTrucks;

    cout << "Introduza o nome do ficheiro que irá conter os resultados" << endl;
    cin >> resFilename;

    newWindow();

    try {
        thirdPhaseAlgorithm(farm, graph, filenameBaskets, filenameTrucks, resFilename);
    }catch (FileNotFound f){
        cout << "Não foi possivel encontrar o ficheiro " << f.getFilename() << "." << endl;
        cout << "Introduza qualquer caracter para prosseguir" << endl;

        cin >> any;
        return 0;
    }catch (VerticeNotFound<int> v){
        cout << "O vertice de id " << to_string(v.getInfo()) << "não existe." << endl;
        cout << "Introduza qualquer caracter para prosseguir" << endl;
        cin >> any;
        return 0;
    }

    cout << "Algoritmo realizado com sucesso!" << endl
         << "Introduza qualquer caracter para prosseguir" << endl;

    cin >> any;
    return 0;
}

void newWindow() {
    for (int i = 0; i < 20; i++){
        cout << endl;
    }
}


