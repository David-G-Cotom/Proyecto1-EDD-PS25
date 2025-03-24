//
// Created by Carlos Cotom on 23/03/2025.
//

#ifndef GAME_H
#define GAME_H

#include "Movement.h"
#include "Player.h"
#include "../structs/list/LinkedList.h"


class Game {

private:
    Player *player;
    double time;
    LinkedList<Movement> *movements;

public:
    Game(Player *player, double time, LinkedList<Movement> *movements);
    ~Game();

    Player *getPlayer();
    void setPlayer(Player *player);

    double getTime();
    void setTime(double time);

    LinkedList<Movement> *getMovements();
    void setMovements(LinkedList<Movement> *movements);

};



#endif //GAME_H
