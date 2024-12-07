//
// Created by jholloway on 12/5/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INAMEOBSERVER_H
#define ASSIGN2_INAMEOBSERVER_H

#include <iostream>

#ifdef __linux__
#include <memory>
#include <vector>

#endif

class INameObserver {
public:
    virtual void onNotifierNameChange(const std::string &oldName, const std::string &newName) = 0;

    virtual ~INameObserver() = default;
};

#endif //ASSIGN2_INAMEOBSERVER_H

