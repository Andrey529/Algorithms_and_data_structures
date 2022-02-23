#ifndef LAB3_QUEUE_CPP
#define LAB3_QUEUE_CPP

#include "../../headers/queue/queue.h"


template<class T>
queue<T>::queue() {
    this->head = nullptr;
}

template<class T>
queue<T>::queue(elemOfQueue<T> *elemOfQueue) {
    this->head = elemOfQueue;
}

template<class T>
queue<T>::queue(T data) {
    auto *newElem = new elemOfQueue<T>(data);
    this->head = newElem;
}

template<class T>
queue<T>::~queue() {
    elemOfQueue<T> *elem = this->head;
    elemOfQueue<T> *temp;
    while (elem != nullptr) {
        temp = elem;
        elem = elem->getNextElem();
        delete temp;
    }
}

template<class T>
bool queue<T>::isEmpty() const{
    return this->head == nullptr;
}

template<class T>
void queue<T>::push(elemOfQueue<T> *newElem) {
    if (this->head == nullptr) {
        this->head = newElem;
        return;
    }
    elemOfQueue<T> *temp = this->head;
    while (temp->getNextElem() != nullptr) {
        temp = temp->getNextElem();
    }
    temp->setNextElem(newElem);
}

template<class T>
void queue<T>::push(T data) {
    auto *newElem = new elemOfQueue<T>(data);
    if (this->head == nullptr) {
        this->head = newElem;
        return;
    }
    elemOfQueue<T> *temp = this->head;
    while (temp->getNextElem() != nullptr) {
        temp = temp->getNextElem();
    }
    temp->setNextElem(newElem);
}

template<class T>
void queue<T>::push() {
    auto *newElem = new elemOfQueue<T>(0);
    if (this->head == nullptr) {
        this->head = newElem;
        return;
    }
    elemOfQueue<T> *temp = this->head;
    while (temp->getNextElem() != nullptr) {
        temp = temp->getNextElem();
    }
    temp->setNextElem(newElem);
}

template<class T>
void queue<T>::pop() {
    if (this->head == nullptr) throw std::logic_error("The queue is already empty in function pop()");
    elemOfQueue<T> *elem = this->head->getNextElem();
//    delete this->head;
    this->head = elem;
}

template<class T>
elemOfQueue<T> *queue<T>::getFront() {
    return this->head;
}

template<class T>
elemOfQueue<T> *queue<T>::getBack() {
    elemOfQueue<T> *elem = this->head;
    if (elem == nullptr) return nullptr;
    while (elem->getNextElem() != nullptr) {
        elem = elem->getNextElem();
    }
    return elem;
}

template<class T>
size_t queue<T>::getSize() const {
    elemOfQueue<T> *elem = this->head;
    size_t size = 0;
    while (elem != nullptr) {
        elem = elem->getNextElem();
        size++;
    }
    return size;
}

#endif //LAB3_QUEUE_CPP
