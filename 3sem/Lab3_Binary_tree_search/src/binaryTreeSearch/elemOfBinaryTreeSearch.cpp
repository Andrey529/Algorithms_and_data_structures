#ifndef LAB3_ELEMOFBINARYTREESEARCH_CPP
#define LAB3_ELEMOFBINARYTREESEARCH_CPP

#include "../../headers/binaryTreeSearch/elemOfBinaryTreeSearch.h"

template<class T>
T elemOfBinaryTreeSearch<T>::getData() const {
    return this->data;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setData(T data) {
    this->data = data;
}

template<class T>
elemOfBinaryTreeSearch<T> *elemOfBinaryTreeSearch<T>::getParent() const {
    return this->parent;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setParent(elemOfBinaryTreeSearch *parent) {
    this->parent = parent;
}

template<class T>
elemOfBinaryTreeSearch<T> *elemOfBinaryTreeSearch<T>::getNextLeft() const {
    return this->nextLeft;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setNextLeft(elemOfBinaryTreeSearch *nextLeft) {
    this->nextLeft = nextLeft;
}

template<class T>
elemOfBinaryTreeSearch<T> *elemOfBinaryTreeSearch<T>::getNextRight() const {
    return this->nextRight;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setNextRight(elemOfBinaryTreeSearch *nextRight) {
    this->nextRight = nextRight;
}

#endif //LAB3_ELEMOFBINARYTREESEARCH_CPP
