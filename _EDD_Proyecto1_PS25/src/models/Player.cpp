//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/models/Player.h"

#include <iostream>

void Player::setImage(std::string image) {
    this->image = image;
}

Player::Player(std::string name) {
    this->life = this->LIFE_LIMIT;
    this->name = name;
    this->score = 0;
    this->movements = new LinkedList<Movement>();
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
    std::cout << "Has Recibido: " << damage << " de Damage" << std::endl;
    this->life -= damage;
    std::cout << "Perdiste: " << damage << " Puntos" << std::endl;
    this->score -= damage;
    if (this->life <= 0) {
        this->life = 0;
        return true;
    }
    return false;
}

void Player::getHealth(int health) {
    std::cout << "Has Recibido: " << health << " de Salud" << std::endl;
    this->life += health;
    std::cout << "Ganaste: " << health / 2 << " Puntos" << std::endl;
    this->score += health / 2;
    if (this->life > this->LIFE_LIMIT) {
        this->life = this->LIFE_LIMIT;
    }
}




