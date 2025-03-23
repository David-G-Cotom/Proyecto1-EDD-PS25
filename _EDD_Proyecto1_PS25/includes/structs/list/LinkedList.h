//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "NodeList.h"


template <class T> class LinkedList {

private:
    NodeList<T> *head;
    int size;

public:
    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    ~LinkedList() {
        delete this->head;
    }

    NodeList<T> *getHead() {
        return this->head;
    }

    void setHead(NodeList<T> *head) {
        this->head = head;
    }

    int getSize() {
        return this->size;
    }

    void setSize(int size) {
        this->size = size;
    }

    NodeList<T> *getElementAt(int index) {
        if (index < 0 || index >= this->size) return nullptr;

        if (index == 0) return this->head;

        int counter = 0;
        NodeList<T> *current = this->head;
        while (counter < index) {
            current = current->getNext();
            counter++;
        }
        return current;
    }

    void addElementAt(T *element) {
        auto *newNode = new NodeList<T>(element);
        if (this->isEmpty()) {
            this->head = newNode;
            ++this->size;
            return;
        }
        NodeList<T> *current = this->head;
        while (current->getNext() != nullptr) current = current->getNext();

        current->setNext(newNode);
        ++this->size;
    }

    T *removeElementAt(int index) {
        NodeList<T> *current = this->head;
        NodeList<T> *prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->getNext();
        }
        if (prev != nullptr) {
            prev->setNext(current->getNext());
        } else {
            this->head = current->getNext();
        }
        current->setNext(nullptr);
        --this->size;
        return current->getData();
    }

    T *removeElements(T *element) {
        NodeList<T> *current = this->head;
        NodeList<T> *prev = nullptr;
        while (current != nullptr && current->getData() != element) {
            prev = current;
            current = current->getNext();
        }
        if (current == nullptr) return nullptr;

        if (prev != nullptr) {
            prev->setNext(current->getNext());
        } else {
            this->head = current->getNext();
        }
        current->setNext(nullptr);
        --this->size;
        return current->getData();
    }

    bool isEmpty() {
        return this->size == 0 && this->head == nullptr;
    }

};



#endif //LINKEDLIST_H
