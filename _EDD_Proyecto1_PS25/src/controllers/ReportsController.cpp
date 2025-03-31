//
// Created by Carlos Cotom on 21/03/2025.
//

#include "../../includes/controllers/ReportsController.h"
#include "../../includes/Utilities.h"

#include <fstream>
#include <iostream>

ReportsController::ReportsController() = default;

ReportsController::~ReportsController() = default;

void ReportsController::gameReport() {

}

void ReportsController::treasureLocationReport() {

}

void ReportsController::trackReport() {

}

void ReportsController::reportEnemiesAndTraps() {

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
            if (leftArray->getElementAt(i)->getData()->getScore() <= rightArray->getElementAt(j)->getData()->getScore()) {
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
        std::cout << i << aux->getData()->getPlayerName() << " -> " << aux->getData()->getScore() << " puntos, "
        << aux->getData()->getMovements() << " movimientos -> " << aux->getData()->getTime() << " ms\n" << std::endl;
        aux = aux->getNext();
        i++;
    }
    std::cout << std::endl;
}

void ReportsController::treeReport(TreeBB<Enemy> *enemiesTree, TreeBB<Trap> *trapsTree) {
    std::string dot = "digraph{\nrankdir = TB;\nlabel = \"Arbol de Enemigos y Trampas\";\nlabelloc = t;\nnode[color=transparent style=filled];\nnode[shape = circle];\n";
    dot += this->traversePreOrden(enemiesTree->getRoot(), dot);
    dot += "node[shape = circle];\n";
    dot += this->traversePreOrden(trapsTree->getRoot(), dot) + "\n}";
    std::ofstream file;
    file.open("../Graficas/ReporteArboles.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteArboles.txt -o ../Graficas/ReporteArboles.png");
    std::cout << ">> Reporte Generado!!!" << std::endl;
}

std::string ReportsController::traversePreOrden(NodeTree<Enemy> *nodeEnemy, std::string dot) {
    std::string dotAux;
    if (nodeEnemy != nullptr) {
        dotAux += "\"" + nodeEnemy->getData()->getLevel();
        dotAux += "\"[label=<" + nodeEnemy->getData()->getLevel();
        dotAux += "<br/>Damage: " + nodeEnemy->getData()->getDamage();
        dotAux += "> fillcolor=\"#8080F0\"];\n";
        if (nodeEnemy->getLeft() != nullptr) {
            dotAux += traversePreOrden(nodeEnemy->getLeft(), dotAux) + "\"";
            dotAux += nodeEnemy->getData()->getLevel() + "\" -> \"" + nodeEnemy->getLeft()->getData()->getLevel();
            dotAux += "\";\n";
        }
        if (nodeEnemy->getRight() != nullptr) {
            dotAux += traversePreOrden(nodeEnemy->getRight(), dotAux) + "\"";
            dotAux += nodeEnemy->getData()->getLevel() + "\" -> \"" + nodeEnemy->getRight()->getData()->getLevel();
            dotAux += "\";\n";
        }
    }
    return dotAux;
}

std::string ReportsController::traversePreOrden(NodeTree<Trap> *nodeTrap, std::string dot) {
    std::string dotAux;
    if (nodeTrap != nullptr) {
        dotAux += "\"" + nodeTrap->getData()->getLevel();
        dotAux += "\"[label=<" + nodeTrap->getData()->getLevel();
        dotAux += "<br/>Damage: " + nodeTrap->getData()->getDamage();
        dotAux += "> fillcolor=\"#8080F0\"];\n";
        if (nodeTrap->getLeft() != nullptr) {
            dotAux += traversePreOrden(nodeTrap->getLeft(), dotAux) + "\"";
            dotAux += nodeTrap->getData()->getLevel() + "\" -> \"" + nodeTrap->getLeft()->getData()->getLevel();
            dotAux += "\";\n";
        }
        if (nodeTrap->getRight() != nullptr) {
            dotAux += traversePreOrden(nodeTrap->getRight(), dotAux) + "\"";
            dotAux += nodeTrap->getData()->getLevel() + "\" -> \"" + nodeTrap->getRight()->getData()->getLevel();
            dotAux += "\";\n";
        }
    }
    return dotAux;
}


