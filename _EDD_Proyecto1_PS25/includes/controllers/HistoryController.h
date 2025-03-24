//
// Created by Carlos Cotom on 23/03/2025.
//

#ifndef HISTORYCONTROLLER_H
#define HISTORYCONTROLLER_H

#include "../models/Game.h"
#include "../structs/list/LinkedList.h"


class HistoryController {

public:
    HistoryController();

    ~HistoryController();

    LinkedList<Game> *loadHistory(std::string &fileName);

};



#endif //HISTORYCONTROLLER_H
