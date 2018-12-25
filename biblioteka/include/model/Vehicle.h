//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_VEHICLE_H
#define POBIPROJECT_VEHICLE_H

#include <memory>
#include <string>

class Vehicle {

    std::string id;
    int baseRentPrice;

public:

    Vehicle(std::string id, int baseRentPrice);

    std::string vehicleInfo();
    std::string getID();
    int getBaseRentPrice();

};

typedef std::shared_ptr<Vehicle> vehicle_ptr;

#endif //POBIPROJECT_VEHICLE_H
