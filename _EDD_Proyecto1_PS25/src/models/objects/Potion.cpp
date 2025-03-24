//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../../includes/models/objects/Potion.h"

void Potion::setImage(std::string image) {
    this->image = image;
}

Potion::Potion(int healing) {
    this->healing = healing;
}

int Potion::getHealing() {
    return this->healing;
}

void Potion::setHealing(int healing) {
    this->healing = healing;
}

