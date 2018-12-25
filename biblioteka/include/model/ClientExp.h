//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_CLIENTEXP_H
#define POBIPROJECT_CLIENTEXP_H


#include <stdexcept>

class ClientExp : public std::logic_error {
public:
    ClientExp(std::string s);
};


#endif //POBIPROJECT_CLIENTEXP_H
