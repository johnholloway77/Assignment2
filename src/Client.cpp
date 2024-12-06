//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Client.h"

#include <unordered_map>


void Client::addAnimal(std::shared_ptr<BaseAnimal> animal) {


    auto result = animalsByName_.find(animal->getName());

    if (result != animalsByName_.end()) {
        std::cout << "Client already has animal with this name" << std::endl;
        return;
    }

    addAnimalToVector(animal);
    addAnimalToPhoneMap(animal);
}

void Client::addAnimalToPhoneMap(std::shared_ptr<BaseAnimal> animal) {
    animalsByName_.emplace(animal->getName(), animal);
}

void Client::addAnimalToVector(std::shared_ptr<BaseAnimal> animal) {

    animals_.push_back(animal);


}


std::shared_ptr<BaseAnimal> Client::getAnimal(const std::string &animalName) {
    auto iterator = animalsByName_.find(animalName);

    if (iterator != animalsByName_.end()) {
        return (iterator->second);
    } else {
        throw std::out_of_range("Animal not found: " + animalName);
    }
}

const std::string &Client::getName() const {
    return name_;
}


int Client::getPhoneNumber() {
    return phoneNumber_;
}

void Client::updateAnimalName(std::shared_ptr<BaseAnimal> animal, const std::string &newName) {

    animalsByName_.erase(animal->getName());

    animal->setName(newName);

    animalsByName_.emplace(animal->getName(), animal);
}