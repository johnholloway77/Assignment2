//
// Created by jholloway on 12/6/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INAMECHANGENOTIFIER_H
#define ASSIGN2_INAMECHANGENOTIFIER_H

#include "INameObserver.h"

#ifdef __linux__
#include <memory>
#endif


class INameChangeNotifier {
public:
    virtual void addIObserver(std::weak_ptr<INameObserver> i_observer) = 0;

    virtual void notifyIObserverNameChange(const std::string &oldName, const std::string &newName) = 0;

    virtual ~INameChangeNotifier() = default;

};

#endif //ASSIGN2_INAMECHANGENOTIFIER_H
