//
// Created by Ricardo Nunes on 18/05/2020.
//

#include "Basket.h"

Basket::Basket(int dest, int idClient, int invoice, double weight, double volume) : dest(dest), idClient(idClient),invoice(invoice), weight(weight),volume(volume) {}

int Basket::getDest() const {
    return dest;
}





