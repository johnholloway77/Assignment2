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
    addAnimalToNameMap(animal);
}

void Client::addAnimalToNameMap(std::shared_ptr<BaseAnimal> animal) {
    animalsByName_.emplace(animal->getName(), animal);
}

void Client::addAnimalToVector(std::shared_ptr<BaseAnimal> animal) {

    std::weak_ptr<IObserver> clientWeakPointer = shared_from_this();

    animal->addIObserver(clientWeakPointer);
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

void Client::onNotifierNameChange(const std::string &oldName, const std::string &newName) {


    auto iterator = animalsByName_.find(oldName);

    if (iterator != animalsByName_.end()) {

        auto animal = iterator->second;
        animalsByName_.erase(oldName);
        animalsByName_.emplace(newName, animal);
    }


}