//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/controllers/GameController.h"
#include "../../includes/Utilities.h"

GameController::GameController() {
    this->enemiesTree = new TreeBB<Enemy>();
    this->trapsTree = new TreeBB<Trap>();
    this->historyController = new HistoryController();
    this->reportsController = new ReportsController();
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
    this->board->printBoard(this->board->getOrthogonalMatrix()->getRoot(), this->board->getOrthogonalMatrix()->getRoot());
}

void GameController::generateReports() {
    int option;
    do {
        std::cout << "1. Reporte de la Partida" << std::endl;
        std::cout << "2. Ubicacion del tesoro y trayectoria del jugador" << std::endl;
        std::cout << "3. Pistas encontradas y su distancia al tesoro" << std::endl;
        std::cout << "4. Enemigos enfrentados y trampas activadas" << std::endl;
        std::cout << "5. Tabla de posiciones con los mejores jugadores" << std::endl;
        std::cout << "6. Grafico de los arboles de enemigos y trampas" << std::endl;
        std::cout << "7. Salir" << std::endl;
        Utilities::verifyNumericEntry(option, "Opcion: ");
        switch (option) {
            case 1: {
                this->reportsController->gameReport();
                break;
            }
            case 2: {
                this->reportsController->treasureLocationReport();
                break;
            }
            case 3: {
                this->reportsController->trackReport();
                break;
            }
            case 4: {
                this->reportsController->reportEnemiesAndTraps();
                break;
            }
            case 5: {
                this->reportsController->gameHistoryReport(this->gamesHistory);
                break;
            }
            case 6: {
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


