//
// Created by Carlos Cotom on 23/03/2025.
//

#ifndef GAME_H
#define GAME_H

#include "Player.h"


class Game {

private:
    std::string playerName;
    int score;
    long time;
    int movements;

public:
    Game(std::string playerName, int score, long time, int movements);
    ~Game();

    std::string getPlayerName();
    void setPlayerName(std::string playerName);

    int getScore();
    void setScore(int score);

    long getTime();
    void setTime(long time);

    int getMovements();
    void setMovements(int movements);

};



#endif //GAME_H
