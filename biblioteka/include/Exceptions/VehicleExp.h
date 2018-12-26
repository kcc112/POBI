//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_VEHICLEEXP_H
#define POBIPROJECT_VEHICLEEXP_H


#include <stdexcept>

class VehicleExp : public std::logic_error {
public:
    VehicleExp(std::string s);
};



#endif //POBIPROJECT_VEHICLEEXP_H
