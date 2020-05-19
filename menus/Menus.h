//
// Created by Ricardo Nunes on 14/05/2020.
//

#ifndef CODE_MENUS_H
#define CODE_MENUS_H

#include "Graph.h"
#include "graphviewer.h"
#include "aStar.h"
#include "FarmFresh2You.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>


int InitialMenu(Graph<int> &graph);

int VisualizeGraphMenu(Graph<int> &graph);

int FirstFaseMenu(const FarmFresh2You &farm, Graph<int> &graph);

int SecondFaseMenu(Graph<int> &graph);

int ThirdFaseMenu(Graph<int> &graph);

void newWindow();

#endif //CODE_MENUS_H
