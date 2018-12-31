//
// Created by pobi on 31.12.18.
//

#ifndef POBIPROJECT_RENTSMANAGER_H
#define POBIPROJECT_RENTSMANAGER_H

#include <memory>
#include <vector>

class ClientRepository;
class RentsRepository;
class VehicleRepository;
class Client;
class Vehicle;
class Rent;
class RentDateTime;

typedef std::shared_ptr<ClientRepository> clientRepository_ptr;
typedef std::shared_ptr<RentsRepository> rentsRepository_ptr;
typedef std::shared_ptr<VehicleRepository> vehicleRepository_ptr;
typedef std::shared_ptr<Client> client_ptr;
typedef std::shared_ptr<Vehicle> vehicle_ptr;
typedef std::shared_ptr<Rent> rent_ptr;
typedef std::shared_ptr<RentDateTime> rentDateTime_ptr;

class RentsManager {

    rentsRepository_ptr currentRents;
    rentsRepository_ptr archiveRents;
    clientRepository_ptr clientList;
    vehicleRepository_ptr vehicleList;

public:
    RentsManager(rentsRepository_ptr currentRents, rentsRepository_ptr archiveRents,  clientRepository_ptr clientList, vehicleRepository_ptr vehicleList);
    ~RentsManager() = default;
    void rentVehicle(client_ptr client, vehicle_ptr vehicle, rentDateTime_ptr date);
    void returnVehicle(client_ptr client, vehicle_ptr vehicle);
    std::vector<rent_ptr> getAllClientRents(client_ptr client);
    double checkClientRentBallance(client_ptr client);
};

typedef std::shared_ptr<RentsManager> rentsManager_ptr ;

#endif //POBIPROJECT_RENTSMANAGER_H
