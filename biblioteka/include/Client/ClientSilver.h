//
// Created by pobi on 28.12.18.
//

#ifndef POBIPROJECT_CLIENTSILVER_H
#define POBIPROJECT_CLIENTSILVER_H

#include "ClientType.h"

class ClientSilver : public ClientType{

public:
    ~ClientSilver() = default;
    double discount(double x);
    int maxVehicle();
};

typedef std::shared_ptr<ClientSilver> clientSilver_ptr;

#endif //POBIPROJECT_CLIENTSILVER_H
