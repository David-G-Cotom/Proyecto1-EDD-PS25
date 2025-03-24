//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Movement.h"
#include "../structs/list/LinkedList.h"

class Player {

private:
    const int LIFE_LIMIT = 100;
    int life;
    std::string name;
    int score;
    LinkedList<Movement> *movements;

public:
    Player(std::string name);
    ~Player();

    int getLife();
    void setLife(int life);

    int getLIFE_LIMIT();

    std::string getName();
    void setName(std::string name);

    int getScore();
    void setScore(int score);

    LinkedList<Movement> *getMovements();
    void setMovements(LinkedList<Movement> *movements);

    bool getDamage(int damage);
    void getHealth(int health);

};



#endif //PLAYER_H
