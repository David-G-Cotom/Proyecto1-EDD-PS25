//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "../models/Game.h"
#include "../models/Player.h"
#include "../models/objects/Enemy.h"
#include "../models/objects/Object.h"
#include "../models/objects/Track.h"
#include "../models/objects/Trap.h"
#include "../models/objects/Treasure.h"
#include "../structs/list/LinkedList.h"
#include "../structs/matrix/OrthogonalMatrix.h"
#include "../structs/tree/TreeBB.h"


class GameController {

private:
    OrthogonalMatrix<Object> *board;
    Player *player;
    Treasure *treasure; // NodeMatrix<Treasure> *nodeTreasure
    TreeBB<Enemy> *enemiesTree;
    TreeBB<Trap> *trapsTree;
    LinkedList<Track> *tracks;
    LinkedList<Game> *gamesHistory;
    long time;

public:
    GameController();
    ~GameController();

    void init();

    bool movePlayer(int x, int y, int z);

    void checkNode();

    void generateReports();

};



#endif //GAMECONTROLLER_H
