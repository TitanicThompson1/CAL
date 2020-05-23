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

/**
 * Reads all baskets from a file, returning them on a vector
 * @param filename name of the file containing the basket
 * @return vector containing the baskets
 */
vector<Basket> readBasketsFromFile(const string &filename);


#endif //CODE_BASKETSIO_H
