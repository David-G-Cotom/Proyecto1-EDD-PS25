//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../../includes/models/objects/Trap.h"

void Trap::setImage(std::string image) {
    this->image = image;
}

Trap::Trap(const int level, const int damage) {
    this->level = level;
    this->damage = damage;
    this->wasFound = false;
}

int Trap::getLevel() {
    return this->level;
}

void Trap::setLevel(const int level) {
    this->level = level;
}

int Trap::getDamage() {
    return this->damage;
}

void Trap::setDamage(const int damage) {
    this->damage = damage;
}

bool Trap::getWasFound() {
    return this->wasFound;
}

void Trap::setWasFound(const bool wasFound) {
    this->wasFound = wasFound;
}


