//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/models/Movement.h"

Movement::Movement(int x, int y, int z, std::string event, int remainingLife) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->event = event;
    this->remainingLife = remainingLife;
}

Movement::~Movement() = default;

int Movement::getX() {
    return this->x;
}

void Movement::setX(int x) {
    this->x = x;
}

int Movement::getY() {
    return this->y;
}

void Movement::setY(int y) {
    this->y = y;
}

int Movement::getZ() {
    return this->z;
}

void Movement::setZ(int z) {
    this->z = z;
}

std::string Movement::getEvent() {
    return this->event;
}

void Movement::setEvent(std::string event) {
    this->event = event;
}

int Movement::getRemainingLife() {
    return this->remainingLife;
}

void Movement::setRemainingLife(int remainingLife) {
    this->remainingLife = remainingLife;
}


