// include/SnakeGame.h

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "GameBase.h"

class SnakeGame : public GameBase {
public:
    virtual void initialize() override;
    virtual void update() override;
    virtual void render() override;
    virtual void handleInput() override;
    virtual void playSound() override;
    virtual void displayScore() const override;
private:
    int score;
    // Add SnakeGame-specific members
};

#endif // SNAKE_GAME_H

