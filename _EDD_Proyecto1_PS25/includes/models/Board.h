//
// Created by Carlos Cotom on 22/03/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "../structs/matrix/NodeMatrix.h"
#include "../structs/matrix/OrthogonalMatrix.h"
#include "../structs/tree/TreeBB.h"
#include "objects/Enemy.h"
#include "objects/Trap.h"


class Board {

private:
    OrthogonalMatrix<Object> *orthogonalMatrix;
    NodeMatrix<Object> *treasureNode;
    NodeMatrix<Object> *playerNode;
    Object *dataBelowThePlayer;
    int totalNodes;

    void putTreasure();
    void putPlayer(Player *player);
    void putEnemies(TreeBB<Enemy> *enemiesTree);
    void putTraps(TreeBB<Trap> *trapsTree);
    void putPotions();
    void putTracks();

    std::string getTrack(int x, int y, int z);

public:
    Board(int dimensionX, int dimensionY, int dimensionZ);
    ~Board();

    OrthogonalMatrix<Object> *getOrthogonalMatrix();
    void setOrthogonalMatrix(OrthogonalMatrix<Object> *orthogonalMatrix);

    NodeMatrix<Object> *getTreasureNode();
    void setTreasureNode(NodeMatrix<Object> *treasureNode);

    NodeMatrix<Object> *getPlayerNode();
    void setPlayerNode(NodeMatrix<Object> *playerNode);

    Object *getDataBelowThePlayer();
    void setDataBelowThePlayer(Object *dataBelowThePlayer);

    int getTotalNodes();
    void setTotalNodes(int totalNodes);

    void createBoard(Player *player, TreeBB<Enemy> *enemiesTree, TreeBB<Trap> *trapsTree);
    void deleteBoard();

    void printBoard(NodeMatrix<Object> *node, NodeMatrix<Object> *root, int z = 0);

};



#endif //BOARD_H
