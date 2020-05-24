//
// Created by Ricardo Nunes on 14/05/2020.
//

#ifndef CODE_MENUS_H
#define CODE_MENUS_H

#include "Graph.h"
#include "graphviewer.h"
#include "aStar.h"
#include "FarmFresh2You.h"
#include "heldKarp.h"
#include "thirdPhase.h"
#include "complexityAnalysis.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>



int InitialMenu(Graph<int> &graph);

/**
 * This menu allows the user to visualize the graph using GraphViewer
 * @param graph graph to see
 * @return next menu
 */
int VisualizeGraphMenu(Graph<int> &graph);

/**
 * This menu applies the A* algorithm to solve fase 1
 * @param farm farm the contains the id of the begining vertice, and the id of the destination vertice
 * @param graph graph to perfom A* to
 * @return next menu
 */
int FirstFaseMenu(const FarmFresh2You &farm, Graph<int> &graph);

int SecondFaseMenu(const FarmFresh2You &farm, Graph<int> &graph);

int ThirdFaseMenu(const FarmFresh2You &farm, Graph<int> &graph);

/**
 * Function that simulates a new window on the console
 */
void newWindow();

#endif //CODE_MENUS_H
