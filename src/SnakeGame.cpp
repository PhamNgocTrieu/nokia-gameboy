// src/SnakeGame.cpp

#include "SnakeGame.h"
#include <iostream>

void SnakeGame::initialize() {
    // Initialize SnakeGame
    score = 0;
    std::cout << "Snake Game Initialization\n";
}

void SnakeGame::update() {
    // Update SnakeGame logic
    std::cout << "Snake Game Update\n";
}

void SnakeGame::render() {
    // Render SnakeGame
    std::cout << "Snake Game Render\n";
}

void SnakeGame::handleInput() {
    // Handle input for SnakeGame
    std::cout << "Handle Snake Game Input\n";
}

void SnakeGame::playSound() {
    // Play sound for SnakeGame
    std::cout << "Play Snake Game Sound\n";
}

void SnakeGame::displayScore() const {
    // Display score for SnakeGame
    std::cout << "Snake Game Score: " << score << std::endl;
}

