//
// Created by pobi on 26.12.18.
//

#include "Repository/RentsRepository.h"
#include "Rent/Rent.h"
#include "Client/Client.h"
#include "Vehicle/Vehicle.h"
#include "Exceptions/RepositoryExp.h"
#include <sstream>
#include <Repository/RentsRepository.h>

void RentsRepository::addRent(rent_ptr rent) {
    rents.push_back(rent);
}

void RentsRepository::removeRent(rent_ptr rent) {
    int i = 0;
    bool flag = false;
    while((i < rents.size()) && (flag!= true)){
        if(rents[i]->getRentId() == rent->getRentId()){
            rents.erase(rents.begin()+i);
            flag = true;
        }
        i++;
    }
}

client_ptr RentsRepository::getClientForRentedVehicle(vehicle_ptr vehicle) {
    for(auto i:rents){
        if(i->vechicleId() == vehicle->getID()){
            return i->getClient();
        }
    }
    return nullptr;
}

std::string RentsRepository::rentReport() {
    std::ostringstream sout;
    for(auto i:rents){
        sout << i->rentInfo() << std::endl;
    }
    return sout.str();
}

std::vector<rent_ptr> RentsRepository::getRents() {
    return rents;
}

rent_ptr RentsRepository::findRent(rent_ptr rent) {
    for(auto i:rents){
        if(i->getRentId() == rent->getRentId()) return i;
    }
    return nullptr;
}
