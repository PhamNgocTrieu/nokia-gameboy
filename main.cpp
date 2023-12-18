// main.cpp

#include "AudioManager.h"
#include "ConsoleRenderer.h"
#include "GameRegistry.h"
#include "InputManager.h"
#include "Menu.h"
#include "PongGame.h"
#include "SnakeGame.h"

#include <iostream>

int main() {
  GameRegistry gameRegistry;

  SnakeGame snakeGame;
  PongGame pongGame;

  ConsoleRenderer consoleRenderer;
  InputManager inputManager;
  AudioManager audioManager;

  // Register games with the game registry
  gameRegistry.registerGame(&snakeGame);
  gameRegistry.registerGame(&pongGame);

  // Create a menu
  Menu gameMenu({"Snake Game", "Pong Game", "Exit"});

  int choice;
  do {
    choice = gameMenu.displayMenu();

    switch (choice) {
    case 1:
      // Run Snake Game
      gameRegistry.runAllGames();
      break;
    case 2:
      // Run Pong Game
      gameRegistry.runAllGames();
      break;
    case 0:
      // Exit the program
      std::cout << "Exiting the program." << std::endl;
      break;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
      break;
    }

  } while (choice != 0);

  return 0;
}

