//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_DATEEXP_H
#define POBIPROJECT_DATEEXP_H


#include <stdexcept>

class DateExp : public std::logic_error {
public:
    DateExp(std::string s);
};

#endif //POBIPROJECT_DATEEXP_H
