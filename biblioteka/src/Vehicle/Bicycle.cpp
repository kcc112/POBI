//
// Created by pobi on 26.12.18.
//

#include "Vehicle/Bicycle.h"
#include <sstream>

Bicycle::Bicycle(std::string id, double baseRentPrice) : Vehicle(id, baseRentPrice) {
}

std::string Bicycle::vehicleInfo() {
    std::ostringstream sout;
    sout << "BICYCLE INFORMATIONS:" << std::endl;
    sout << "Id: " << getID() << std::endl;
    sout << "Base Rent Price: " << getBaseRentPrice() << std::endl;
    sout << "Actual rental price: " << actualRentPrice() << std::endl;
    return sout.str();
}

