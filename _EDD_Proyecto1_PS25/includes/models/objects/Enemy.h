//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"


class Enemy : public Object {

private:
    int level;
    int damage;

public:
    void setImage(std::string image) override;

    Enemy(int level, int damage);

    int getLevel();
    void setLevel(int level);

    int getDamage();
    void setDamage(int damage);

};



#endif //ENEMY_H
