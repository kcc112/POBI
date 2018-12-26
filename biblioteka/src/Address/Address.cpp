//
// Created by pobi on 25.12.18.
//

#include "Address/Address.h"
#include "Exceptions/AddressExp.h"
#include <sstream>


Address::Address(int addressNumber, std::string streetName) : addressNumber(addressNumber), streetName(streetName){
    if(addressNumber == 0) throw AddressExp("Address number can't be zero");
    if(streetName == "") throw AddressExp("Empty streetName");
}

int Address::getAddressNumber() {
    return addressNumber;
}

std::string Address::getStreetName() {
    return streetName;
}

std::string Address::addressInfo() {
    std::ostringstream sout;
    sout << "addressNumber: " << getAddressNumber() <<" "<< "streetName: " << getStreetName() <<" ";
    return sout.str();
}
