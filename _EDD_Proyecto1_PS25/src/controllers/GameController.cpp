//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/controllers/GameController.h"
#include "../../includes/Utilities.h"
#include "../../includes/models/objects/Potion.h"

#include <chrono>

GameController::GameController() {
    this->enemiesTree = new TreeBB<Enemy>();
    this->trapsTree = new TreeBB<Trap>();
    this->tracksFound = new LinkedList<Track>();
    this->time = 0;
    this->historyController = new HistoryController();
    this->reportsController = new ReportsController();
    this->gameOver = false;
    this->currentGame = nullptr;
}

GameController::~GameController() = default;

void GameController::initializeBoard() {
    int dimensionX, dimensionY, dimensionZ;
    Utilities::verifyNumericEntry(dimensionX, "Ingrese la Cantidad de Filas (Eje x) del Tablero (Minimo de 2): ");
    while (dimensionX < 2) {
        Utilities::verifyNumericEntry(dimensionX, "Se Requiere al Menos 2 Filas (Eje x) en el Tablero. Ingrese de Nuevo: ");
    }
    Utilities::verifyNumericEntry(dimensionY, "Ingrese la Cantidad de Columnas (Eje y) del Tablero (Minimo de 2): ");
    while (dimensionY < 2) {
        Utilities::verifyNumericEntry(dimensionY, "Se Requiere al Menos 2 Columnas (Eje y) en el Tablero. Ingrese de Nuevo: ");
    }
    Utilities::verifyNumericEntry(dimensionZ, "Ingrese la Cantidad de Fondos (Eje z) del Tablero (Minimo de 2): ");
    while (dimensionZ < 2) {
        Utilities::verifyNumericEntry(dimensionZ, "Se Requiere al Menos 2 Fondos (Eje z) en el Tablero. Ingrese de Nuevo: ");
    }
    this->board = new Board(dimensionX, dimensionY, dimensionZ);
    this->board->createBoard(this->player, this->enemiesTree, this->trapsTree);
}

void GameController::init() {
    auto startTime = std::chrono::steady_clock::now();

    std::string fileName;
    std::cout << "Ingrese el Nombre/Direccion del Archivo con el Historial de Partidas: ";
    getline(std::cin, fileName);
    this->gamesHistory = this->historyController->loadHistory(fileName);

    std::string playerName;
    std::cout << "Ingrese el nombre del jugador: ";
    getline(std::cin, playerName);
    this->player = new Player(playerName);
    this->player->setImage("@");
    std::cout << "Jugador Registrado!!!" << std::endl;

    this->initializeBoard();

    char movement;
    while (this->player->getLife() > 0 && !this->gameOver) {
        this->board->printBoard(this->board->getOrthogonalMatrix()->getRoot(), this->board->getOrthogonalMatrix()->getRoot());
        std::cout << "Vida del Jugador: " << this->player->getLife() << std::endl;
        std::cout << "Puntos del Jugaodr: " << this->player->getScore() << std::endl;
        NodeMatrix<Object> *newNode;
        do {
            std::cout << "W. Arriba, S. Abajo, A. Izquierda, D. Derecha, Q. Atras, E. Adelante" << std::endl;
            std::cout << "Ingrese Movimiento: ";
            std::cin >> movement;
            movement = toupper(movement);
            //OBTENER EL NODO AL QUE SE MOVIO
            newNode = this->verifyMovement(movement);
            //VERIFICAR QUE SEA UN MOVIMIENTO VALIDO (letra correcta y dentro del tablero)
            if (newNode == nullptr) {
                std::cout << "Movimiento Incorrecto!!!" << std::endl;
            }
        } while (newNode == nullptr);
        //CHEKEAR EL NODO NUEVO (interactua con el nuevo nodo)
        //REGISTRAR LAS ACIONES DEL MOVIMIENTO
        this->checkNode(newNode);
        //HACER EL MOVIMIENTO DE NODOS
        this->board->getPlayerNode()->setData(this->board->getDataBelowThePlayer());
        this->board->setDataBelowThePlayer(newNode->getData());
        newNode->setData(this->player);
        this->board->setPlayerNode(newNode);
    }

    auto endTime = std::chrono::steady_clock::now();
    this->time = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    this->currentGame = new Game(this->player->getName(), this->player->getScore(), this->time, this->player->getMovements()->getSize());
    this->gamesHistory->addElementAt(this->currentGame);
    this->gameReport();

    int option;
    do {
        std::cout << "1. Ver Reportes\n2. Salir" << std::endl;
        Utilities::verifyNumericEntry(option, "Opcion: ");
        switch (option) {
            case 1: {
                this->generateReports();
                break;
            }
            case 2: {
                std::cout << "JUEGO FINALIZADO!!!" << std::endl;
                break;
            }
            default: {
                std::cout << "Error!!! Opcion No Valida." << std::endl;
                break;
            }
        }
    } while (option != 1 && option != 2);
}

