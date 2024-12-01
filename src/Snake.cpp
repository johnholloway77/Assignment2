//
// Created by jholloway on 12/1/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include "../include/Snake.h"

#include <iostream>

std::string Snake::getOrder() {
  return orderToString(order_);
};

std::string Snake::getColour() const {
  return colourToString(colour_);
}

std::string Snake::getPattern() const {
  return patternToString(pattern_);
}
