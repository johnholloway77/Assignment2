//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_CLIENT_H_
#define ASSIGN2_INCLUDE_CLIENT_H_

#include <iostream>

#include "Mammal.h"

class Client {
private:
    int phoneNumber_;
    std::string name_;
    std::vector<std::shared_ptr<BaseAnimal>> animals_;
    std::unordered_map<std::string, std::shared_ptr<BaseAnimal>> animalsByName_;

    void addAnimalToVector(std::shared_ptr<BaseAnimal> animal);

    void addAnimalToNameMap(std::shared_ptr<BaseAnimal> animal);


public:
    int getPhoneNumber();

    Client(std::string name, int phoneNumber)
            : name_(name), phoneNumber_(phoneNumber) {}

    void addAnimal(std::shared_ptr<BaseAnimal> animal);

    std::shared_ptr<BaseAnimal> getAnimal(const std::string &name);

    const std::string &getName() const;

    void updateAnimalName(std::shared_ptr<BaseAnimal> animal, const std::string &newName);

};

#endif  // ASSIGN2_INCLUDE_CLIENT_H_
