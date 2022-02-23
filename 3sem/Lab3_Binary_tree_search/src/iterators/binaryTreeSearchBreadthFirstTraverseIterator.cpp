#ifndef LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_CPP
#define LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_CPP

#include "../../headers/iterators/binaryTreeSearchBreadthFirstTraverseIterator.h"

template<class T>
binaryTreeSearchBreadthFirstTraverseIterator<T>::binaryTreeSearchBreadthFirstTraverseIterator(
        elemOfBinaryTreeSearch<T> *start) {
    this->current = start;
    this->Queue = new queue<elemOfBinaryTreeSearch<T>>(*(this->current));
}

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearchBreadthFirstTraverseIterator<T>::getCurrent() const {
    return this->current;
}

template<class T>
void binaryTreeSearchBreadthFirstTraverseIterator<T>::setCurrent(elemOfBinaryTreeSearch<T> *current) {
    this->current = current;
}

template<class T>
elemOfBinaryTreeSearch<T> binaryTreeSearchBreadthFirstTraverseIterator<T>::next() {
    if (!hasNext()) {
        throw std::out_of_range("No more elements in binary tree search. Function next()");
    }
    this->current = this->Queue->getFront()->getData();
    this->Queue->pop();  // delete current in queue
    if (this->current->getNextLeft() != nullptr)  // set in queue childs of current
        this->Queue->push(*(this->current->getNextLeft()));
    if (this->current->getNextRight() != nullptr)
        this->Queue->push(*(this->current->getNextRight()));
    return this->current->getData();  // return current
}

template<class T>
bool binaryTreeSearchBreadthFirstTraverseIterator<T>::hasNext() {
    return ( (this->current != nullptr) && (this->Queue->getFront() != nullptr) );
}



#endif //LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_CPP
