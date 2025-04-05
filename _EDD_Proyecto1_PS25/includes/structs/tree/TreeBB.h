//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef TREEBB_H
#define TREEBB_H

#include "NodeTree.h"



template <class T> class TreeBB {

private:
    NodeTree<T> *root;
    
    void insert(NodeTree<T> *value, NodeTree<T> *&root, const bool isInverse) {
        if (root == nullptr) {
            root = value;
            return;
        }
        if (isInverse) {    // ARBOL DE TRAMPAS
            if (value->getSize() < root->getSize()) {
                insert(value, root->getRight2(), isInverse);
            } else {
                insert(value, root->getLeft2(), isInverse);
            }
        } else {    // ARBOL DE ENEMIGOS
            if (value->getSize() < root->getSize()) {
                insert(value, root->getLeft2(), isInverse);
            } else {
                insert(value, root->getRight2(), isInverse);
            }
        }
    }

    void remove(NodeTree<T> *value, NodeTree<T> *&root) {
        if (value->getSize() == root->getSize()) {
            if (this->isLeaf(root)) {
                root = nullptr;
                return;
            }
            if (root->getLeft() == nullptr) {
                root = root->getRight();
                return;
            }
            if (root->getRight() == nullptr) {
                root = root->getLeft();
                return;
            }
            root->getRight()->setLeft(root->getLeft()->getRight());
            root->getLeft()->setRight(root->getRight());
            root = root->getLeft();
            return;
        }
        if (value->getSize() < root->getSize()) {
            remove(value, root->getLeft());
            return;
        }
        if (value->getSize() >= root->getSize()) {
            remove(value, root->getRight());
        }
    }

    T *search(NodeTree<T> *root, int size, const bool isInverse) {
        if (root == nullptr) {
            return nullptr;
        }
        if (size == root->getSize()) {
            return root->getData();
        }
        if (isInverse) {    // ARBOL DE TRAMPAS
            if (size < root->getSize()) {
                return search(root->getRight(), size, isInverse);
            }
            if (size >= root->getSize()) {
                return search(root->getLeft(), size, isInverse);
            }
        } else {    // ARBOL DE ENEMIGOS
            if (size < root->getSize()) {
                return search(root->getLeft(), size, isInverse);
            }
            if (size >= root->getSize()) {
                return search(root->getRight(), size, isInverse);
            }
        }
    }

public:
    TreeBB() {
        this->root = nullptr;
    }

    ~TreeBB() {
        delete this->root;
    }

    NodeTree<T> *getRoot() {
        return this->root;
    }

    void setRoot(NodeTree<T> *root) {
        this->root = root;
    }

    void insert(NodeTree<T> *newNode, const bool isInverse) {
        this->insert(newNode, this->root, isInverse);
    }

    void remove(NodeTree<T> *value) {
        this->remove(value, this->root);
    }

    T *search(const int size, const bool isInverse) {
        return this->search(this->root, size, isInverse);
    }

    bool isLeaf(NodeTree<T> *node) {
        return node->getLeft() == nullptr && node->getRight() == nullptr;
    }

};



#endif //TREEBB_H
