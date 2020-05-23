//
// Created by Ricardo Nunes on 18/05/2020.
//

#include "Truck.h"

Truck::Truck(double cap, const string &type, vector<Basket> toDeliver) : cap(cap), type(type), toDeliver(toDeliver)  {}

double Truck::getCap() const {
    return cap;
}

void Truck::setCap(double cap) {
    Truck::cap = cap;
}

const string &Truck::getType() const {
    return type;
}

void Truck::setType(const string &type) {
    Truck::type = type;
}

const vector<Basket> &Truck::getToDeliver() const {
    return toDeliver;
}

void Truck::setToDeliver(const vector<Basket> &toDeliver) {
    Truck::toDeliver = toDeliver;
}

void Truck::addBasket(Basket newB) {
    toDeliver.push_back(newB);
}


