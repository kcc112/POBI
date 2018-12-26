//
// Created by pobi on 26.12.18.
//

#ifndef POBIPROJECT_REPOSITORYEXP_H
#define POBIPROJECT_REPOSITORYEXP_H


#include <stdexcept>

class RepositoryExp : public std::logic_error {
public:
    RepositoryExp(std::string s);
};


#endif //POBIPROJECT_REPOSITORYEXP_H
