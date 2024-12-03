//
// Created by jholloway on 12/2/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Clients.h"

#include <unordered_map>

void Clients::addClient(std::unique_ptr<Client> client) {
    auto result = clientsByPhoneNumber.insert({client->getPhoneNumber(), std::move(client)});

    if (!result.second){
        std::cout << "Client already exists with this phone number" << std::endl;
    }
}

Client& Clients::getClient(int phoneNumber) {
    auto iterator = clientsByPhoneNumber.find(phoneNumber);

    if(iterator != clientsByPhoneNumber.end() && iterator->second){
        return *(iterator->second);
    } else{

        throw std::out_of_range("Client not found with number: " + std::to_string(phoneNumber));
    }
}


//Client& findClient(Client*){
//    std::cout << "I don't know what this is suppose to do. Why would you want to find an object you already have?";
//
//    return nullptr;
//}