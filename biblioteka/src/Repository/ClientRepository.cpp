//
// Created by pobi on 28.12.18.
//

#include <Repository/ClientRepository.h>

#include "Repository/ClientRepository.h"
#include "Client/Client.h"

void ClientRepository::addClient(client_ptr client) {
    clientList.push_back(client);
}

void ClientRepository::removeClient(client_ptr client) {
    int i = 0;
    bool flag = false;
    while((i < clientList.size()) && (flag!= true)){
        if(clientList[i]->getPersonalID() == client->getPersonalID()){
            clientList.erase(clientList.begin()+i);
            flag = true;
        }
        i++;
    }
}

void ClientRepository::removeClientById(int nr) {
    clientList.erase(clientList.begin()+nr);
}

void ClientRepository::changeType(client_ptr client, clientType_ptr clientType) {
    client->setClientType(clientType);
}

client_ptr ClientRepository::findClient(client_ptr client) {

    for(auto i:clientList){
        if(i->getPersonalID() == client->getPersonalID()) return i;
    }
    return nullptr;
}
