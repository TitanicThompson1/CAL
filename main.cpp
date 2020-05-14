//
// Created by Ricardo Nunes on 13/05/2020.
//
#include "iofunctions/Graphio.h"
#include "Graph.h"
#include "Menus.h"


int main(){

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
                currentOption = FirstFaseMenu(graph);
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
