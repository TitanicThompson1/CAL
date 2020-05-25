//
// Created by debor on 23/05/2020.
//

#include <Truck.h>
#include "thirdPhase.h"
#include "heldKarp.h"


/**
 *
 * @param farm : node from where all deliveries start
 * @param graph : graph imported
 * @param filenameB : file with all the baskets to be delivered
 * @param filenameT : file with all the trucks of FarmFresh2You
 * @param resultFilename : file where the results will be kept
 */
void thirdPhaseAlgorithm(const FarmFresh2You &farm, Graph<int> &graph, const string &filenameB,  const string &filenameT, const string &resultFilename) {

    //Import baskets from file
    vector<Basket> baskets = readBasketsFromFile(filenameB);
    vector<Basket> basketsCopy = baskets;

    //Import trucks from file
    vector<Truck> trucks = readTrucksFromFile(filenameT);

    //Create counter for truck capacity
    double currentCapacity=0.0;

    // Treat trucks
    // Fill trucks with a number of baskets
    // The amount of volume occupied by the baskets is either smaller or equal to truck capacity
    for (auto it = trucks.begin(); it != trucks.end() && !baskets.empty(); it++) {
        auto itB = basketsCopy.begin();
        auto maxCap = (*it).getCap();
        while (currentCapacity < maxCap && itB != basketsCopy.end() && !(basketsCopy.empty())) {
            if(maxCap >= currentCapacity + (*itB).getVolume()){
                currentCapacity += (*itB).getVolume();
                (*it).addBasket(*itB);
                itB = basketsCopy.erase(itB);
                itB--;
            }
            itB++;
        }
        //Use Held-Karp algorithm to find the shortest path for this particular truck
        heldKarpCore(farm.getFarm(), farm.getGarage(), (it)->getToDeliver(), graph, resultFilename); //O(|V|*2^|V|)
        currentCapacity = 0.0;
    }
}


