//
// Created by jholloway on 12/2/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//
#include <gtest/gtest.h>
#include "../include/Snake.h"

TEST(SnakeTest, ConstructorTest){

    auto s = std::make_unique<Snake>(
            "Slithers", "python", 1999, Snake::Order::Squamata, Snake::Colour::Green,
            Snake::Pattern::Reticulated);

    EXPECT_TRUE(s);

    EXPECT_EQ(s->getName(), "Slithers");
    EXPECT_EQ(s->getBreed(), "python");
    EXPECT_EQ(s->getBirthYear(), 1999);
    EXPECT_EQ(s->getOrder(), "Squamata");
    EXPECT_EQ(s->getColour(), "Green");
    EXPECT_EQ(s->getPattern(), "Reticulated");

}