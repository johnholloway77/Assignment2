//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_DOG_H_
#define ASSIGN2_INCLUDE_DOG_H_

#include "Mammal.h"

#define DOG_COLOURS \
  X(Black)          \
  X(Chocolate)      \
  X(Gray)           \
  X(Gold)           \
  X(White)          \
  X(Yellow)

#define DOG_MARKINGS \
  X(Brindle)         \
  X(Spotted)         \
  X(TwoColour)       \
  X(Merle)           \
  X(Tricolour)       \
  X(Tudexo)

class Dog : public Mammal<Dog> {
public:
    enum class Colour {
#define X(name) name,
        DOG_COLOURS
#undef X
    };

    enum class Marking {
#define X(name) name,
        DOG_MARKINGS
#undef X
    };

    Dog(std::string name, std::string breed, int birthYear, Dog::Colour colour,
        Dog::Marking marking)
            : Mammal<Dog>(name, breed, birthYear) {
        this->colour_ = colour;
        this->marking_ = marking;
    };

//  std::string getColour() const override;
//  std::string getMarking() const override;

private:
    friend class Mammal<Dog>;

    Colour colour_;
    Marking marking_;

    static std::string markingToStringImplementation(Marking marking) {
        switch (marking) {
#define X(name)       \
  case Marking::name: \
    return #name;
            DOG_MARKINGS
#undef X

            default:
                return "Unknown";
        }
    };

    static std::string colourToStringImplementation(Colour colour) {
        switch (colour) {
#define X(name)      \
  case Colour::name: \
    return #name;
            DOG_COLOURS
#undef X

            default:
                return "Unknown";
        }
    };
};

#endif  // ASSIGN2_INCLUDE_DOG_H_
