//
// Created by jholloway on 12/1/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_RABBIT_H_
#define ASSIGN2_INCLUDE_RABBIT_H_

#include "Mammal.h"

#define RABBIT_COLOURS \
  X(Black)             \
  X(Brown)             \
  X(Gray)              \
  X(White)

#define RABBIT_MARKINGS \
  X(Solid)              \
  X(Spotted)            \
  X(Patches)

class Rabbit : public Mammal<Rabbit> {
public:
    enum class Colour {
#define X(name) name,
        RABBIT_COLOURS
#undef X
    };

    enum class Marking {
#define X(name) name,
        RABBIT_MARKINGS
#undef X
    };

    Rabbit(std::string name, std::string breed, int birthYear,
           Rabbit::Colour colour, Rabbit::Marking marking)
            : Mammal<Rabbit>(name, breed, birthYear) {
        this->colour_ = colour;
        this->marking_ = marking;
    };


private:
    friend class Mammal<Rabbit>;

    Colour colour_;
    Marking marking_;

    static std::string markingToStringImplementation(Marking marking) {
        switch (marking) {
#define X(name)       \
  case Marking::name: \
    return #name;
            RABBIT_MARKINGS
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
            RABBIT_COLOURS
#undef X

            default:
                return "Unknown";
        }
    };
};

#endif  // ASSIGN2_INCLUDE_RABBIT_H_
