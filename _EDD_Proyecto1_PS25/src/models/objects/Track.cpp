//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../../includes/models/objects/Track.h"

void Track::setImage(std::string image) {
    this->image = image;
}

Track::Track(std::string type, const int distance) {
    this->type = type;
    this->distance = distance;
}

std::string Track::getType() {
    return this->type;
}

void Track::setType(std::string type) {
    this->type = type;
}

int Track::getDistance() {
    return this->distance;
}

void Track::setDistance(const int distance) {
    this->distance = distance;
}


