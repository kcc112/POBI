//
// Created by pobi on 25.12.18.
//

#include "Vehicle/Vehicle.h"
#include "Exceptions/VehicleExp.h"
#include <sstream>

Vehicle::Vehicle(std::string id, int baseRentPrice) : id(id), baseRentPrice(baseRentPrice){
    if(baseRentPrice == 0) throw VehicleExp("Base rent Price can't be zero");
    if(id == "") throw VehicleExp("Empty id");
}

std::string Vehicle::vehicleInfo() {
    std::ostringstream sout;
    sout << "ID: " << getID() <<" " << "baseRentPrice: " << getBaseRentPrice() <<" ";
    return sout.str();
}

std::string Vehicle::getID() {
    return id;
}

int Vehicle::getBaseRentPrice() {
    return baseRentPrice;
}
