//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef NODELIST_H
#define NODELIST_H



template <class T> class NodeList {

private:
    T *data;
    NodeList *next;

public:
    NodeList(T *data) {
        this->data = data;
        this->next = nullptr;
    }

    ~NodeList() {
        delete data;
    }

    T *getData() {
        return this->data;
    }

    void setData(T *data) {
        this->data = data;
    }

    NodeList *getNext() {
        return this->next;
    }

    void setNext(NodeList *next) {
        this->next = next;
    }

};



#endif //NODELIST_H
