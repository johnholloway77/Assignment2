//
// Created by jholloway on 12/1/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include <iostream>

#include "BaseAnimal.h"

#define REPTILE_ORDERS \
  X(Testudines)        \
  X(Crocodilians)      \
  X(Squamata)          \
  X(Rhynchocephalia)

template<typename Child>
class Reptile : public BaseAnimal {

public:

    enum class Order {
#define X(name) name,
        REPTILE_ORDERS
#undef X
    };

    std::string getColour() const override {
        const Child *child = static_cast<const Child *>(this);
        return Child::colourToString(child->colour_);
    }

    std::string getPattern() const {
        const Child *child = static_cast<const Child *>(this);
        return Child::patternToString(child->pattern_);
    }

    std::string getOrder() const {
        return orderToString(order_);
    }

protected:

    Order order_;

    Reptile(const std::string &name, const std::string &breed, int birthYear,
            Reptile::Order order)
            : BaseAnimal(name, breed, birthYear) {
        this->order_ = order;
    };

    ~Reptile() override = default;

    static std::string orderToString(Order order) {
        switch (order) {
#define X(name)     \
  case Order::name: \
    return #name;
            REPTILE_ORDERS
#undef X
            default:
                return "Unknown";
        }
    }

};
