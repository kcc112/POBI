//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_ADDRESS_H
#define POBIPROJECT_ADDRESS_H

#include <string>
#include <memory>

class Address {

    int addressNumber;
    std::string streetName;

public:

    Address(int addressNumber, std::string streetName);

    int getAddressNumber();
    std::string getStreetName();
    std::string addressInfo();

};

typedef  std::shared_ptr<Address> address_ptr;

#endif //POBIPROJECT_ADDRESS_H
