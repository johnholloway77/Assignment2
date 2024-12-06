//
// Created by jholloway on 12/2/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#include <gtest/gtest.h>
#include "../include/Client.h"
#include "../include/Clients.h"
#include "../include/Cat.h"

TEST(ClientsTest, AddClientTest) {
    std::unique_ptr<Clients> clientsThingimajig;

    EXPECT_FALSE(clientsThingimajig);

    clientsThingimajig = std::make_unique<Clients>();

    EXPECT_TRUE(clientsThingimajig);

    clientsThingimajig->addClient(std::make_shared<Client>("Timmy", 1234567890));

    auto timmy = clientsThingimajig->getClient(1234567890);

    EXPECT_EQ(timmy->getName(), "Timmy");

    EXPECT_THROW(clientsThingimajig->getClient(8675301), std::out_of_range);
}

TEST(ClientsTest, AddClientAndAnimalTest) {
    std::unique_ptr<Clients> clientsThingimajig;

    EXPECT_FALSE(clientsThingimajig);

    clientsThingimajig = std::make_unique<Clients>();

    clientsThingimajig->addClient(std::make_shared<Client>("Timmy", 1234567890));

    auto timmy = clientsThingimajig->getClient(1234567890);

    timmy->addAnimal(std::make_unique<Cat>("Josephine", "Domestic Shorthair",
                                           2021, Cat::Colour::Cinnamon,
                                           Cat::Marking::Tortoise));

    EXPECT_THROW(timmy->getAnimal("FakeName"), std::out_of_range);

    const std::shared_ptr<Cat> josie = std::dynamic_pointer_cast<Cat>(timmy->getAnimal("Josephine"));
    EXPECT_EQ(josie->getName(), "Josephine");
}

