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
    LinkedList<Track> *tracksFound;
    LinkedList<Game> *gamesHistory;
    long time;
    HistoryController *historyController;
    ReportsController *reportsController;
    bool gameOver;
    Game *currentGame;

    void initializeBoard();

    NodeMatrix<Object> *verifyMovement(char movement);

    void checkNode(NodeMatrix<Object> *node);

    void generateReports();

    void gameReport();

public:
    GameController();
    ~GameController();

    void init();

};



#endif //GAMECONTROLLER_H
