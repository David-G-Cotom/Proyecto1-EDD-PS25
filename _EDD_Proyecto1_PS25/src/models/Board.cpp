//
// Created by Carlos Cotom on 22/03/2025.
//

#include "../../includes/models/Board.h"
#include "../../includes/models/objects/Potion.h"
#include "../../includes/models/objects/Track.h"
#include "../../includes/models/objects/Treasure.h"

Board::Board(int dimensionX, int dimensionY, int dimensionZ) {
    this->orthogonalMatrix = new OrthogonalMatrix<Object>(dimensionX, dimensionY, dimensionZ);
    this->treasureNode = nullptr;
    this->totalNodes = dimensionX * dimensionY * dimensionZ;
}

Board::~Board() {
    delete this->orthogonalMatrix;
    delete this->treasureNode;
}

OrthogonalMatrix<Object>* Board::getOrthogonalMatrix() {
    return this->orthogonalMatrix;
}

void Board::setOrthogonalMatrix(OrthogonalMatrix<Object> *orthogonalMatrix) {
    this->orthogonalMatrix = orthogonalMatrix;
}

NodeMatrix<Object> *Board::getTreasureNode() {
    return this->treasureNode;
}

void Board::setTreasureNode(NodeMatrix<Object> *treasureNode) {
    this->treasureNode = treasureNode;
}

NodeMatrix<Object> *Board::getPlayerNode() {
    return this->playerNode;
}

void Board::setPlayerNode(NodeMatrix<Object> *playerNode) {
    this->playerNode = playerNode;
}

Object *Board::getDataBelowThePlayer() {
    return this->dataBelowThePlayer;
}

void Board::setDataBelowThePlayer(Object *dataBelowThePlayer) {
    this->dataBelowThePlayer = dataBelowThePlayer;
}

int Board::getTotalNodes() {
    return this->totalNodes;
}

void Board::setTotalNodes(int totalNodes) {
    this->totalNodes = totalNodes;
}

void Board::createBoard(Player *player, TreeBB<Enemy> *enemiesTree, TreeBB<Trap> *trapsTree) {
    this->putTreasure();
    this->putPlayer(player);
    srand(time(nullptr));
    for (int i = 0; i < this->totalNodes - 2; i++) {
        int random = rand() % 100;
        if (random < 15) {
            this->putEnemies(enemiesTree);
        } else if (random < 30) {
            this->putTraps(trapsTree);
        } else if (random < 45) {
            this->putPotions();
        } else if (random < 60) {
            this->putTracks();
        }   // else SE QUEDA EL PATH LIBRE
    }
}

void Board::deleteBoard() {

}

void Board::putTreasure() {
    srand(time(nullptr));
    NodeMatrix<Object> *treasureNode;
    do {
        int x = rand() % this->orthogonalMatrix->getDimensionX();
        int y = rand() % this->orthogonalMatrix->getDimensionY();
        int z = rand() % this->orthogonalMatrix->getDimensionZ();
        treasureNode = this->orthogonalMatrix->getNode(x, y, z);
    } while (treasureNode->getData() == nullptr
        || dynamic_cast<Path*>(treasureNode->getData()) == nullptr);
    delete treasureNode->getData();
    auto *treasure = new Treasure();
    treasure->setImage("$");
    treasureNode->setData(treasure);
    this->treasureNode = treasureNode;
    std::cout << "Tesoro Colocado en el Mapa" << std::endl;
}

void Board::putPlayer(Player *player) {
    srand(time(nullptr));
    NodeMatrix<Object> *playerNode;
    do {
        int x = rand() % this->orthogonalMatrix->getDimensionX();
        int y = rand() % this->orthogonalMatrix->getDimensionY();
        int z = rand() % this->orthogonalMatrix->getDimensionZ();
        playerNode = this->orthogonalMatrix->getNode(x, y, z);
    } while (playerNode->getData() == nullptr
        || dynamic_cast<Path*>(playerNode->getData()) == nullptr);
    this->dataBelowThePlayer = playerNode->getData();
    playerNode->setData(player);
    this->playerNode = playerNode;
    std::cout << "Jugador Colocado en el Mapa" << std::endl;
}

