#ifndef LAB3_BINARYTREESEARCH_H
#define LAB3_BINARYTREESEARCH_H

#include "elemOfBinaryTreeSearch.h"
#include "../iterators/binaryTreeSearchDepthFirstTraverseIterator.h"
#include "../iterators/binaryTreeSearchBreadthFirstTraverseIterator.h"

template<class T>
class binaryTreeSearch{
private:
    elemOfBinaryTreeSearch<T> *head;

    void removeWhenZeroChild(elemOfBinaryTreeSearch<T> *delElem);
    void removeWhenOneChildLeft(elemOfBinaryTreeSearch<T> *delElem);
    void removeWhenOneChildRight(elemOfBinaryTreeSearch<T> *delElem);
    void removeWhenTwoChild(elemOfBinaryTreeSearch<T> *delElem);
    elemOfBinaryTreeSearch<T> *giveElemByData(T data);
public:
    binaryTreeSearch(elemOfBinaryTreeSearch<T> *head = nullptr) : head(head){}
    void destroyRecursive(elemOfBinaryTreeSearch<T> *elem);
    ~binaryTreeSearch();

    iterator<elemOfBinaryTreeSearch<T>> *create_dft_iterator(); // depth-first traverse
    iterator<elemOfBinaryTreeSearch<T>> *create_bft_iterator(); // breadth-first traverse

    bool isEmpty();
    bool contains(T data); // search for an element in the tree by key
    void insert(T data); // adding an element to the tree by key. Must work for O(logN)
    void remove(T data); // deleting a tree element by key

};

#include "../../src/binaryTreeSearch/binaryTreeSearch.cpp"


#endif //LAB3_BINARYTREESEARCH_H
