//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_CLIENTS_H_
#define ASSIGN2_INCLUDE_CLIENTS_H_

#include <iostream>

#include "Client.h"

class Clients {
private:
    std::vector<std::shared_ptr<Client>> clients_;
    std::unordered_map<int, std::shared_ptr<Client>> clientsByPhoneNumber_;

    void addClientToVector(std::shared_ptr<Client> client);

    void addClientToPhoneMap(std::shared_ptr<Client>);

public:
    void addClient(std::shared_ptr<Client> client);

    std::shared_ptr<Client> getClient(int phoneNumber);

    Client *findClient(Client *);
};

#endif  // ASSIGN2_INCLUDE_CLIENTS_H_
