//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Client.h"

#include <unordered_map>


void Client::addAnimal(std::shared_ptr<BaseAnimal> animal) {


    auto result = _animalsByName.find(animal->getName());

    if (result != _animalsByName.end()) {
        std::cout << "Client already has animal with this name" << std::endl;
        return;
    }

    addAnimalToVector(animal);
    addAnimalToPhoneMap(animal);
}

void Client::addAnimalToPhoneMap(std::shared_ptr<BaseAnimal> animal) {
    _animalsByName.emplace(animal->getName(), animal);
}

void Client::addAnimalToVector(std::shared_ptr<BaseAnimal> animal) {

    _animals.push_back(animal);


}


std::shared_ptr<BaseAnimal> Client::getAnimal(const std::string &animalName) {
    auto iterator = _animalsByName.find(animalName);

    if (iterator != _animalsByName.end()) {
        return (iterator->second);
    } else {
        throw std::out_of_range("Animal not found: " + animalName);
    }
}

const std::string &Client::getName() const {
    return _name;
}


int Client::getPhoneNumber() {
    return _phoneNumber;
}

void Client::updateAnimalName(std::shared_ptr<BaseAnimal> animal, const std::string &newName) {

    _animalsByName.erase(animal->getName());

    animal->setName(newName);

    _animalsByName.emplace(animal->getName(), animal);
}