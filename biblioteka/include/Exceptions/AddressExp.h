//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_ADDRESSEXP_H
#define POBIPROJECT_ADDRESSEXP_H


#include <stdexcept>

class AddressExp : public std::logic_error {
public:
    AddressExp(std::string s);
};



#endif //POBIPROJECT_ADDRESSEXP_H
