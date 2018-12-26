//
// Created by pobi on 25.12.18.
//

#include "Rent/Rent.h"
#include "Exceptions/RentExp.h"
#include "Date/RentDateTime.h"
#include "Client/Client.h"
#include "Vehicle/Vehicle.h"
#include <sstream>
#include <Rent/Rent.h>


Rent::Rent(client_ptr client, vehicle_ptr vehicle, rentDateTime_ptr date) : client(client) , vehicle(vehicle), date(date){
    client->setRent(rent_ptr(this));
}

int Rent::rentDayNumber() {
    return date->currentRentDuration();
}

double Rent::countRentPrice() {
     return date->rentDuration()*vehicle->getBaseRentPrice();
}

std::string Rent::rentInfo() {
    std::ostringstream sout;
    sout << "Rent Id: " << getRentId() << std::endl;
    sout << "Start Date: " << date->getBegin() << std::endl;
    sout << "End day: " << date->rentDuration() << std::endl;//albo ile trwala renta albo na ile dni zostala stworzona
    sout << "Client Info" << client->clientInfo() << std::endl;
    sout << "Vehicle info" << vehicle->vehicleInfo() << std::endl;
    return sout.str();
}

std::string Rent::clientID() {
    return client->getPersonalID();
}

std::string Rent::vechicleId() {
    return vehicle->getID();
}

boost::uuids::uuid Rent::getRentId() {
    return rentId;
}

void Rent::returnVehicle() {
    client->eraseRent(rent_ptr(this));
    date->endRentDate();
}

int Rent::rentEndDate(){
    return date->rentDuration();
}

client_ptr Rent::getClient() {
    return client;
}
