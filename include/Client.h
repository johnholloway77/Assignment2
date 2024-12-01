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
  int phoneNumber;
  std::string name;
  std::unordered_map<std::string, std::unique_ptr<BaseAnimal>> animalsByName;

 public:
  Client(std::string name, int phoneNumber)
      : name(name), phoneNumber(phoneNumber) {}

  void addAnimal(std::unique_ptr<BaseAnimal> animal);
  BaseAnimal& getAnimal(const std::string& name);
  std::string getName();
  int getPhoneNumber();
};

#endif  // ASSIGN2_INCLUDE_CLIENT_H_
