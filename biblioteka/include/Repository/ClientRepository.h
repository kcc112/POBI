//
// Created by pobi on 28.12.18.
//

#ifndef POBIPROJECT_CLIENTREPOSITORY_H
#define POBIPROJECT_CLIENTREPOSITORY_H

#include <memory>
#include <vector>

class Client;
class ClientType;

typedef std::shared_ptr<Client> client_ptr;
typedef std::shared_ptr<ClientType> clientType_ptr;

class ClientRepository {

    std::vector<client_ptr> clientList;

public:

    ClientRepository() = default;
    ~ClientRepository() = default;

    void addClient(client_ptr client);
    void removeClient(client_ptr client);
    void removeClientById(int nr);
    void changeType(client_ptr client, clientType_ptr clientType);
};

typedef std::shared_ptr<ClientRepository> clientRepository_ptr;

#endif //POBIPROJECT_CLIENTREPOSITORY_H
