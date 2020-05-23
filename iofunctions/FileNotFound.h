//
// Created by Ricardo Nunes on 19/05/2020.
//

#ifndef CODE_FILENOTFOUND_H
#define CODE_FILENOTFOUND_H

#include <iostream>

using namespace std;

/**
 * Error class for a file not found
 */
class FileNotFound {
    string filename;
public:
    FileNotFound(const string &filename) : filename(filename) {}

    const string &getFilename() const {
        return filename;
    }
};


#endif //CODE_FILENOTFOUND_H
