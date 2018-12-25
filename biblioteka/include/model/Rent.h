//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H


#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

class Vehicle;
class Client;
class RentDateTime;

typedef std::shared_ptr<Client> client_ptr;
typedef std::shared_ptr<Vehicle> vehicle_ptr;
typedef std::shared_ptr<RentDateTime> rentDateTime_ptr;

class Rent {

    boost::uuids::uuid rentId;
    client_ptr client;
    vehicle_ptr vehicle;
    rentDateTime_ptr date;

public:

    Rent(client_ptr client, vehicle_ptr vehicle, rentDateTime_ptr date);
    int rentDayNumber(); //liczba dni wyporzyczenia
    int rentEndDate(); //data zakonczenia
    double countRentPrice();
    std::string rentInfo();
    std::string clientID();
    std::string vechicleId();
    boost::uuids::uuid getRentId();
    void returnVehicle();
};

typedef std::shared_ptr<Rent> rent_ptr;

#endif //POBIPROJECT_RENT_H
