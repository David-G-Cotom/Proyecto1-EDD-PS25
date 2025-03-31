//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "HistoryController.h"
#include "ReportsController.h"
#include "../models/Board.h"
#include "../models/Game.h"
#include "../models/Player.h"
#include "../models/objects/Enemy.h"
#include "../models/objects/Track.h"
#include "../models/objects/Trap.h"
#include "../structs/list/LinkedList.h"
#include "../structs/tree/TreeBB.h"


class GameController {

private:
    Board *board;
    Player *player;
    TreeBB<Enemy> *enemiesTree;
    TreeBB<Trap> *trapsTree;
    LinkedList<Track> *tracks;
    LinkedList<Game> *gamesHistory;
    long time;
    HistoryController *historyController;
    ReportsController *reportsController;

    void initializeBoard();

public:
    GameController();
    ~GameController();

    void init();

    bool movePlayer(int x, int y, int z);

    void checkNode();

    void generateReports();

};



#endif //GAMECONTROLLER_H
