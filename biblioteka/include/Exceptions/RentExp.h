//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_RENTEXP_H
#define POBIPROJECT_RENTEXP_H

#include <stdexcept>

class RentExp : public std::logic_error {
public:
    RentExp(std::string s);
};



#endif //POBIPROJECT_RENTEXP_H
