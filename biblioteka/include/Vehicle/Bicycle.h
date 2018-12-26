//
// Created by pobi on 26.12.18.
//

#ifndef POBIPROJECT_BICYCLE_H
#define POBIPROJECT_BICYCLE_H


#include "Vehicle.h"

class Bicycle : public Vehicle{

public:
    Bicycle(std::string id, double baseRentPrice);
    virtual ~Bicycle(){};
    virtual std::string vehicleInfo();
};

typedef std::shared_ptr<Bicycle> bicycle_ptr;

#endif //POBIPROJECT_BICYCLE_H
