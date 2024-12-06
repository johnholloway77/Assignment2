//
// Created by jholloway on 12/6/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INOTIFIER_H
#define ASSIGN2_INOTIFIER_H

#include "IObserver.h"

class INotifier {
public:
    virtual void addIObserver(std::weak_ptr<IObserver> i_observer) = 0;

    virtual void notifyIObserverNameChange(const std::string &oldName, const std::string &newName) = 0;

    virtual ~INotifier() = default;

};

#endif //ASSIGN2_INOTIFIER_H
