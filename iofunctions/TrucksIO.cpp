//
// Created by debor on 23/05/2020.
//

#include "TrucksIO.h"

vector<Truck> readTrucksFromFile(const string &filename) {
    vector<Truck> result;

    ifstream infile(filename);

    if(!infile.is_open())
        throw FileNotFound(filename);


    double capacity;
    string type;

    string temp;

    while(getline(infile, temp)){
        capacity = stod(temp);

        getline(infile, temp);
        type = temp;

        Truck truck(capacity, type, vector<Basket>());
        result.push_back(truck);

        getline(infile, temp);
    }

    infile.close();

    return result;
}