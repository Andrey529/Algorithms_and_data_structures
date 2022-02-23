#ifndef COURSEWORK_STACK_CPP
#define COURSEWORK_STACK_CPP

#include "../../headers/stack/stack.h"

template<class T>
stack<T>::stack() {
    this->head = nullptr;
}

template<class T>
stack<T>::stack(elemOfStack<T> *elemOfStack) {
    this->head = elemOfStack;
}

template<class T>
stack<T>::stack(T data) {
    auto *newElem = new elemOfStack<T>(data);
    this->head = newElem;
}

template<class T>
void stack<T>::push(elemOfStack<T> *newElem) {
    if (this->head == nullptr) {
        this->head = newElem;
        return;
    }

    elemOfStack<T> *temp = this->head;
    this->head = newElem;
    newElem->setNextElem(temp);
}

template<class T>
void stack<T>::push(T data) {
    auto *newElem = new elemOfStack<T>(data);
    if (this->head == nullptr) {
        this->head = newElem;
        return;
    }

    elemOfStack<T> *temp = this->head;
    this->head = newElem;
    newElem->setNextElem(temp);
}

template<class T>
void stack<T>::push() {
    auto *newElem = new elemOfStack<T>(0);
    if (this->head == nullptr) {
        this->head = newElem;
        return;
    }

    elemOfStack<T> *temp = this->head;
    this->head = newElem;
    newElem->setNextElem(temp);
}

template<class T>
void stack<T>::pop() {
    if (this->head == nullptr) throw std::logic_error("The stack is already empty in function pop()");
    if (this->head->getNextElem() == nullptr) {
        this->head = nullptr;
        return;
    }
    this->head = this->head->getNextElem();
}

template<class T>
elemOfStack<T> *stack<T>::getFront() {
    return this->head;
}

template<class T>
elemOfStack<T> *stack<T>::getBack() {
    elemOfStack<T> *elem = this->head;
    if(elem == nullptr) return nullptr;
    while (elem->getNextElem() != nullptr) {
        elem = elem->getNextElem();
    }
    return elem;
}

template<class T>
bool stack<T>::isEmpty() const {
    return this->head == nullptr;
}

template<class T>
size_t stack<T>::getSize() const {
    elemOfStack<T> *elem = this->head;
    size_t size = 0;
    while (elem != nullptr) {
        elem = elem->getNextElem();
        size++;
    }
    return size;
}

template<class T>
stack<T>::~stack() {
    elemOfStack<T> *elem = this->head;
    elemOfStack<T> *temp;
    while (elem != nullptr) {
        temp = elem;
        elem = elem->getNextElem();
        delete temp;
    }
}

#endif //COURSEWORK_STACK_CPP