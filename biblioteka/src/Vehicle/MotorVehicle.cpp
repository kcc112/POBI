//
// Created by pobi on 26.12.18.
//

#include "Vehicle/MotorVehicle.h"
#include "Exceptions/VehicleExp.h"

MotorVehicle::MotorVehicle(int engineDisplacement , std::string id , double baseRentPrice) : Vehicle(id , baseRentPrice) , engineDisplacement(engineDisplacement){
    if(engineDisplacement == 0) throw VehicleExp("engineDisplacement can't be zero");
}

double MotorVehicle::actualRentPrice() {

    double actualRentalPrice = 1;

    if(getEngineDisplacement() < 1000) actualRentalPrice = getBaseRentPrice()*1.0;
    else if(getEngineDisplacement() >= 1000 && getEngineDisplacement() <= 2000){

        double x = 0.0005*getEngineDisplacement()+0.5;
        actualRentalPrice = getBaseRentPrice()*x;
    }
    else if(getEngineDisplacement() > 2000) actualRentalPrice = getBaseRentPrice()*1.5;

    return actualRentalPrice;
}

int MotorVehicle::getEngineDisplacement(){
    return engineDisplacement;
}