//
// Created by Carlos Cotom on 22/03/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include "../structs/matrix/NodeMatrix.h"
#include "../structs/matrix/OrthogonalMatrix.h"
#include "../structs/tree/TreeBB.h"
#include "objects/Enemy.h"
#include "objects/Trap.h"
#include "objects/Treasure.h"


class Board {

private:
    OrthogonalMatrix<Object> *orthogonalMatrix;
    NodeMatrix<Treasure> *treasureNode;

public:
    Board(int dimensionX, int dimensionY, int dimensionZ);
    ~Board();

    NodeMatrix<Treasure> *getTreasureNode();
    void setTreasureNode(NodeMatrix<Treasure> *);

    void createBoard();
    void deleteBoard();

    void putTreasure();
    void putEnemys(TreeBB<Enemy> &enemysTree);
    void putTraps(TreeBB<Trap> &trapsTree);
    void putPotions();
    void putTracks();
    void completeBoard();

    void printBoard();

};



#endif //BOARD_H
