//
// Created by jholloway on 12/2/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//
#include <gtest/gtest.h>
#include "../include/Client.h"
#include "../include/Cat.h"

TEST(Client_Test, DoEverythingTest) {

    std::unique_ptr<Client> timmy = std::make_unique<Client>("Timmy", 1234567890);

    timmy->addAnimal(std::make_unique<Cat>("Josephine", "Domestic Shorthair",
                                           2021, Cat::Colour::Cinnamon,
                                           Cat::Marking::Tortoise));
    try {
        const Cat josie = dynamic_cast<Cat &>(timmy->getAnimal("Josephine"));
        EXPECT_EQ(josie.getName(), "Josephine");

    } catch (const std::out_of_range &ex) {
        std::cout << "No kitty :(\n";
    }

}

TEST(Client_Test, ChangeCatNameTest) {

    std::unique_ptr<Client> timmy = std::make_unique<Client>("Timmy", 1234567890);

    timmy->addAnimal(std::make_unique<Cat>("Josephine", "Domestic Shorthair",
                                           2021, Cat::Colour::Cinnamon,
                                           Cat::Marking::Tortoise));
    try {
        Cat &josie = dynamic_cast<Cat &>(timmy->getAnimal("Josephine"));
        EXPECT_EQ(josie.getName(), "Josephine");

        timmy->updateAnimalName(josie, "JosieBean");
        EXPECT_EQ(josie.getName(), "JosieBean");

        EXPECT_THROW(timmy->getAnimal("Josephine"), std::out_of_range);
        
        Cat &josie_2 = dynamic_cast<Cat &>(timmy->getAnimal("JosieBean"));

        EXPECT_EQ(josie_2.getName(), "JosieBean");

        EXPECT_THROW(timmy->getAnimal("Josephine"), std::out_of_range);

        timmy->updateAnimalName(josie_2, "Josephine");
        EXPECT_EQ(josie.getName(), "Josephine");

    } catch (const std::out_of_range &ex) {
        std::cout << "No kitty :(\n";
        FAIL();
    }

}

TEST(Client_Test, ThrowTest) {

    std::unique_ptr<Client> timmy = std::make_unique<Client>("Timmy", 1234567890);

    timmy->addAnimal(std::make_unique<Cat>("Josephine", "Domestic Shorthair",
                                           2021, Cat::Colour::Cinnamon,
                                           Cat::Marking::Tortoise));

    EXPECT_THROW(timmy->getAnimal("FakeName"), std::out_of_range);
}