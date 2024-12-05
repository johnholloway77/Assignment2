//
// Created by jholloway on 11/30/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//

#ifndef ASSIGN2_INCLUDE_BASEANIMAL_H_
#define ASSIGN2_INCLUDE_BASEANIMAL_H_

#include <iostream>
#include <string>

class BaseAnimal {
public:
    BaseAnimal(const std::string &name, const std::string &breed, int birthYear)
            : name_(name), breed_(breed), birthYear_(birthYear) {}

    virtual ~BaseAnimal() = default;

    int getBirthYear() const;

    const std::string &getBreed() const;

    const std::string &getName() const;

private:
    friend class Client;
    
    void const setName(const std::string &name);

protected:
    std::string name_;
    std::string breed_;
    int birthYear_;

    virtual std::string getColour() const = 0;

};


#endif  // ASSIGN2_INCLUDE_BASEANIMAL_H_
