//
// Created by pobi on 25.12.18.
//

#include "Vehicle/Vehicle.h"
#include "Exceptions/VehicleExp.h"

Vehicle::Vehicle(std::string id, double baseRentPrice) : id(id), baseRentPrice(baseRentPrice){
    if(baseRentPrice == 0.0) throw VehicleExp("Base rent Price can't be zero");
    if(id == "") throw VehicleExp("Empty id");
}


std::string Vehicle::getID() {
    return id;
}

double Vehicle::getBaseRentPrice() {
    return baseRentPrice;
}

double Vehicle::actualRentPrice(){
    return getBaseRentPrice();
}