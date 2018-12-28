//
// Created by pobi on 28.12.18.
//

#include "Repository/VehicleRepository.h"
#include "Vehicle/Vehicle.h"
#include "Exceptions/RepositoryExp.h"
#include <sstream>

VehicleRepository::VehicleRepository() {
}

VehicleRepository::~VehicleRepository() {
}

std::string VehicleRepository::vehicleReport() {
    std::ostringstream sout;
    for(auto i:vehicles){
        sout << i->vehicleInfo() << std::endl;
    }
    return sout.str();
}

vehicle_ptr VehicleRepository::findVehicle(int nr) {
    if((nr >= (int)vehicles.size())||(nr < 0)) throw RepositoryExp("Ne ma pojazdu o takim rn indeksu");
    return vehicles[nr];
}

void VehicleRepository::addVehicle(vehicle_ptr vehicle) {
    vehicles.push_back(vehicle);
}

void VehicleRepository::removeVehicle(vehicle_ptr vehicle) {
    int i = 0;
    bool flag = false;
    while((i < (int)vehicles.size()) && (flag != true)){
        if(vehicles[i]->getID() == vehicle->getID()){
            vehicles.erase(vehicles.begin()+i);
            flag = true;
        }
        i++;
    }
}
