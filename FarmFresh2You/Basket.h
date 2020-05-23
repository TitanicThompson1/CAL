//
// Created by Ricardo Nunes on 18/05/2020.
//

#ifndef CODE_BASKET_H
#define CODE_BASKET_H


class Basket {
private:
    int dest, idClient, invoice;
    double weight, volume;

public:
    Basket(int dest, int idClient, int invoice, double weight, double volume);

    int getDest() const;

    double getVolume() const;

    void setVolume(double volume);

};


#endif //CODE_BASKET_H
