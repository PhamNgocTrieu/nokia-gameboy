// include/GameRegistry.h

#ifndef GAME_REGISTRY_H
#define GAME_REGISTRY_H

#include "GameBase.h"
#include <vector>

class GameRegistry {
public:
  void registerGame(GameBase *game);
  void runAllGames();

private:
  std::vector<GameBase *> games;
};

#endif // GAME_REGISTRY_H

