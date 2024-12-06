//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_MAMMAL_H_
#define ASSIGN2_INCLUDE_MAMMAL_H_

#include <iostream>

#include "BaseAnimal.h"

template<typename Child>
class Mammal : public BaseAnimal {
protected:


public:
    Mammal(const std::string &name, const std::string &breed, int birthYear)
            : BaseAnimal(name, breed, birthYear) {};

    ~Mammal() = default;

    std::string getColour() const {
        const Child *child = static_cast<const Child *>(this);
        return Child::colourToStringImplementation(child->colour_);
    }

    std::string getMarking() const {
        const Child *child = static_cast<const Child *>(this);

        return Child::markingToStringImplementation(child->marking_);
        
    }
};

#endif  // ASSIGN2_INCLUDE_MAMMAL_H_
