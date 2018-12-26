//
// Created by pobi on 25.12.18.
//

#include "Client/Client.h"
#include "Exceptions/ClientExp.h"
#include "Address/Address.h"
#include <Rent/Rent.h>
#include <sstream>
#include <Client/Client.h>


Client::Client(std::string firstName, std::string lastName, std::string personalID, address_ptr registeredAddress, address_ptr address ) :firstName(firstName),lastName(lastName), personalID(personalID), registeredAddress(registeredAddress), address(address){
    if(firstName == "") throw ClientExp("Empty firstName");
    if(lastName == "") throw ClientExp("Empty lastName");
    if(personalID == "") throw ClientExp("Empty personalID");
}

std::string Client::clientInfo() {

    std::ostringstream sout;
    sout << "firstName: " << getFirstName() <<" "<< "lastName: " << getLastName() <<" "<< "personalID: " << getPersonalID() << std::endl;
    if(registeredAddress!=NULL) sout << "registeredAddressInfo: " << registeredAddress->addressInfo() << std::endl;
    if(address!=NULL) sout << "addressInfo" <<  address->addressInfo() << std::endl;
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

    for(int i = 0; i<rents.size(); i++){
        if(rents[i] == rent){
            rents.erase(rents.begin() + i);
        }
    }
}
