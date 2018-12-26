//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_VEHICLE_H
#define POBIPROJECT_VEHICLE_H

#include <memory>
#include <string>

class Vehicle {

    std::string id;
    double baseRentPrice;

public:

    Vehicle(std::string id, double baseRentPrice);

    virtual std::string vehicleInfo() = 0;
    virtual std::string getID();
    virtual double getBaseRentPrice();
    virtual double actualRentPrice();

};

typedef std::shared_ptr<Vehicle> vehicle_ptr;

#endif //POBIPROJECT_VEHICLE_H
