//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef REPORTSCONTROLLER_H
#define REPORTSCONTROLLER_H

#include "../models/Game.h"
#include "../models/objects/Enemy.h"
#include "../models/objects/Track.h"
#include "../models/objects/Trap.h"
#include "../structs/list/LinkedList.h"
#include "../structs/matrix/NodeMatrix.h"
#include "../structs/tree/TreeBB.h"


class ReportsController {

public:
    ReportsController();

    ~ReportsController();

    void treasureLocationReport(NodeMatrix<Object> *treasureNode, LinkedList<Movement> *playerMovements);

    void trackReport(LinkedList<Track> *tracksFound);

    void reportEnemiesAndTraps(TreeBB<Enemy> *enemiesTree, TreeBB<Trap> *trapsTree);
    void traversePreOrden(NodeTree<Trap> *nodeTrap);
    void traversePreOrden(NodeTree<Enemy> *nodeEnemy);

    void gameHistoryReport(LinkedList<Game> *gamesHistory);
    void mergeSort(LinkedList<Game> *array, int left, int right, bool orderType);
    void merge(LinkedList<Game> *array, int left, int half, int right, bool orderType);
    void printLeaderBoard(LinkedList<Game> *gamesHistory);

    void treeReport(TreeBB<Enemy> *enemiesTree, TreeBB<Trap> *trapsTree);
    std::string traversePreOrden(NodeTree<Trap> *nodeTrap, std::string dot);
    std::string traversePreOrden(NodeTree<Enemy> *nodeEnemy, std::string dot);

};



#endif //REPORTSCONTROLLER_H
