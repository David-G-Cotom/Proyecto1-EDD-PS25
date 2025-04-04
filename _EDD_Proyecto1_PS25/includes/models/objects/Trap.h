//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef TRAP_H
#define TRAP_H

#include "Object.h"


class Trap : public Object {

private:
    int level;
    int damage;
    bool wasFound;

public:
    void setImage(std::string image) override;

    Trap(int level, int damage);

    int getLevel();
    void setLevel(int level);

    int getDamage();
    void setDamage(int damage);

    bool getWasFound();
    void setWasFound(bool wasFound);

};



#endif //TRAP_H
