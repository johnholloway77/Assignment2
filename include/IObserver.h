//
// Created by jholloway on 12/5/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_IOBSERVER_H
#define ASSIGN2_IOBSERVER_H

#include <iostream>

class IObserver {
public:
    virtual void onAnimalNameChange(const std::string &oldName, const std::string &newName) = 0;

    virtual ~IObserver() = default;
};

#endif //ASSIGN2_IOBSERVER_H

