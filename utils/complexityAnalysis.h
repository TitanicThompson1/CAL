//
// Created by Ricardo Nunes on 19/05/2020.
//

#ifndef CODE_COMPLEXITYANALYSIS_H
#define CODE_COMPLEXITYANALYSIS_H

#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <iomanip>

#include "heldKarp.h"
#include "thirdPhase.h"
#include "aStar.h"
#include "Graphio.h"

using namespace std;

void testAStarPerfomance1();

void testAStarPerfomance2();

double registerTime(Graph<int> graph, const string &input, const string &output);

void testHeldKarpPerformance();

double registerTime3Phase(Graph<int> graph, const string &inputBaskets, const string &inputTrucks, const string &output);

void testThirdPhasePerformance();

void testConnectivity();

double registerTimeConnectivity(Graph<int> &graph);

#endif //CODE_COMPLEXITYANALYSIS_H
