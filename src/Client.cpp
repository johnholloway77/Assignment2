//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Client.h"

#include <unordered_map>


void Client::addAnimal(std::unique_ptr<BaseAnimal> animal) {


    auto result = _animalsByName.find(animal->getName());

    if (result != _animalsByName.end()) {
        std::cout << "Client already has animal with this name" << std::endl;
        return;
    }

    BaseAnimal &animalReference = addAnimalToVector(std::move(animal));
    addAnimalToMap(animalReference);
}

void Client::addAnimalToMap(BaseAnimal &animalReference) {
    // _animalsByName[animalReference.getName()] = std::ref(animalReference);
    _animalsByName.emplace(animalReference.getName(), std::ref(animalReference));
}

BaseAnimal &Client::addAnimalToVector(std::unique_ptr<BaseAnimal> animal) {

    _animals.push_back(std::move(animal));
    return *_animals.back();

}


BaseAnimal &Client::getAnimal(const std::string &animalName) {
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

void Client::updateAnimalName(BaseAnimal &animal, std::string newName) {

    _animalsByName.erase(animal.getName());

    animal.setName(newName);

    _animalsByName.emplace(animal.getName(), animal);
}