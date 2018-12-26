//
// Created by pobi on 26.12.18.
//

#ifndef POBIPROJECT_CAR_H
#define POBIPROJECT_CAR_H


#include "MotorVehicle.h"

class Car : public MotorVehicle {

    std::string segment;

public:
    Car(std::string segment, int engineDisplacement, std::string id, double baseRentPrice);
    virtual ~Car(){};

    virtual double actualRentPrice();
    virtual std::string vehicleInfo();
    virtual std::string getSegment();
};

typedef std::shared_ptr<Car> car_ptr;

#endif //POBIPROJECT_CAR_H
