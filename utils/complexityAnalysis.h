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

#include "aStar.h"
#include "Graphio.h"

using namespace std;

void testAStarPerfomance();

int GetMilliCount();

int GetMilliSpan(int nTimeStart);

#endif //CODE_COMPLEXITYANALYSIS_H
