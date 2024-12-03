//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Client.h"

#include <unordered_map>

void Client::addAnimal(std::unique_ptr<BaseAnimal> animal) {
  auto result = animalsByName.insert({animal->getName(), std::move(animal)});

  if (!result.second) {
    std::cout << "Client already has animal with this name" << std::endl;
  }
}

BaseAnimal& Client::getAnimal(const std::string& animalName) {
  auto iterator = animalsByName.find(animalName);

  if (iterator != animalsByName.end() && iterator->second) {
    return *(iterator->second);
  } else {
    throw std::out_of_range("Animal not found: " + animalName);
  }
}

const std::string& Client::getName() const {
  return name;
}

int Client::getPhoneNumber() {
  return phoneNumber;
}
