//
// Created by pobi on 28.12.18.
//

#include "Client/ClientGold.h"

double ClientGold::discount(double x) {
    return x - (x/4.0);
}

int ClientGold::maxVehicle() {
    return 3;
}
