//
// Created by pobi on 26.12.18.
//

#ifndef POBIPROJECT_CURRENTRENTSREPOSITORY_H
#define POBIPROJECT_CURRENTRENTSREPOSITORY_H

#include <memory>
#include <vector>
#include <string>

class Rent;
class Vehicle;
class Client;

typedef std::shared_ptr<Rent> rent_ptr;
typedef std::shared_ptr<Vehicle> vehicle_ptr;
typedef std::shared_ptr<Client> client_ptr;

class RentsRepository {

    std::vector<rent_ptr> rents;

public:
    RentsRepository() = default;
    ~RentsRepository() = default;

    void addRent(rent_ptr rent);
    void removeRent(rent_ptr rent);
    client_ptr getClientForRentedVehicle(vehicle_ptr vehicle);
    std::string rentReport();
    std::vector<rent_ptr> getRents();
    rent_ptr findRent(rent_ptr rent);
};

typedef std::shared_ptr<RentsRepository> rentsRepository_ptr;

#endif //POBIPROJECT_CURRENTRENTSREPOSITORY_H
