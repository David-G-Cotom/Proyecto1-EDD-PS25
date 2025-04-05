//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../../includes/models/objects/Enemy.h"

void Enemy::setImage(std::string image) {
    this->image = image;
}

Enemy::Enemy(const int level, const int damage) {
    this->level = level;
    this->damage = damage;
    this->wasFound = false;
}

int Enemy::getLevel() {
    return this->level;
}

void Enemy::setLevel(const int level) {
    this->level = level;
}

int Enemy::getDamage() {
    return this->damage;
}

void Enemy::setDamage(const int damage) {
    this->damage = damage;
}

bool Enemy::getWasFound() {
    return this->wasFound;
}

void Enemy::setWasFound(const bool wasFound) {
    this->wasFound = wasFound;
}


