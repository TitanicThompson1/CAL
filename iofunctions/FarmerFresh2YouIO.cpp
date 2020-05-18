//
// Created by Ricardo Nunes on 18/05/2020.
//

#include "FarmerFresh2YouIO.h"

FarmFresh2You readCompanyFromFile(const string &filename){
    ifstream infile(filename);

    int delivery, garage;
    string temp;

    getline(infile,temp);
    delivery = stoi(temp);

    getline(infile,temp);
    garage = stoi(temp);

    FarmFresh2You farmFresh2You(delivery, garage);

    infile.close();
    return farmFresh2You;
}
