//
// Created by debor on 23/05/2020.
//

#include <Truck.h>
#include "thirdPhase.h"
#include "heldKarp.h"

/*Importar read baskets from file
Camioes tratar
encher um camiao - usar held karp
encher outro - held karp*/


void thirdPhaseAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filenameB,  const string &filenameT, const string &resultFilename) {

    //Import baskets from file
    vector<Basket> baskets = readBasketsFromFile(filenameB);

    //Treat trucks
    vector<Truck> trucks = readTrucksFromFile(filenameT);
    double currentCapacity=0.0;
    for (auto it = trucks.begin(); it != trucks.end(); it++) {
        if(!baskets.empty()){
            auto itB = baskets.begin();
            while (currentCapacity <= (*it).getCap() && itB != baskets.end()) {
                //se meter no camiao, se estiver vazio os baskets, nao add mais
                currentCapacity += (*itB).getVolume();
                itB++;
                (*it).addBasket(*itB);
                itB = baskets.erase(itB);

            }
            heldKarpCore(farm.getFarm(), farm.getGarage(), (it)->getToDeliver(), graph, resultFilename);
            currentCapacity = 0.0;
        }
    }
}


