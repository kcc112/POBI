//
// Created by pobi on 28.12.18.
//

#ifndef POBIPROJECT_CLIENTTYPE_H
#define POBIPROJECT_CLIENTTYPE_H

#include <memory>

class ClientType {

public:
    virtual double discount(double x) = 0;
    virtual int maxVehicle() = 0;
    virtual ~ClientType() = default;
};

typedef std::shared_ptr<ClientType> clientType_ptr;

#endif //POBIPROJECT_CLIENTTYPE_H
