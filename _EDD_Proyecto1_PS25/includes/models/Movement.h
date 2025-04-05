//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <string>


class Movement {

private:
    int x, y, z;
    std::string event;
    int remainingLife;

public:
    Movement(int x, int y, int z, std::string event, int remainingLife);
    ~Movement();

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);

    int getZ();
    void setZ(int z);

    std::string getEvent();
    void setEvent(std::string event);

    int getRemainingLife();
    void setRemainingLife(int remainingLife);

    std::string convertToString();

};



#endif //MOVEMENT_H
