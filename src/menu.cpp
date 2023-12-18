// src/Menu.cpp

#include "Menu.h"
#include <iostream>

Menu::Menu(const std::vector<std::string> &options) : menuOptions(options) {}

int Menu::displayMenu() {
  // Display menu options
  std::cout << "Choose a game to play:" << std::endl;
  for (size_t i = 0; i < menuOptions.size(); ++i) {
    std::cout << i + 1 << ". " << menuOptions[i] << std::endl;
  }

  // Get user choice
  int choice;
  std::cout << "Enter your choice (0 to exit): ";
  std::cin >> choice;

  return choice;
}
