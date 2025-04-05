//
// Created by Carlos Cotom on 23/03/2025.
//

#include "../../includes/models/Game.h"

Game::Game(std::string playerName, const int score, const long time, const int movements) {
    this->playerName = playerName;
    this->score = score;
    this->time = time;
    this->movements = movements;
}

Game::~Game() = default;

std::string Game::getPlayerName() {
    return this->playerName;
}

void Game::setPlayerName(std::string playerName) {
    this->playerName = playerName;
}

int Game::getScore() {
    return this->score;
}

void Game::setScore(const int score) {
    this->score = score;
}

long Game::getTime() {
    return this->time;
}

void Game::setTime(const long time) {
    this->time = time;
}

int Game::getMovements() {
    return this->movements;
}

void Game::setMovements(int movements) {
    this->movements = movements;
}




