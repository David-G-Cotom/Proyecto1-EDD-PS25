//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/controllers/ReportsController.h"
#include "../../includes/Utilities.h"

#include <filesystem>
#include <fstream>
#include <iostream>

ReportsController::ReportsController() = default;

ReportsController::~ReportsController() = default;

void ReportsController::treasureLocationReport(NodeMatrix<Object> *treasureNode, LinkedList<Movement> *playerMovements) {
    std::cout << "--- Ubicacion del Tesoro ---" << std::endl;
    std::cout << "Coordenada X: " << treasureNode->getX() << std::endl;
    std::cout << "Coordenada Y: " << treasureNode->getY() << std::endl;
    std::cout << "Coordenada Z: " << treasureNode->getZ() << std::endl;
    std::cout << "--- Trayectoria del Jugador ---" << std::endl;
    NodeList<Movement> *aux = playerMovements->getHead();
    int i = 1;
    while (aux != nullptr) {
        std::cout << "-> Movimiento: " << i << std::endl;
        std::cout << aux->getData()->convertToString() << std::endl;
        aux = aux->getNext();
        i++;
    }
}

void ReportsController::trackReport(LinkedList<Track> *tracksFound) {
    std::cout << "--- Pistas Encontradas y su Distancia al Tesoro ---" << std::endl;
    NodeList<Track> *aux = tracksFound->getHead();
    while (aux != nullptr) {
        std::cout << "Pista de Tipo: " << aux->getData()->getType() << ", con Distancia de " << aux->getData()->getDistance() << " pasos" << std::endl;
        aux = aux->getNext();
    }
}

void ReportsController::reportEnemiesAndTraps(TreeBB<Enemy> *enemiesTree, TreeBB<Trap> *trapsTree) {
    std::cout << "--- Enemigos Enfrentados ---" << std::endl;
    this->traversePreOrden(enemiesTree->getRoot());
    std::cout << "--- Trampas Activadas ---" << std::endl;
    this->traversePreOrden(trapsTree->getRoot());
}

void ReportsController::traversePreOrden(NodeTree<Enemy> *nodeEnemy) {
    if (nodeEnemy != nullptr) {
        if (nodeEnemy->getData()->getWasFound()) {
            std::cout << "Enemigo de Nivel: " << nodeEnemy->getData()->getLevel() << " con un Damage de " << nodeEnemy->getData()->getDamage() << std::endl;
        }
        if (nodeEnemy->getLeft() != nullptr) {
            traversePreOrden(nodeEnemy->getLeft());
        }
        if (nodeEnemy->getRight() != nullptr) {
            traversePreOrden(nodeEnemy->getRight());
        }
    }
}

void ReportsController::traversePreOrden(NodeTree<Trap> *nodeTrap) {
    if (nodeTrap != nullptr) {
        if (nodeTrap->getData()->getWasFound()) {
            std::cout << "Trampa de Nivel: " << nodeTrap->getData()->getLevel() << " con un Damage de " << nodeTrap->getData()->getDamage() << std::endl;
        }
        if (nodeTrap->getLeft() != nullptr) {
            traversePreOrden(nodeTrap->getLeft());
        }
        if (nodeTrap->getRight() != nullptr) {
            traversePreOrden(nodeTrap->getRight());
        }
    }
}

void ReportsController::gameHistoryReport(LinkedList<Game> *gamesHistory) {
    int option;
    do {
        std::cout << "1. Ordenada por Puntos" << std::endl;
        std::cout << "2. Ordenada por Nombres" << std::endl;
        Utilities::verifyNumericEntry(option, "Opcion: ");
        if (option == 1) {
            std::cout << "--- Historial de Partidas Ordenada por Puntos ---" << std::endl;
            this->mergeSort(gamesHistory, 0, gamesHistory->getSize() - 1, true);
            this->printLeaderBoard(gamesHistory);
        } else if (option == 2) {
            std::cout << "--- Historial de Partidas Ordenada por Nombres ---" << std::endl;
            this->mergeSort(gamesHistory, 0, gamesHistory->getSize() - 1, false);
            this->printLeaderBoard(gamesHistory);
        }
    } while (option != 1 && option != 2);
}

void ReportsController::mergeSort(LinkedList<Game> *array, int left, int right, bool orderType) {
    if (left < right) {
        int half = left + (right - left) / 2;

        this->mergeSort(array, left, half, orderType);
        this->mergeSort(array, half + 1, right, orderType);

        this->merge(array, left, half, right, orderType);
    }
}

