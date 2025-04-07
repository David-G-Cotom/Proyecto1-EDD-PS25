cmake_minimum_required(VERSION 3.28)
project(_EDD_Proyecto1_PS25)

set(CMAKE_CXX_STANDARD 23)

add_executable(_EDD_Proyecto1_PS25 main.cpp
        includes/controllers/GameController.h
        src/controllers/GameController.cpp
        includes/structs/tree/NodeTree.h
        includes/structs/tree/TreeBB.h
        includes/structs/matrix/NodeMatrix.h
        includes/structs/matrix/OrthogonalMatrix.h
        includes/models/Player.h
        src/models/Player.cpp
        includes/controllers/ReportsController.h
        src/controllers/ReportsController.cpp
        includes/structs/list/NodeList.h
        includes/structs/list/LinkedList.h
        src/models/Movement.cpp
        includes/models/Movement.h
        includes/models/objects/Object.h
        includes/models/objects/Trap.h
        includes/models/objects/Track.h
        src/models/objects/Object.cpp
        src/models/objects/Trap.cpp
        src/models/objects/Track.cpp
        includes/models/objects/Treasure.h
        src/models/objects/Treasure.cpp
        includes/models/objects/Potion.h
        src/models/objects/Potion.cpp
        includes/models/objects/Enemy.h
        src/models/objects/Enemy.cpp
        includes/models/Board.h
        src/models/Board.cpp
        includes/models/objects/Path.h
        src/models/objects/Path.cpp
        includes/models/Game.h
        src/models/Game.cpp
        includes/controllers/HistoryController.h
        src/controllers/HistoryController.cpp
        includes/Utilities.h
        src/Utilities.cpp
)
