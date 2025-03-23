//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef NODETREE_H
#define NODETREE_H



template <class T> class NodeTree {

private:
    T *data;
    int size;
    NodeTree *left;
    NodeTree *right;

public:
    NodeTree(T *data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~NodeTree() {
        delete data;
    }

    T *getData() {
        return this->data;
    }

    void setData(T *data) {
        this->data = data;
    }

    int getSize() {
        return this->size;
    }

    void setSize(int size) {
        this->size = size;
    }

    NodeTree *getLeft() {
        return this->left;
    }

    void setLeft(NodeTree *left) {
        this->left = left;
    }

    NodeTree *getRight() {
        return this->right;
    }

    void setRight(NodeTree *right) {
        this->right = right;
    }

};



#endif //NODETREE_H
