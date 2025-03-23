//
// Created by Carlos Cotom on 22/03/2025.
//

#include "../../includes/models/Board.h"

Board::Board() {
    this->treasureNode = nullptr;
}

Board::~Board() {
    delete this->treasureNode;
}

NodeMatrix<Treasure> *Board::getTreasureNode() {
    return this->treasureNode;
}

void Board::setTreasureNode(NodeMatrix<Treasure> *treasureNode) {
    this->treasureNode = treasureNode;
}

void Board::createBoard() {

}

void Board::deleteBoard() {

}

void Board::putTreasure() {

}

void Board::putEnemys(TreeBB<Enemy> &enemysTree) {

}

void Board::putTraps(TreeBB<Trap> &trapsTree) {

}

void Board::putPotions() {

}

void Board::putTracks() {

}

void Board::completeBoard() {

}

void Board::printBoard() {

}









