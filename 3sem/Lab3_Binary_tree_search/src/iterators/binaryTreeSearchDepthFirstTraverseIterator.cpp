#ifndef LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_CPP
#define LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_CPP

#include "../../headers/iterators/binaryTreeSearchDepthFirstTraverseIterator.h"

template<class T>
binaryTreeSearchDepthFirstTraverseIterator<T>::binaryTreeSearchDepthFirstTraverseIterator(
        elemOfBinaryTreeSearch<T> *start) {
    this->current = start;
    this->Stack = new stack<elemOfBinaryTreeSearch<T>>(*(this->current));
}

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearchDepthFirstTraverseIterator<T>::getCurrent() const {
    return this->current;
}

template<class T>
void binaryTreeSearchDepthFirstTraverseIterator<T>::setCurrent(elemOfBinaryTreeSearch<T> *current) {
    this->current = current;
}

template<class T>
elemOfBinaryTreeSearch<T> binaryTreeSearchDepthFirstTraverseIterator<T>::next() {
    if (!hasNext()) {
        throw std::out_of_range("No more elements in binary tree search. Function next()");
    }
    auto currentData = this->current->getData();

    if (this->current->getNextRight() != nullptr)
        this->Stack->push(*(this->current->getNextRight()));

    if (this->current->getNextLeft() != nullptr)
        this->current = this->current->getNextLeft();
    else {
        this->current = this->Stack->getFront()->getData();
        this->Stack->pop();
    }

    return currentData;  // return current
}

template<class T>
bool binaryTreeSearchDepthFirstTraverseIterator<T>::hasNext() {
    return ( (this->current != nullptr) && (this->Stack->getFront() != nullptr) );
}


#endif //LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_CPP