NodeMatrix<Object> *GameController::verifyMovement(const char movement) {
    switch (movement) {
        case 'W': { return this->board->getPlayerNode()->getTop(); }
        case 'S': { return this->board->getPlayerNode()->getBottom(); }
        case 'A': { return this->board->getPlayerNode()->getPrev(); }
        case 'D': { return this->board->getPlayerNode()->getNext(); }
        case 'Q': { return this->board->getPlayerNode()->getBack(); }
        case 'E': { return this->board->getPlayerNode()->getFront(); }
        default: { return nullptr; }
    }
}

void GameController::checkNode(NodeMatrix<Object> *node) {
    //ENCONTRO TESORO
    if (node->getX() == this->board->getTreasureNode()->getX()
        && node->getY() == this->board->getTreasureNode()->getY()
        && node->getZ() == this->board->getTreasureNode()->getZ()) {
        std::cout << "Felicidades!!! Has Encontrado el Tesotro" << std::endl;
        this->player->setScore(this->player->getScore() + this->player->getLife()*10);
        this->gameOver = true;
        auto *newMovement = new Movement(node->getX(), node->getY(), node->getZ(), "Ha encontrado el Tesoro", this->player->getLife());
        this->player->getMovements()->addElementAt(newMovement);
        return;
    }
    //ENCONTRO ENEMIGO
    if (node->getData() != nullptr
        && dynamic_cast<Enemy*>(node->getData()) != nullptr) {
        int level = ((node->getX() + 1) * 100) + ((node->getY() + 1) * 10) + (node->getZ() + 1);
        Enemy *enemy = this->enemiesTree->search(level, false);
        enemy->setWasFound(true);
        std::cout << "Encontraste un Enemigo!!! de nivel: " << enemy->getLevel() << std::endl;
        std::string event = "Ha encontrado un Enemigo de nivel " + std::to_string(enemy->getLevel()) +
                            " y ha recibido " + std::to_string(enemy->getDamage()) + " de damage.";
        if (this->player->getDamage(enemy->getDamage())) {
            std::cout << "Has Perdido!!! Te has Quedado Sin Vida" << std::endl;
            this->gameOver = true;
            event += "Ha perdido porque se quedo sin vida";
        }
        auto *newMovement = new Movement(node->getX(), node->getY(), node->getZ(), event, this->player->getLife());
        this->player->getMovements()->addElementAt(newMovement);
        auto *path = new Path();
        path->setImage(" ");
        node->setData(path);
        return;
    }
    //ENCONTRO TRAMPA
    if (node->getData() != nullptr
        && dynamic_cast<Trap*>(node->getData()) != nullptr) {
        int level = ((node->getZ() + 1) * 100) + ((node->getY() + 1) * 10) + (node->getX() + 1);
        Trap *trap = this->trapsTree->search(level, true);
        trap->setWasFound(true);
        std::cout << "Encontraste una Trampa!!! de nivel: " << trap->getLevel() << std::endl;
        std::string event = "Ha encontrado una Trampa de nivel " + std::to_string(trap->getLevel()) +
                            " y ha recibido " + std::to_string(trap->getDamage()) + " de damage.";
        if (this->player->getDamage(trap->getDamage())) {
            std::cout << "Has Perdido!!! Te has Quedado Sin Vida" << std::endl;
            this->gameOver = true;
            event += "Ha perdido porque se quedo sin vida";
        }
        auto *newMovement = new Movement(node->getX(), node->getY(), node->getZ(), event, this->player->getLife());
        this->player->getMovements()->addElementAt(newMovement);
        auto *path = new Path();
        path->setImage(" ");
        node->setData(path);
        return;
    }
    //ENCONTRO PISTA
    if (node->getData() != nullptr) {
        auto *track = dynamic_cast<Track*>(node->getData());
        if (track != nullptr) {
            std::cout << "Encontraste una Pista!!! con el Siguiente Mensaje: " << track->getType() << " (" << track->getDistance() << ")Pasos" << std::endl;
            std::string event = "Ha encontrado una Pista con el mensaje de: " + track->getType();
            auto *newMovement = new Movement(node->getX(), node->getY(), node->getZ(), event, this->player->getLife());
            this->player->getMovements()->addElementAt(newMovement);
            this->tracksFound->addElementAt(track);
            return;
        }
    }
    //ENCONTRO POSIMA
    if (node->getData() != nullptr) {
        auto *potion = dynamic_cast<Potion*>(node->getData());
        if (potion != nullptr) {
            std::cout << "Encontraste una Posion!!!";
            std::string event = "Ha encontrado una Posion y ha recuperado: " + std::to_string(potion->getHealing()) + " de salud";
            auto *newMovement = new Movement(node->getX(), node->getY(), node->getZ(), event, this->player->getLife());
            this->player->getMovements()->addElementAt(newMovement);
            this->player->getHealth(potion->getHealing());
            auto *path = new Path();
            path->setImage(" ");
            node->setData(path);
            return;
        }
    }
    //NO ENCONTRO NADA
    auto *newMovement = new Movement(node->getX(), node->getY(), node->getZ(), "No encontro nada en el camino", this->player->getLife());
    this->player->getMovements()->addElementAt(newMovement);
}

