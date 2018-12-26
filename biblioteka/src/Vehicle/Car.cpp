//
// Created by pobi on 26.12.18.
//

#include "Vehicle/Car.h"
#include "Exceptions/VehicleExp.h"
#include <sstream>

Car::Car(std::string segment, int engineDisplacement, std::string id, double baseRentPrice) : MotorVehicle(engineDisplacement, id, baseRentPrice) ,segment(segment){
if(segment !="A"&&"B"&&"C"&&"D"&&"E"&&"F"&&"")  throw VehicleExp("Niepoprwny aegmwnt tylko A B C D E F");
}

double Car::actualRentPrice() {
    double i = 1.0;
    if(segment == "A") i = 1.0;
    else if(segment == "B") i = 1.0;
    else if(segment == "C") i = 1.1;
    else if(segment == "D") i = 1.2;
    else if(segment == "E") i = 1.3;
    else if(segment == "F") i = 1.5;

    return MotorVehicle::actualRentPrice()*i;
}

std::string Car::vehicleInfo() {
    std::ostringstream sout;
    sout << "CAR INFORMATIONS:" << std::endl;
    sout << "Id: " << getID() << std::endl;
    sout << "Base Rent Price: " << getBaseRentPrice() << std::endl;
    sout << "Actual rental price: " << actualRentPrice() << std::endl;
    sout << "Pojemnosc silnika: " << getEngineDisplacement()<< std::endl;
    sout << "Segment: " << getSegment() << std::endl;
    return sout.str();
}

std::string Car::getSegment(){
    return segment;
}
