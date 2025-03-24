//
// Created by Carlos Cotom on 23/03/2025.
//

#include "../../includes/models/Game.h"

Game::Game(Player *player, double time, LinkedList<Movement> *movements) {
    this->player = player;
    this->time = time;
    this->movements = movements;
}

Game::~Game() {
    delete movements;
    delete player;
}

Player *Game::getPlayer() {
    return this->player;
}

void Game::setPlayer(Player *player) {
    this->player = player;
}

double Game::getTime() {
    return this->time;
}

void Game::setTime(double time) {
    this->time = time;
}

LinkedList<Movement> *Game::getMovements() {
    return this->movements;
}

void Game::setMovements(LinkedList<Movement> *movements) {
    this->movements = movements;
}




