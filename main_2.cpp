// main.cpp

#include "AudioManager.h"
#include "ConsoleRenderer.h"
#include "GameRegistry.h"
#include "InputManager.h"
#include "Menu.h"
#include "PongGame.h"
#include "SnakeGame.h"

#include <iostream>
#include <thread>

// Function to run the rendering thread
void renderingThread(GameBase *game, ConsoleRenderer *renderer) {
  while (/* game is running */) {
    game->render();
    // You can add additional rendering-related logic here
    std::this_thread::sleep_for(
        std::chrono::milliseconds(16)); // Simulate a frame rate
  }
}

// Function to run the input thread
void inputThread(GameBase *game, InputManager *inputManager) {
  while (/* game is running */) {
    game->handleInput();
    // You can add additional input-related logic here
    std::this_thread::sleep_for(
        std::chrono::milliseconds(16)); // Simulate a frame rate
  }
}

// Function to run the sound thread
void soundThread(GameBase *game, AudioManager *audioManager) {
  while (/* game is running */) {
    game->playSound();
    // You can add additional sound-related logic here
    std::this_thread::sleep_for(
        std::chrono::milliseconds(16)); // Simulate a frame rate
  }
}

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
      std::thread snakeRenderingThread(renderingThread, &snakeGame,
                                       &consoleRenderer);
      std::thread snakeInputThread(inputThread, &snakeGame, &inputManager);
      std::thread snakeSoundThread(soundThread, &snakeGame, &audioManager);
      snakeGame.initialize();
      while (/* game is running */) {
        snakeGame.update();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(16)); // Simulate a game loop
      }
      snakeRenderingThread.join(); // Wait for the rendering thread to finish
      snakeInputThread.join();     // Wait for the input thread to finish
      snakeSoundThread.join();     // Wait for the sound thread to finish
      break;
    case 2:
      // Run Pong Game
      std::thread pongRenderingThread(renderingThread, &pongGame,
                                      &consoleRenderer);
      std::thread pongInputThread(inputThread, &pongGame, &inputManager);
      std::thread pongSoundThread(soundThread, &pongGame, &audioManager);
      pongGame.initialize();
      while (/* game is running */) {
        pongGame.update();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(16)); // Simulate a game loop
      }
      pongRenderingThread.join(); // Wait for the rendering thread to finish
      pongInputThread.join();     // Wait for the input thread to finish
      pongSoundThread.join();     // Wait for the sound thread to finish
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

