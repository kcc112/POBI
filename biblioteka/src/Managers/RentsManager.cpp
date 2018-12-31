//
// Created by pobi on 31.12.18.
//

#include "Managers/RentsManager.h"
#include "Repository/ClientRepository.h"
#include "Repository/VehicleRepository.h"
#include "Repository/RentsRepository.h"
#include "Exceptions/ManagerExp.h"
#include "Rent/Rent.h"
#include "Client/Client.h"
#include "Client/ClientType.h"
#include "Vehicle/Vehicle.h"

RentsManager::RentsManager(rentsRepository_ptr currentRents, rentsRepository_ptr archiveRents, clientRepository_ptr clientList, vehicleRepository_ptr vehicleList) : currentRents(currentRents), archiveRents(archiveRents), clientList(clientList), vehicleList(vehicleList) {

    if(currentRents == nullptr) throw ManagerExp("NULLPTR!");
    if(archiveRents == nullptr) throw ManagerExp("NULLPTR!");
    if(clientList == nullptr) throw ManagerExp("NULLPTR!");
    if(vehicleList == nullptr) throw ManagerExp("NULLPTR!");
}

void RentsManager::rentVehicle(client_ptr client, vehicle_ptr vehicle, rentDateTime_ptr date) {
   if(clientList->findClient(client) == nullptr) throw ManagerExp("Nie ma takiego klienta w bazie ");
   else if(vehicleList->findVehicle(vehicle) == nullptr) throw ManagerExp("Nie ma takiego pojazdu w bazie ");
   else if(currentRents->getClientForRentedVehicle(vehicle) != nullptr) throw  ManagerExp("Dany pojazd jest już wypożyczony");
   else{

        clientType_ptr T = client->getClientType();
        if(T->maxVehicle() <= (int)client->getRents().size()) throw  ManagerExp("Klient nie jest w stanie wypożyczyć więcej pojazdów ze swoim aktualnym typem");
        else{
            rent_ptr R(new Rent(client, vehicle, date));
            currentRents->addRent(R);
        }
   }
}

void RentsManager::returnVehicle(client_ptr client, vehicle_ptr vehicle) {

    if(clientList->findClient(client) == nullptr) throw ManagerExp("Nie ma takiego klienta w bazie ");
    else if(vehicleList->findVehicle(vehicle) == nullptr) throw ManagerExp("Nie ma takiego pojazdu w bazie ");
    std::vector<rent_ptr> R = client->getRents();
    for(auto i:R){
        if(i->vechicleId() == vehicle->getID()){
            archiveRents->addRent(i);
            i->returnVehicle();
            client->eraseRent(i);
            currentRents->removeRent(i);
        }
        else{
            throw ManagerExp("Ten klient nie wypożyczył tego pojazdu ");
        }
    }
}

std::vector<rent_ptr> RentsManager::getAllClientRents(client_ptr client) {
    if(clientList->findClient(client) == nullptr) throw ManagerExp("Nie ma takiego klienta w bazie ");

    std::vector<rent_ptr> output;
    std::vector<rent_ptr> R = archiveRents->getRents();
    for(auto i:R){
        if(i->clientID() == client->getPersonalID()) output.push_back(i);
    }
    return output;
}

double RentsManager::checkClientRentBallance(client_ptr client) {
    if(clientList->findClient(client) == nullptr) throw ManagerExp("Nie ma takiego klienta w bazie ");
    std::vector<rent_ptr> R = archiveRents->getRents();
    double sum = 0;
    for(auto i:R){
        if(i->clientID() == client->getPersonalID()) sum+=i->countRentPrice();
    }
    return sum;
}
