//
// Created by Ricardo Nunes on 18/05/2020.
//

#include "FarmFresh2You.h"

FarmFresh2You::FarmFresh2You(int delivery, int garage) : farm(delivery), garage(garage) {}


int FarmFresh2You::getGarage() const {
    return garage;
}

int FarmFresh2You::getFarm() const {
    return farm;
}
