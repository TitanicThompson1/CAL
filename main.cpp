//
// Created by Ricardo Nunes on 13/05/2020.
//
#include <vector>

#include "Graphio.h"
#include "Graph.h"
#include "Menus.h"
#include "FarmerFresh2YouIO.h"
#include "FileNotFound.h"
#include "complexityAnalysis.h"

FarmFresh2You setUpRoutine();

int main(){


    FarmFresh2You farm = setUpRoutine();

    Graph<int> graph = readGraph();

    graph.dfsRemoveUnvisited(farm.getFarm());

    int currentOption = 0;

    while(currentOption != -1){
        switch (currentOption){
            case 0:
                currentOption = InitialMenu(graph);
                break;
            case 1:
                currentOption = VisualizeGraphMenu(graph);
                break;
            case 2:
                currentOption = FirstFaseMenu(farm, graph);
                break;
            case 3:
                currentOption = SecondFaseMenu(farm, graph);
                break;
            case 4:
                currentOption = ThirdFaseMenu(farm, graph);
                break;
        }
    }

    return 0;
}

/**
 * This function reads the company from a file, returning an object of type FarmFresh2You.
 * If the file doesnt exist, it asks the user until it has a valid file.
 * @return the company
 */
FarmFresh2You setUpRoutine() {

    string filename;
    cout << "Introduza o nome do ficheiro da companhia" << endl;
    cin >> filename;

    bool unvalid = true;
    FarmFresh2You farmFresh2You;
    while(unvalid){
        unvalid = false;
        try {
            farmFresh2You = readCompanyFromFile(filename);
        }catch (FileNotFound fileNotFound){
            unvalid = true;
            cout << "O ficheiro '"<< fileNotFound.getFilename() << "' nao existe. Por favor introduza outra vez" << endl;
            cin >> filename;
        }
    }

    return farmFresh2You;
}
