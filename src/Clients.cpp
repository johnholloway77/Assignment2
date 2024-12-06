//
// Created by jholloway on 12/2/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Clients.h"

#include <unordered_map>

void Clients::addClient(std::shared_ptr<Client> client) {

    auto result = clientsByPhoneNumber_.find(client->getPhoneNumber());

    if (result != clientsByPhoneNumber_.end()) {
        std::cout << "Client list already includes client with this phone number" << std::endl;
    }

    addClientToPhoneMap(client);
    addClientToVector(client);

}

void Clients::addClientToPhoneMap(std::shared_ptr<Client> client) {
    clientsByPhoneNumber_.emplace(client->getPhoneNumber(), client);
}

void Clients::addClientToVector(std::shared_ptr<Client> client) {
    clients_.push_back(client);
}


std::shared_ptr<Client> Clients::getClient(int phoneNumber) {
    auto iterator = clientsByPhoneNumber_.find(phoneNumber);

    if (iterator != clientsByPhoneNumber_.end() && iterator->second) {
        return iterator->second;
    } else {

        throw std::out_of_range("Client not found with number: " + std::to_string(phoneNumber));
    }
}


//Client& findClient(Client*){
//    std::cout << "I don't know what this is suppose to do. Why would you want to find an object you already have?";
//
//    return nullptr;
//}