void ReportsController::merge(LinkedList<Game> *array, int left, int half, int right, bool orderType) {
    int leftArraySize = half - left + 1;
    int rightArraySize = right - half;

    auto *leftArray = new LinkedList<Game>();
    auto *rightArray = new LinkedList<Game>();

    for (int i = 0; i < leftArraySize; i++) {
        leftArray->addElementAt(array->getElementAt(left + i)->getData());
    }
    for (int i = 0; i < rightArraySize; i++) {
        rightArray->addElementAt(array->getElementAt(half + 1 + i)->getData());
    }

    int i = 0, j = 0;
    int k = left;

    while (i < leftArraySize && j < rightArraySize) {
        if (orderType) {    // Ordenado por puntos
            if (leftArray->getElementAt(i)->getData()->getScore() >= rightArray->getElementAt(j)->getData()->getScore()) {
                array->getElementAt(k)->setData(leftArray->getElementAt(i)->getData());
                i++;
            } else {
                array->getElementAt(k)->setData(rightArray->getElementAt(j)->getData());
                j++;
            }
        } else {    // Ordenado por Nombres
            if (leftArray->getElementAt(i)->getData()->getPlayerName() <= rightArray->getElementAt(j)->getData()->getPlayerName()) {
                array->getElementAt(k)->setData(leftArray->getElementAt(i)->getData());
                i++;
            } else {
                array->getElementAt(k)->setData(rightArray->getElementAt(j)->getData());
                j++;
            }
        }
        k++;
    }

    while (i < leftArraySize) {
        array->getElementAt(k)->setData(leftArray->getElementAt(i)->getData());
        i++;
        k++;
    }

    while (j < rightArraySize) {
        array->getElementAt(k)->setData(rightArray->getElementAt(j)->getData());
        j++;
        k++;
    }
}

void ReportsController::printLeaderBoard(LinkedList<Game> *gamesHistory) {
    NodeList<Game> *aux = gamesHistory->getHead();
    int i = 1;
    while (aux != nullptr) {
        std::cout << i << ". " << aux->getData()->getPlayerName() << " -> " << aux->getData()->getScore() << " puntos, "
        << aux->getData()->getMovements() << " movimientos -> " << aux->getData()->getTime() / 1000 << " s" << std::endl;
        aux = aux->getNext();
        i++;
    }
}

void ReportsController::treeReport(TreeBB<Enemy> *enemiesTree, TreeBB<Trap> *trapsTree) {
    std::string dot = "digraph{\nrankdir = TB;\nlabel = \"Arbol de Enemigos y Trampas\";\nlabelloc = t;\nnode[color=transparent style=filled];\nnode[shape = box];Enemigos\nnode[shape = circle];\n";
    dot += this->traversePreOrden(enemiesTree->getRoot(), dot);
    dot += "\nnode[color=transparent style=filled];\nnode[shape = box];Trampas\nnode[shape = circle];\n";
    dot += this->traversePreOrden(trapsTree->getRoot(), dot) + "\n}";
    std::filesystem::create_directories("../Graficas");
    std::ofstream file;
    file.open("../Graficas/ReporteArboles.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteArboles.txt -o ../Graficas/ReporteArboles.png");
    std::cout << "\n>> Reporte Generado!!!" << std::endl;
}

std::string ReportsController::traversePreOrden(NodeTree<Enemy> *nodeEnemy, std::string dot) {
    std::string dotAux;
    if (nodeEnemy != nullptr) {
        dotAux += "\"E" + std::to_string(nodeEnemy->getData()->getLevel())
        + "\"[label=<" + std::to_string(nodeEnemy->getData()->getLevel())
        + "<br/>Damage: " + std::to_string(nodeEnemy->getData()->getDamage())
        + "<br/>Encontrado: " + std::to_string(nodeEnemy->getData()->getWasFound())
        + "> fillcolor=\"#8080F0\"];\n";
        if (nodeEnemy->getLeft() != nullptr) {
            dotAux += traversePreOrden(nodeEnemy->getLeft(), dotAux) + "\"E"
            +  std::to_string(nodeEnemy->getData()->getLevel()) + "\" -> \"E" + std::to_string(nodeEnemy->getLeft()->getData()->getLevel())
            + "\";\n";
        }
        if (nodeEnemy->getRight() != nullptr) {
            dotAux += traversePreOrden(nodeEnemy->getRight(), dotAux) + "\"E"
            + std::to_string(nodeEnemy->getData()->getLevel()) + "\" -> \"E" + std::to_string(nodeEnemy->getRight()->getData()->getLevel())
            + "\";\n";
        }
    }
    return dotAux;
}

std::string ReportsController::traversePreOrden(NodeTree<Trap> *nodeTrap, std::string dot) {
    std::string dotAux;
    if (nodeTrap != nullptr) {
        dotAux += "\"T" + std::to_string(nodeTrap->getData()->getLevel())
        + "\"[label=<" + std::to_string(nodeTrap->getData()->getLevel())
        + "<br/>Damage: " + std::to_string(nodeTrap->getData()->getDamage())
        + "<br/>Encontrada: " + std::to_string(nodeTrap->getData()->getWasFound())
        + "> fillcolor=\"#F08080\"];\n";
        if (nodeTrap->getLeft() != nullptr) {
            dotAux += traversePreOrden(nodeTrap->getLeft(), dotAux) + "\"T"
            + std::to_string(nodeTrap->getData()->getLevel()) + "\" -> \"T" + std::to_string(nodeTrap->getLeft()->getData()->getLevel())
            + "\";\n";
        }
        if (nodeTrap->getRight() != nullptr) {
            dotAux += traversePreOrden(nodeTrap->getRight(), dotAux) + "\"T"
            + std::to_string(nodeTrap->getData()->getLevel()) + "\" -> \"T" + std::to_string(nodeTrap->getRight()->getData()->getLevel())
            + "\";\n";
        }
    }
    return dotAux;
}


