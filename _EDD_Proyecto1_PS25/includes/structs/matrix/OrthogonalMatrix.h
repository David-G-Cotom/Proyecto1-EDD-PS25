//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef ORTHOGONALMATRIX_H
#define ORTHOGONALMATRIX_H

#include <iostream>
#include <ostream>

#include "NodeMatrix.h"
#include "../../models/objects/Path.h"


template <class T> class OrthogonalMatrix {

private:
    NodeMatrix<T> *root;    // Nodo en la posicion (0,0,0)
    int dimensionX, dimensionY, dimensionZ;

    void createOrthogonalMatrix() {
        NodeMatrix<T> *aux = this->root;
        for (int i = 0; i < this->dimensionX - 1; i++) {
            this->connectNodes(aux, i);
            aux = this->getNode(i, 0, 0);
            auto path = new Path();
            path->setImage(" ");
            auto *newNode = new NodeMatrix<T>(path, i + 1, 0, 0);
            aux->setBottom(newNode);
            newNode->setTop(aux);
            aux = newNode;
            this->connectNodes(aux, i + 1);
        }
        std::cout << "TABLERO TRIDIMENSIONAL CREADO CON EXITO!!!" << std::endl;
    }

    void connectNodes(NodeMatrix<T> *aux, int i, int j) {
        for (int k = 0; k < this->dimensionZ - 1; k++) {
            auto path = new Path();
            path->setImage(" ");
            auto *newNode = new NodeMatrix<T>(path, i, j, k + 1);
            aux->setBack(newNode);
            newNode->setFront(aux);
            if (j > 0) {
                newNode->setPrev(aux->getPrev()->getBack());
                aux->getPrev()->getBack()->setNext(newNode);
            }
            if (i > 0) {
                newNode->setTop(aux->getTop()->getBack());
                aux->getTop()->getBack()->setBottom(newNode);
            }
            aux = newNode;
        }
    }

    void connectNodes(NodeMatrix<T> *aux, int i) {
        for (int j = 0; j < this->dimensionY - 1; j++) {
            this->connectNodes(aux, i, j);
            aux = this->getNode(i, j, 0);
            auto path = new Path();
            path->setImage(" ");
            auto *newNode = new NodeMatrix<T>(path, i, j + 1, 0);
            aux->setNext(newNode);
            newNode->setPrev(aux);
            if (i > 0) {
                newNode->setTop(aux->getTop()->getNext());
                aux->getTop()->getNext()->setBottom(newNode);
            }
            aux = newNode;
            this->connectNodes(aux, i, j + 1);
        }
    }

public:
    OrthogonalMatrix(int dimensionX, int dimensionY, int dimensionZ) {
        auto path = new Path();
        path->setImage(" ");
        this->root = new NodeMatrix<T>(path, 0, 0, 0);
        this->dimensionX = dimensionX;
        this->dimensionY = dimensionY;
        this->dimensionZ = dimensionZ;
        this->createOrthogonalMatrix();
    }

    ~OrthogonalMatrix() {
        delete this->root;
    }

    NodeMatrix<T> *getRoot() {
        return this->root;
    }

    void setRoot(NodeMatrix<T> *root) {
        this->root = root;
    }

    int getDimensionX() {
        return this->dimensionX;
    }

    void setDimensionX(int dimensionX) {
        this->dimensionX = dimensionX;
    }

    int getDimensionY() {
        return this->dimensionY;
    }

    void setDimensionY(int dimensionY) {
        this->dimensionY = dimensionY;
    }

    int getDimensionZ() {
        return this->dimensionZ;
    }

    void setDimensionZ(int dimensionZ) {
        this->dimensionZ = dimensionZ;
    }

    bool isEmpty() {
        return this->root == nullptr;
    }

    NodeMatrix<T> *getNode(int x, int y, int z) {
        NodeMatrix<T> *aux = this->root;
        for (int i = 0; i < x; ++i) {
            aux = aux->getBottom();
        }
        for (int i = 0; i < y; ++i) {
            aux = aux->getNext();
        }
        for (int i = 0; i < z; ++i) {
            aux = aux->getBack();
        }
        return aux;
    }

};



#endif //ORTHOGONALMATRIX_H
