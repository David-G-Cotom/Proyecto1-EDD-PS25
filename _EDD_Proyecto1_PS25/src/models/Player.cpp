//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/models/Player.h"

Player::Player(std::string name) {
    this->life = this->LIFE_LIMIT;
    this->name = name;
    this->score = 0;
    this->movements = nullptr;
}

Player::~Player() = default;

int Player::getLife() {
    return this->life;
}

void Player::setLife(int life) {
    this->life = life;
}

int Player::getLIFE_LIMIT() {
    return this->LIFE_LIMIT;
}

std::string Player::getName() {
    return this->name;
}

void Player::setName(std::string name) {
    this->name = name;
}

int Player::getScore() {
    return this->score;
}

void Player::setScore(int score) {
    this->score = score;
}

LinkedList<Movement> *Player::getMovements() {
    return this->movements;
}

void Player::setMovements(LinkedList<Movement> *movements) {
    this->movements = movements;
}

bool Player::getDamage(int damage) {
    this->life -= damage;
    if (this->life <= 0) {
        this->life = 0;
        return true;
    }
    return false;
}

void Player::getHealth(int health) {
    this->life -= health;
    if (this->life > this->LIFE_LIMIT) {
        this->life = this->LIFE_LIMIT;
    }
}




