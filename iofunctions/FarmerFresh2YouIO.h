//
// Created by Ricardo Nunes on 18/05/2020.
//

#ifndef CODE_FARMERFRESH2YOUIO_H
#define CODE_FARMERFRESH2YOUIO_H

#include <string>
#include <fstream>
#include "FarmFresh2You.h"

using namespace std;

/**
 * Reads the company from a file, returning it on a object FarmFresh2You
 * @param filename name of the file that contains the company
 * @return object of type FarmFresh2You
 */
FarmFresh2You readCompanyFromFile(const string &filename);


#endif //CODE_FARMERFRESH2YOUIO_H
