//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../../includes/models/objects/Enemy.h"

void Enemy::setImage(std::string image) {
    this->image = image;
}

Enemy::Enemy(int level, int damage) {
    this->level = level;
    this->damage = damage;
}

int Enemy::getLevel() {
    return this->level;
}

void Enemy::setLevel(int level) {
    this->level = level;
}

int Enemy::getDamage() {
    return this->damage;
}

void Enemy::setDamage(int damage) {
    this->damage = damage;
}