void Board::putEnemies(TreeBB<Enemy> *enemiesTree) {
    srand(time(nullptr));
    NodeMatrix<Object> *enemyNode;
    int x, y, z;
    do {
        x = rand() % this->orthogonalMatrix->getDimensionX();
        y = rand() % this->orthogonalMatrix->getDimensionY();
        z = rand() % this->orthogonalMatrix->getDimensionZ();
        enemyNode = this->orthogonalMatrix->getNode(x, y, z);
    } while (enemyNode->getData() == nullptr
        || dynamic_cast<Path*>(enemyNode->getData()) == nullptr);
    delete enemyNode->getData();
    int level = ((x + 1) * 100) + ((y + 1) * 10) + (z + 1);
    int damage = (rand() % 15) + 1;
    auto *enemy = new Enemy(level, damage);
    enemy->setImage("!");
    enemyNode->setData(enemy);
    auto *enemyNodeTree = new NodeTree(enemy, level);
    enemiesTree->insert(enemyNodeTree, false);
    std::cout << "Enemigo Colocado en el Mapa" << std::endl;
}

void Board::putTraps(TreeBB<Trap> *trapsTree) {
    srand(time(nullptr));
    NodeMatrix<Object> *trapNode;
    int x, y, z;
    do {
        x = rand() % this->orthogonalMatrix->getDimensionX();
        y = rand() % this->orthogonalMatrix->getDimensionY();
        z = rand() % this->orthogonalMatrix->getDimensionZ();
        trapNode = this->orthogonalMatrix->getNode(x, y, z);
    } while (trapNode->getData() == nullptr
        || dynamic_cast<Path*>(trapNode->getData()) == nullptr);
    delete trapNode->getData();
    int level = ((z + 1) * 100) + ((y + 1) * 10) + (x + 1);
    int damage = (rand() % 10) + 1;
    auto *trap = new Trap(level, damage);
    trap->setImage("#");
    trapNode->setData(trap);
    auto *trapNodeTree = new NodeTree(trap, level);
    trapsTree->insert(trapNodeTree, true);
    std::cout << "Trampa Colocada en el Mapa" << std::endl;
}

void Board::putPotions() {
    srand(time(nullptr));
    NodeMatrix<Object> *potionNode;
    do {
        int x = rand() % this->orthogonalMatrix->getDimensionX();
        int y = rand() % this->orthogonalMatrix->getDimensionY();
        int z = rand() % this->orthogonalMatrix->getDimensionZ();
        potionNode = this->orthogonalMatrix->getNode(x, y, z);
    } while (potionNode->getData() == nullptr
        || dynamic_cast<Path*>(potionNode->getData()) == nullptr);
    delete potionNode->getData();
    int healing = (rand() % 10) + 1;
    auto *potion = new Potion(healing);
    potion->setImage("&");
    potionNode->setData(potion);
    std::cout << "Pocion Colocado en el Mapa" << std::endl;
}

void Board::putTracks() {
    srand(time(nullptr));
    NodeMatrix<Object> *trackNode;
    int x, y, z;
    do {
        x = rand() % this->orthogonalMatrix->getDimensionX();
        y = rand() % this->orthogonalMatrix->getDimensionY();
        z = rand() % this->orthogonalMatrix->getDimensionZ();
        trackNode = this->orthogonalMatrix->getNode(x, y, z);
    } while (trackNode->getData() == nullptr
        || dynamic_cast<Path*>(trackNode->getData()) == nullptr);
    delete trackNode->getData();
    int distance = std::abs(x - this->treasureNode->getX()) + std::abs(y - this->treasureNode->getY()) + std::abs(z - this->treasureNode->getZ());
    std::string trackType = this->getTrack(distance);
    auto *track = new Track(trackType, distance);
    track->setImage("?");
    trackNode->setData(track);
    std::cout << "Pista Colocada en el Mapa" << std::endl;
}

std::string Board::getTrack(const int distance) {
    std::string type;
    switch (distance) {
        case 1: {
            type = "CALIENTE";
            break;
        }
        case 2: {
            type = "TIBIO";
            break;
        }
        default: {
            type = "FRIO";
            break;
        }
    }
    return type;
}

void Board::printBoard(NodeMatrix<Object> *node, NodeMatrix<Object> *root, int z) {
    NodeMatrix<Object> *aux = node;
    if (z >= 0 && node == root) {
        std::cout << "Tablero en Z = " << z << std::endl;
    }
    while (aux != nullptr) {
        std::cout << "|" << aux->getData()->image;
        aux = aux->getNext();
    }
    std::cout << "|" << std::endl;
    if (node->getBottom() != nullptr) {
        printBoard(node->getBottom(), root, z);
    } else {
        if (root->getBack() != nullptr) {
            printBoard(root->getBack(), root->getBack(), z + 1);
        }
    }
}


