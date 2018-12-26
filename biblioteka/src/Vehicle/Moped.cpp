//
// Created by pobi on 26.12.18.
//

#include "Vehicle/Moped.h"
#include <sstream>

Moped::Moped(int engineDisplacement, std::string id, double baseRentPrice) : MotorVehicle(engineDisplacement, id,baseRentPrice) {
}

std::string Moped::vehicleInfo() {
    std::ostringstream sout;
    sout << "MOPRD INFORMATIONS:" << std::endl;
    sout << "Id: " << getID() << std::endl;
    sout << "Base Rent Price: " << getBaseRentPrice() << std::endl;
    sout << "Actual rental price: " << actualRentPrice() << std::endl;
    sout << "Pojemnosc silnika: " << getEngineDisplacement()<< std::endl;
    return sout.str();
}
