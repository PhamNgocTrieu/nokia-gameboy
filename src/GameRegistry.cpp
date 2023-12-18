// src/GameRegistry.cpp

#include "GameRegistry.h"

void GameRegistry::registerGame(GameBase *game) { games.push_back(game); }

void GameRegistry::runAllGames() {
  for (auto game : games) {
    game->initialize();
    while (/* game is running */) {
      game->handleInput();
      game->update();
      game->render();
      game->playSound();
      game->displayScore();
      // Add logic for game loop, etc.
    }
  }
}
