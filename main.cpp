#include <iostream>

#include "include/Cat.h"
#include "include/Dog.h"
#include "include/Client.h"
#include "include/Rabbit.h"
#include "include/Snake.h"

int main() {

  std::unique_ptr<Client> timmy = std::make_unique<Client>("Timmy", 1234567890);

  timmy->addAnimal(std::make_unique<Cat>("Josephine", "Domestic Shorthair", 2021, Cat::Colour::Cinnamon, Cat::Marking::Tortoise));
  timmy->addAnimal(std::make_unique<Dog>("Old Yeller", "Golden retriever", 1950, Dog::Colour::Yellow, Dog::Marking::Merle));
  timmy->addAnimal(std::make_unique<Rabbit>("Buggs", "Bunny", 1938, Rabbit::Colour::Gray, Rabbit::Marking::Solid));
  timmy->addAnimal(std::make_unique<Snake>("Slithers", "python", 1999, Snake::Order::Squamata, Snake::Colour::Green, Snake::Pattern::Reticulated));

  try{

    Dog& oldYeller = dynamic_cast<Dog&>(timmy->getAnimal("Old Yeller"));

    std::cout << "Name: " << oldYeller.getName() << "\n\tBreed: " << oldYeller.getBreed() << "\n\tBirth year: " << oldYeller.getBirthYear() << std::endl;
    std::cout << "\tColour: " << oldYeller.getColour() << "\n\tMarking: " << oldYeller.getMarking() << std::endl;
  } catch(const std::out_of_range& ex){
    std::cout << "No doggy\n";
  }


  Cat& josie = dynamic_cast<Cat&>(timmy->getAnimal("Josephine"));

  std::cout << "Name: " << josie.getName() << std::endl << "\tBreed: " << josie.getBreed() << "\n\tBirth year: " << josie.getBirthYear() << std::endl;
  std::cout << "\tColour: " << josie.getColour() << std::endl << "\tMarking: " << josie.getMarking() << std::endl;

try{
  Cat& lucky =  dynamic_cast<Cat&>(timmy->getAnimal("lucky"));
  std::cout << "Name: " << lucky.getName() << std::endl << "\tBreed: " << lucky.getBreed() << "\n\tBirth year: " << lucky.getBirthYear() << std::endl;
} catch(const std::out_of_range& ex){
  std::cout << "No kitty :(\n";
}

try{
  Rabbit& buggs = dynamic_cast<Rabbit&>(timmy->getAnimal("Buggs"));
  std::cout << "Name: " << buggs.getName() << std::endl << "\tBreed: " << buggs.getBreed() << "\n\tBirth year: " << buggs.getBirthYear() << std::endl;
  std::cout << "\tColour: " << buggs.getColour() << std::endl << "\tMarking: " << buggs.getMarking() << std::endl;

}catch(const std::out_of_range& ex){
  std::cout << "No bunny\n";
}


try{
  Snake& snakey = dynamic_cast<Snake&>(timmy->getAnimal("Slithers"));
  std::cout << "Name: " << snakey.getName() << std::endl << "\tOrder: " << snakey.getOrder() << "\n\tBreed: " << snakey.getBreed() << "\n\tBirth year: " << snakey.getBirthYear() << std::endl;
  std::cout << "\tColour: " << snakey.getColour() << std::endl << "\tMarking: " << snakey.getPattern() << std::endl;

}catch(const std::out_of_range& ex){
  std::cout << "No Snake\n";
}

  return 0;
}
