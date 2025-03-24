//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef POTION_H
#define POTION_H

#include "Object.h"


class Potion : public Object {

private:
    int healing;

public:
    void setImage(std::string image) override;

    Potion(int healing);

    int getHealing();
    void setHealing(int healing);

};



#endif //POTION_H
