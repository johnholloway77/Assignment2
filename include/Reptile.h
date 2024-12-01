//
// Created by jholloway on 12/1/24.
// Copyright (c) [2024] John Holloway. All Rights Reserved.
//


#include <iostream>
#include "BaseAnimal.h"

#define ORDERS    \
  X(Testudines)   \
  X(Crocodilians) \
  X(Squamata)     \
  X(Rhynchocephalia)


  template <typename Child>
class Reptile: public BaseAnimal{

 public:

  enum class Colour{};
  enum class Order{
#define X(name) name,
    ORDERS
#undef X
  };

  std::string getOrder(){
    return Child::getOrder();
  };

  virtual std::string getColour() const override = 0 ;
  virtual std::string getPattern() const  = 0 ;

  std::string getName() const override {
    return name_;
  }

  std::string getBreed() const{
    return breed_;
  }
  int getBirthYear() const {
    return birthYear_;
  }

 protected:

  static std::string orderToString(Order order){
    switch(order){
#define X(name) case Order::name: return #name;
      ORDERS
#undef X
    }
  }

  //Colour colour;
  Order order_;

  Reptile(const std::string& name, const std::string& breed, int birthYear, Reptile::Order order): BaseAnimal(name, breed, birthYear){
    this->order_ = order;
  };





};