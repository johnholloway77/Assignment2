//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Cat.h"

#include <iostream>

std::string Cat::getColour() const {
  return colourToString(colour_);
};

std::string Cat::getMarking() const {
  return markingToString(marking_);
}
