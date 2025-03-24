//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/models/Player.h"

Player::Player(int life, std::string name, int score) {
    this->life = life;
    this->name = name;
    this->score = score;
}

Player::~Player() = default;

int Player::getLife() {
    return this->life;
}

void Player::setLife(int life) {
    this->life = life;
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




