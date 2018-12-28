//
// Created by pobi on 25.12.18.
//

#include "Client/Client.h"
#include "Exceptions/ClientExp.h"
#include "Address/Address.h"
#include "Client/ClientTypes.h"
#include "Rent/Rent.h"
#include <sstream>
#include <Client/Client.h>


Client::Client(std::string firstName, std::string lastName, std::string personalID, address_ptr registeredAddress, address_ptr address ) :firstName(firstName),lastName(lastName), personalID(personalID), registeredAddress(registeredAddress), address(address){
    if(firstName.empty()) throw ClientExp("Empty firstName");
    if(lastName.empty()) throw ClientExp("Empty lastName");
    if(personalID.empty()) throw ClientExp("Empty personalID");
    clientType = clientType_ptr(new ClientSilver());
}

std::string Client::clientInfo() {

    std::ostringstream sout;
    sout << "firstName: " << getFirstName() <<" "<< "lastName: " << getLastName() <<" "<< "personalID: " << getPersonalID() << std::endl;
    if(registeredAddress != nullptr) sout << "registeredAddressInfo: " << registeredAddress->addressInfo() << std::endl;
    if(address != nullptr) sout << "addressInfo" <<  address->addressInfo() << std::endl;
    return sout.str();
}

std::string Client::getFirstName() {
    return firstName;
}

std::string Client::getLastName() {
    return lastName;
}

std::string Client::getPersonalID() {
    return personalID;
}

std::vector<rent_ptr> Client::getRents() {
    return rents;
}

void Client::setRent(rent_ptr rent) {
    rents.push_back(rent);
}

void Client::eraseRent(rent_ptr rent) {

    int i = 0;
    bool flag = false;
    while((i < (int)rents.size()) && (flag != true)){
        if(rents[i]->getRentId() == rent->getRentId()){
            rents.erase(rents.begin()+i);
            flag = true;
        }
        i++;
    }
}

clientType_ptr Client::getClientType() {
    return clientType;
}

void Client::setClientType(clientType_ptr type) {
    clientType = type;
}

double Client::discount(double x) {
    return clientType->discount(x);
}
