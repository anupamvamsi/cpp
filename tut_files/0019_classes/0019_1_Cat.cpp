#include "0019_1_Cat.hpp"

#include <cctype>
#include <iostream>
#include <string>

Cat::Cat() {
  std::cout << "\n";
  std::cout << "A wild cat called " << name << " has appeared!\n";
  Rename();
}

Cat::~Cat() {
  if (feed) {
    std::cout << name << " decided to stay with you forever!\n";
  } else {
    std::cout << name << " ran away.\n";
  }
}

void Cat::Rename() {  // SetCatName (Setter)
  char rename_input;

  std::cout << "Would you like to rename " << name << "? (y/n): ";
  std::cin >> rename_input;
  std::cin.ignore();

  if (std::tolower(rename_input) == 'y') {
    std::string temp = name;
    std::cout << "Enter a new name! ";
    std::getline(std::cin, name);

    std::cout << "You renamed " << temp << " to ";
    std::cout << name << "!\n";
  }
}

void Cat::Speak() {
  std::cout << "Mrowrrr.\t(:3)\n";

  if (hungry) {
    std::cout << "Meeww...\t(:3o)\n";
    Cat::Feed();

    if (angry) {
      std::cout << "MROWWWW!\t(>:3)\n";
    } else {
      std::cout << "Mew!\t\t(:3>)\n";
    }
  }
}

void Cat::Speak(std::string name) {  // overload
  std::cout << "Meow, " << name << "!\n";
}

void Cat::Feed() {
  char feed_input;

  std::cout << "Oh! Looks like " << name << " is hungry!\n";
  std::cout << "Feed " << name << "? (y/n): ";
  std::cin >> feed_input;
  std::cin.ignore();

  if (std::tolower(feed_input) == 'y') {
    feed = true;
    hungry = false;
  } else {
    angry = true;
  }
}