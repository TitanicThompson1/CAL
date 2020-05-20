//
// Created by Ricardo Nunes on 18/05/2020.
//

#include "BasketsIO.h"

vector<Basket> readBasketsFromFile(const string &filename) {
    vector<Basket> result;

    ifstream infile(filename);

    if(!infile.is_open())
        throw FileNotFound(filename);

    int dest, idClient, invoice;
    double weight, volume;

    string temp;

    while(getline(infile, temp)){
        idClient = stoi(temp);

        getline(infile, temp);
        dest = stoi(temp);

        getline(infile, temp);
        weight = stod(temp);

        getline(infile, temp);
        volume = stod(temp);

        getline(infile, temp);
        invoice = stoi(temp);

        //Basket *basket = new Basket(dest, idClient, invoice, weight, volume);
        Basket basket(dest, idClient, invoice, weight, volume);
        result.push_back(basket);

        getline(infile, temp);

    }

    infile.close();

    return result;
}
