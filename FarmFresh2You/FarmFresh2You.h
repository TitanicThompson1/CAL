//
// Created by Ricardo Nunes on 18/05/2020.
//

#ifndef CODE_FARMFRESH2YOU_H
#define CODE_FARMFRESH2YOU_H


class FarmFresh2You {
    int farm, garage;
public:
    FarmFresh2You() {};

    FarmFresh2You(int delivery, int garage);

    int getFarm() const;

    int getGarage() const;
};


#endif //CODE_FARMFRESH2YOU_H
