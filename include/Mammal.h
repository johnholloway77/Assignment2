//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_MAMMAL_H_
#define ASSIGN2_INCLUDE_MAMMAL_H_

#include <iostream>

#include "BaseAnimal.h"

template <typename Child>
class Mammal : public BaseAnimal {
 protected:
  enum class Colour {};
  enum class Marking {};

  //    Colour colour;
  //    Marking marking;

  static std::string colourToString(Colour colour) {
    return Child::colourToString(colour);
  }

  static std::string markingToString(Marking marking) {
    return Child::markingToString(marking);
  }

 public:
  Mammal(const std::string& name, const std::string& breed, int birthYear)
      : BaseAnimal(name, breed, birthYear){};

  // virtual ~Mammal() = default;

  std::string getName() const override {
    return name_;
  }

  std::string getBreed() const {
    return breed_;
  }
  int getBirthYear() const {
    return birthYear_;
  }

  virtual std::string getColour() const override = 0;
  virtual std::string getMarking() const = 0;
};

#endif  // ASSIGN2_INCLUDE_MAMMAL_H_
