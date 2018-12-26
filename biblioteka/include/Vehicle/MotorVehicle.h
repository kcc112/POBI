//
// Created by pobi on 26.12.18.
//

#ifndef POBIPROJECT_MOTORVEHICLE_H
#define POBIPROJECT_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle : public Vehicle{

    int engineDisplacement;

public:
    MotorVehicle(int engineDisplacement, std::string id, double baseRentPrice);
    virtual ~MotorVehicle(){};

    virtual std::string vehicleInfo() = 0;
    virtual double actualRentPrice();
    virtual int getEngineDisplacement();
};


#endif //POBIPROJECT_MOTORVEHICLE_H
