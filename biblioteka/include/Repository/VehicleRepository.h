//
// Created by pobi on 28.12.18.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H

#include <memory>
#include <string>
#include <vector>

class Vehicle;

typedef std::shared_ptr<Vehicle> vehicle_ptr;

class VehicleRepository {

    std::vector<vehicle_ptr> vehicles;

public:

    VehicleRepository();
    ~VehicleRepository();
    std::string vehicleReport();
    vehicle_ptr findVehicle(int nr);
    void addVehicle(vehicle_ptr vehicle);
    void removeVehicle(vehicle_ptr vehicle);
};

typedef std::shared_ptr<VehicleRepository> vehicleRepository_ptr;

#endif //POBIPROJECT_VEHICLEREPOSITORY_H
