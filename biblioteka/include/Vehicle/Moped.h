//
// Created by pobi on 26.12.18.
//

#ifndef POBIPROJECT_MOPED_H
#define POBIPROJECT_MOPED_H


#include "MotorVehicle.h"

class Moped : public MotorVehicle{

public:
    Moped(int engineDisplacement, std::string id, double baseRentPrice);
    ~Moped() = default;
    virtual std::string vehicleInfo();
};

typedef std::shared_ptr<Moped> moped_ptr;

#endif //POBIPROJECT_MOPED_H
