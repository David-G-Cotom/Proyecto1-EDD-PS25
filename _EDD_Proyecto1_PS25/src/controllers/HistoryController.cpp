//
// Created by Carlos Cotom on 23/03/2025.
//

#include "../../includes/controllers/HistoryController.h"

#include <fstream>
#include <iostream>
#include <sstream>

HistoryController::HistoryController() = default;

HistoryController::~HistoryController() = default;

LinkedList<Game> *HistoryController::loadHistory(std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo en la ruta: " << fileName << std::endl;
        return nullptr;
    }
    std::cout << "Archivo Cargado Correctamente" << std::endl;
    auto history = new LinkedList<Game>();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string playerName;
        int score;
        int movements;
        if (getline(iss, playerName, ',') && iss >> score && iss.ignore() && iss >> movements) {
            auto game = new Game(playerName, score, 0, movements);
            history->addElementAt(game);
        } else {
            std::cout << "Error al extraer los datos de la linea: " << line << std::endl;
        }
    }
    file.close();
    std::cout << "Archivo Leido!!!\n" << std::endl;
    return history;
}



