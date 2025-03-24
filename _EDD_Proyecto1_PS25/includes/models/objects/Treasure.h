//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef TREASURE_H
#define TREASURE_H

#include "Object.h"


class Treasure : public Object {

public:
    void setImage(std::string image) override;

    Treasure();

};



#endif //TREASURE_H
