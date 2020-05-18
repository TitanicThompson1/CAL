//
// Created by Ricardo Nunes on 13/05/2020.
//
#include <vector>

#include "Graphio.h"
#include "Graph.h"
#include "Menus.h"
#include "FarmerFresh2YouIO.h"
#include "FarmFresh2You.h"

int main(){

    FarmFresh2You farm = readCompanyFromFile("FarmFresh2You/farm.txt");


    Graph<int> graph = readGraph("maps/GridGraphs/4x4/nodes.txt", "maps/GridGraphs/4x4/edges.txt");

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
                currentOption = SecondFaseMenu(graph);
                break;
            case 4:
                currentOption = ThirdFaseMenu(graph);
                break;
        }
    }

    return 0;



}
