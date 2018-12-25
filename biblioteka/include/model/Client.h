//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_CLIENT_H
#define POBIPROJECT_CLIENT_H

#include <string>
#include <memory>

class Address;

typedef  std::shared_ptr<Address> address_ptr;

class Client {

    std::string firstName;
    std::string lastName;
    std::string personalID;
    address_ptr registeredAddress;
    address_ptr address;

public:

    Client(std::string firstName, std::string lastName, std::string personalID, address_ptr registeredAddress, address_ptr address);

    std::string clientInfo();
    std::string getFirstName();
    std::string getLastName();
    std::string getPersonalID();
};

typedef std::shared_ptr<Client> client_ptr;


#endif //POBIPROJECT_CLIENT_H
