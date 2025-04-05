//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/models/Movement.h"

Movement::Movement(const int x, const int y, const int z, std::string event, const int remainingLife) {
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

void Movement::setX(const int x) {
    this->x = x;
}

int Movement::getY() {
    return this->y;
}

void Movement::setY(const int y) {
    this->y = y;
}

int Movement::getZ() {
    return this->z;
}

void Movement::setZ(const int z) {
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

void Movement::setRemainingLife(const int remainingLife) {
    this->remainingLife = remainingLife;
}

std::string Movement::convertToString() {
    return  "Coordenada X: " + std::to_string(this->x) +
            ", Coordenada Y: " + std::to_string(this->y) +
            ", Coordenada Z: " + std::to_string(this->z) +
            "\nEvento: " + this->event +
            "\nVida restante: " + std::to_string(this->remainingLife);
}


