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
    std::string oldName = name_;
    name_ = name;
    notifyIObserver(oldName, name);
}

int BaseAnimal::getBirthYear() const {
    return birthYear_;
}

void BaseAnimal::addIObserver(std::weak_ptr<IObserver> i_observer) {
    i_observers_.push_back(i_observer);
}

void BaseAnimal::notifyIObserver(const std::string &oldName, const std::string &newName) {
    for (auto iterator = i_observers_.begin();
         iterator != i_observers_.end();) {

        if (auto i_observer = iterator->lock()) {
            i_observer->onAnimalNameChange(oldName, newName);
            iterator++;
        } else {
            iterator = i_observers_.erase(iterator);

        }
    }
}