//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef NODEMATRIX_H
#define NODEMATRIX_H



template <class T> class NodeMatrix {

private:
    T *data;
    int x, y, z;
    NodeMatrix *next;
    NodeMatrix *prev;
    NodeMatrix *top;
    NodeMatrix *bottom;
    NodeMatrix *front;
    NodeMatrix *back;

public:
    NodeMatrix(T *data, int x, int y, int z) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
        this->top = nullptr;
        this->bottom = nullptr;
        this->front = nullptr;
        this->back = nullptr;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    ~NodeMatrix() {
        delete data;
    }

    T *getData() {
        return this->data;
    }

    void setData(T *data) {
        this->data = data;
    }

    int getX() {
        return this->x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() {
        return this->y;
    }

    void setY(int y) {
        this->y = y;
    }

    int getZ() {
        return this->z;
    }

    void setZ(int z) {
        this->z = z;
    }

    NodeMatrix *getNext() {
        return this->next;
    }

    void setNext(NodeMatrix *next) {
        this->next = next;
    }

    NodeMatrix *getPrev() {
        return this->prev;
    }

    void setPrev(NodeMatrix *prev) {
        this->prev = prev;
    }

    NodeMatrix *getTop() {
        return this->top;
    }

    void setTop(NodeMatrix *top) {
        this->top = top;
    }

    NodeMatrix *getBottom() {
        return this->bottom;
    }

    void setBottom(NodeMatrix *bottom) {
        this->bottom = bottom;
    }

    NodeMatrix *getFront() {
        return this->front;
    }

    void setFront(NodeMatrix *front) {
        this->front = front;
    }

    NodeMatrix *getBack() {
        return this->back;
    }

    void setBack(NodeMatrix *back) {
        this->back = back;
    }

};



#endif //NODEMATRIX_H
