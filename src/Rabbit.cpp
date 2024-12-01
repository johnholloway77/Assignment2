//
// Created by jholloway on 12/1/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include <iostream>
#include "../include/Rabbit.h"

std::string Rabbit::getColour() const {
  return colourToString(colour_);
}

std::string Rabbit::getMarking() const {
  return markingToString(marking_);
}