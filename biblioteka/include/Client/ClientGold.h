//
// Created by pobi on 28.12.18.
//

#ifndef POBIPROJECT_CLIENTGOLD_H
#define POBIPROJECT_CLIENTGOLD_H

#include "ClientType.h"

class ClientGold : public ClientType{

public:
    ~ClientGold() = default;
    double discount(double x);
    int maxVehicle();
};

typedef std::shared_ptr<ClientGold> clientGold_ptr;

#endif //POBIPROJECT_CLIENTGOLD_H
