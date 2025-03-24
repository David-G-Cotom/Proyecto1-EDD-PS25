//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../../includes/models/objects/Trap.h"

void Trap::setImage(std::string image) {
    this->image = image;
}

Trap::Trap(int level, int damage) {
    this->level = level;
    this->damage = damage;
}

int Trap::getLevel() {
    return this->level;
}

void Trap::setLevel(int level) {
    this->level = level;
}

int Trap::getDamage() {
    return this->damage;
}

void Trap::setDamage(int damage) {
    this->damage = damage;
}


