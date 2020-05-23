//
// Created by Ricardo Nunes on 18/05/2020.
//

#ifndef CODE_TRUCK_H
#define CODE_TRUCK_H

#include <string>
#include <vector>
#include "Basket.h"

using namespace std;

class Truck {
    double cap;
    string type;
    vector<Basket> toDeliver ;
public:
    Truck(double cap, const string &type, vector<Basket> toDeliver);

    double getCap() const;

    void setCap(double cap);

    const string &getType() const;

    void setType(const string &type);

    const vector<Basket> &getToDeliver() const;

    void setToDeliver(const vector<Basket> &toDeliver);

    void addBasket(Basket newB);
};


#endif //CODE_TRUCK_H
