#ifndef LAB3_ELEMOFQUEUE_CPP
#define LAB3_ELEMOFQUEUE_CPP


#include "../../headers/queue/elemOfQueue.h"


template<class T>
elemOfQueue<T>::elemOfQueue(T data) : data(data), nextElem(nullptr){ }

template<class T>
elemOfQueue<T>::elemOfQueue() : data(0), nextElem(nullptr) { }

template<class T>
elemOfQueue<T>::elemOfQueue(elemOfQueue<T> *elem) : data(elem->getData()), nextElem(elem->getNextElem()) { }

template<class T>
T elemOfQueue<T>::getData() const{
    return this->data;
}

template<class T>
void elemOfQueue<T>::setData(T data) {
    this->data = data;
}

template<class T>
elemOfQueue<T> *elemOfQueue<T>::getNextElem() const {
    return this->nextElem;
}

template<class T>
void elemOfQueue<T>::setNextElem(elemOfQueue *nextElem) {
    this->nextElem = nextElem;
}

template<class T>
T *elemOfQueue<T>::getData() {
    return &(this->data);
}


#endif //LAB3_ELEMOFQUEUE_CPP
