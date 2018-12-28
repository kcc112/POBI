//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_CLIENT_H
#define POBIPROJECT_CLIENT_H

#include <string>
#include <memory>
#include <vector>

class Address;
class Rent;
class ClientType;

typedef  std::shared_ptr<Address> address_ptr;
typedef  std::shared_ptr<Rent> rent_ptr;
typedef  std::shared_ptr<ClientType> clientType_ptr;

class Client {

    std::string firstName;
    std::string lastName;
    std::string personalID;
    address_ptr registeredAddress;
    address_ptr address;
    std::vector<rent_ptr> rents;
    clientType_ptr clientType;

public:

    Client(std::string firstName, std::string lastName, std::string personalID, address_ptr registeredAddress, address_ptr address);
    ~Client() = default;

    std::string clientInfo();
    std::string getFirstName();
    std::string getLastName();
    std::string getPersonalID();
    std::vector<rent_ptr> getRents();
    clientType_ptr getClientType();
    void setClientType(clientType_ptr type);
    void setRent(rent_ptr rent);
    void eraseRent(rent_ptr rent);
    double discount(double x);
};

typedef std::shared_ptr<Client> client_ptr;

#endif //POBIPROJECT_CLIENT_H
