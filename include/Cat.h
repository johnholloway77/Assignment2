//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_CAT_H_
#define ASSIGN2_INCLUDE_CAT_H_

#include "Mammal.h"

#define COLOURS \
  X(Black)      \
  X(Chocolate)   \
  X(Gray)       \
  X(Cream)      \
  X(Cinnamon)   \
  X(Red)

#define MARKINGS \
  X(Brindle)     \
  X(Spotted)     \
  X(Tortoise)    \
  X(Calico)      \
  X(Striped)    \
  X(Tabby)

  class Cat: public Mammal<Cat>{
 public:

  enum class Colour{
#define X(name) name,
    COLOURS
#undef X
  };

  enum class Marking{
#define X(name) name,
    MARKINGS
#undef X
  };

  Cat(std::string name, std::string breed, int birthYear, Cat::Colour colour, Cat::Marking marking): Mammal<Cat>(name, breed, birthYear){
    this->colour_ = colour;
    this->marking_ = marking;
  };

  std::string getColour() const override;
  std::string getMarking() const override;


 private:

  Colour colour_;
  Marking marking_;

    static std::string markingToString(Marking marking){
      switch (marking) {
#define X(name) case Marking::name: return #name;
        MARKINGS
#undef X

        default: return "Unknown";
      }
    };


  static std::string colourToString(Colour colour) {
    switch (colour) {
#define X(name) case Colour::name: return #name;
      COLOURS
#undef X

      default: return "Unknown";
    }
  };

};

#endif //ASSIGN2_INCLUDE_CAT_H_
