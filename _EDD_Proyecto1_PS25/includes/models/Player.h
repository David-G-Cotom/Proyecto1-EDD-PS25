//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player {

private:
    int life;
    const int LIFE_LIMIT = life;
    std::string name;
    int score;

public:
    Player(int life, std::string name, int score);
    ~Player();

    int getLife();
    void setLife(int life);

    std::string getName();
    void setName(std::string name);

    int getScore();
    void setScore(int score);

    bool getDamage(int damage);
    void getHealth(int health);

};



#endif //PLAYER_H
