//
// Created by pobi on 26.12.18.
//

#include "Repository/CurrentRentsRepository.h"
#include "Rent/Rent.h"
#include "Client/Client.h"
#include "Vehicle/Vehicle.h"
#include "Exceptions/RepositoryExp.h"
#include <sstream>
#include <Repository/CurrentRentsRepository.h>


CurrentRentsRepository::CurrentRentsRepository() {
}

CurrentRentsRepository::~CurrentRentsRepository() {
}

void CurrentRentsRepository::addRent(rent_ptr rent) {
    rents.push_back(rent);
}

void CurrentRentsRepository::removeRent(rent_ptr rent) {
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

client_ptr CurrentRentsRepository::getClientForRentedVehicle(vehicle_ptr vehicle) {
    for(auto i:rents){
        if(i->vechicleId() == vehicle->getID()){
            return i->getClient();
        }
        else{
            throw RepositoryExp("Nie ma takiego pojazdu");
        }
    }
}

std::string CurrentRentsRepository::rentReport() {
    std::ostringstream sout;
    for(auto i:rents){
        sout << i->rentInfo() << std::endl;
    }
    return sout.str();
}

std::vector<rent_ptr> CurrentRentsRepository::getRents() {
    return rents;
}