void GameController::generateReports() {
    int option;
    do {
        std::cout << "\n1. Reporte de la Partida" << std::endl;
        std::cout << "2. Ubicacion del tesoro y trayectoria del jugador" << std::endl;
        std::cout << "3. Pistas encontradas y su distancia al tesoro" << std::endl;
        std::cout << "4. Enemigos enfrentados y trampas activadas" << std::endl;
        std::cout << "5. Tabla de posiciones con los mejores jugadores" << std::endl;
        std::cout << "6. Grafico de los arboles de enemigos y trampas" << std::endl;
        std::cout << "7. Salir" << std::endl;
        Utilities::verifyNumericEntry(option, "Opcion: ");
        switch (option) {
            case 1: {
                this->gameReport();
                break;
            }
            case 2: {
                this->reportsController->treasureLocationReport(this->board->getTreasureNode(), this->player->getMovements());
                break;
            }
            case 3: {
                this->reportsController->trackReport(this->tracksFound);
                break;
            }
            case 4: {
                this->reportsController->reportEnemiesAndTraps(this->enemiesTree, this->trapsTree);
                break;
            }
            case 5: {
                this->reportsController->gameHistoryReport(this->gamesHistory);
                break;
            }
            case 6: {
                std::cout << "--- Reporte de los Graficos de los Arboles de Enemigos y Trampas ---";
                this->reportsController->treeReport(this->enemiesTree, this->trapsTree);
                break;
            }
            case 7: {
                std::cout << "SALIENDO DEL JUEOG!!!" << std::endl;
                break;
            }
            default: {
                std::cout << "Error!!! Opcion incorrecta" << std::endl;
                break;
            }
        }
    } while (option != 7);
}

void GameController::gameReport() {
    std::cout << "\n--- Reporte de la Partida Actual ---" << std::endl;
    std::cout << "Nombre del Jugador: " << this->currentGame->getPlayerName() << std::endl;
    std::cout << "Tiempo Total de la Partida: " << this->currentGame->getTime() / 1000 << "s" << std::endl;
    std::cout << "Total de Movimientos: " << this->currentGame->getMovements() << std::endl;
    std::cout << "Puntuacion: " << this->currentGame->getScore() << std::endl;
}


