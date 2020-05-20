//
// Created by Ricardo Nunes on 18/05/2020.
//

#ifndef CODE_BASKETSIO_H
#define CODE_BASKETSIO_H

#include <string>
#include <vector>
#include <fstream>
#include "Basket.h"
#include "FileNotFound.h"

using namespace std;


vector<Basket> readBasketsFromFile(const string &filename);


#endif //CODE_BASKETSIO_H
