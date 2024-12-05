//
// Created by jholloway on 12/2/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/BaseAnimal.h"

#include <iostream>

const std::string &BaseAnimal::getBreed() const {
    return breed_;
};

const std::string &BaseAnimal::getName() const {
    return name_;
}

void const BaseAnimal::setName(const std::string &name) {
    name_ = name;
}

int BaseAnimal::getBirthYear() const {
    return birthYear_;
}
