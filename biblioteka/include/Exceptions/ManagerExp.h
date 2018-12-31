//
// Created by pobi on 31.12.18.
//

#ifndef POBIPROJECT_MANAGEREXP_H
#define POBIPROJECT_MANAGEREXP_H


#include <stdexcept>

class ManagerExp : public std::logic_error {
public:
    ManagerExp(std::string s);
};


#endif //POBIPROJECT_MANAGEREXP_H
