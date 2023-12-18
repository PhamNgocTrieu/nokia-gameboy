// include/GameBase.h

#ifndef GAME_BASE_H
#define GAME_BASE_H

class GameBase {
public:
  virtual void initialize() = 0;
  virtual void update() = 0;
  virtual void render() = 0;
  virtual void handleInput() = 0;
  virtual void playSound() = 0;
  virtual void displayScore() const = 0;
};

#endif // GAME_BASE_H

