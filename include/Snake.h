//
// Created by jholloway on 12/1/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_SNAKE_H_
#define ASSIGN2_INCLUDE_SNAKE_H_

#include "Reptile.h"

#define SNAKE_COLOURS \
  X(Green)            \
  X(Brown)            \
  X(Gray)             \
  X(Onyx)             \
  X(Cinnamon)         \
  X(Red)

#define SNAKE_PATTERNS \
  X(Striped)           \
  X(Reticulated)       \
  X(Solid)             \
  X(Checkerboard)      \
  X(Motted)

class Snake : public Reptile<Snake> {
public:
    enum class Colour {
#define X(name) name,
        SNAKE_COLOURS
#undef X
    };

    enum class Pattern {
#define X(name) name,
        SNAKE_PATTERNS
#undef X
    };

    Snake(std::string name, std::string breed, int birthYear,
          Reptile::Order order, Snake::Colour colour, Snake::Pattern pattern)
            : Reptile<Snake>(name, breed, birthYear, order) {
        this->colour_ = colour;
        this->pattern_ = pattern;
    }

    //   std::string getOrder();

//  std::string getColour() const override;
//    std::string getPattern() const override;


protected:
    friend class Reptile<Snake>;

    Pattern pattern_;
    Colour colour_;

    static std::string colourToString(Colour colour) {
        switch (colour) {
#define X(name)      \
  case Colour::name: \
    return #name;
            SNAKE_COLOURS
#undef X

            default:
                return "Unknown";
        }
    };

    static std::string patternToString(Pattern pattern) {
        switch (pattern) {
#define X(name)       \
  case Pattern::name: \
    return #name;
            SNAKE_PATTERNS
#undef X

            default:
                return "Unknown";
        }
    };
};

#endif  // ASSIGN2_INCLUDE_SNAKE_H_
