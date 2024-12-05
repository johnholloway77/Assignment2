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
    int _phoneNumber;
    std::string _name;
    std::vector<std::unique_ptr<BaseAnimal>> _animals;
    std::unordered_map<std::string, std::reference_wrapper<BaseAnimal>> _animalsByName;

    BaseAnimal &addAnimalToVector(std::unique_ptr<BaseAnimal> animal);

    void addAnimalToMap(BaseAnimal &animalReference);


public:
    int getPhoneNumber();

    Client(std::string name, int phoneNumber)
            : _name(name), _phoneNumber(phoneNumber) {}

    void addAnimal(std::unique_ptr<BaseAnimal> animal);

    BaseAnimal &getAnimal(const std::string &name);

    const std::string &getName() const;

    void updateAnimalName(BaseAnimal &animal, std::string newName);
    
};

#endif  // ASSIGN2_INCLUDE_CLIENT_H_
