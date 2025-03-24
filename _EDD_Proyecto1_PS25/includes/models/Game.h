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
    double time;
    int movements;

public:
    Game(std::string playerName, int score, double time, int movements);
    ~Game();

    std::string getPlayerName();
    void setPlayerName(std::string playerName);

    int getScore();
    void setScore(int score);

    double getTime();
    void setTime(double time);

    int getMovements();
    void setMovements(int movements);

};



#endif //GAME_H
