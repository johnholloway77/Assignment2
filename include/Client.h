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
    std::vector<std::shared_ptr<BaseAnimal>> _animals;
    std::unordered_map<std::string, std::shared_ptr<BaseAnimal>> _animalsByName;

    void addAnimalToVector(std::shared_ptr<BaseAnimal> animal);

    void addAnimalToMap(std::shared_ptr<BaseAnimal> animal);


public:
    int getPhoneNumber();

    Client(std::string name, int phoneNumber)
            : _name(name), _phoneNumber(phoneNumber) {}

    void addAnimal(std::shared_ptr<BaseAnimal> animal);

    std::shared_ptr<BaseAnimal> getAnimal(const std::string &name);

    const std::string &getName() const;

    void updateAnimalName(std::shared_ptr<BaseAnimal> animal, const std::string &newName);

};

#endif  // ASSIGN2_INCLUDE_CLIENT_H_
