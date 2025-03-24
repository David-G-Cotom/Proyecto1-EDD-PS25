//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/controllers/GameController.h"
#include "../../includes/Utilities.h"

GameController::GameController() = default;

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

    this->initializeBoard();
}

void GameController::generateReports() {

}


