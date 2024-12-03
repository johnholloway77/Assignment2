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
  std::unordered_map<int, std::unique_ptr<Client>> clientsByPhoneNumber;

 public:
  void addClient(std::unique_ptr<Client> client);
  Client& getClient(int phoneNumber);
  Client& findClient(Client*);
};

#endif  // ASSIGN2_INCLUDE_CLIENTS_H_
