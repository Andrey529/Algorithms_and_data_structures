#ifndef LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_H
#define LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_H

#include "iterator.h"
#include "../binaryTreeSearch/elemOfBinaryTreeSearch.h"
#include "../queue/queue.h"

template<class T>
class binaryTreeSearchBreadthFirstTraverseIterator : public iterator<elemOfBinaryTreeSearch<T>>{   // методов обхода в ширину
private:
    elemOfBinaryTreeSearch<T> *current;
    queue<elemOfBinaryTreeSearch<T>> *Queue;
public:
    binaryTreeSearchBreadthFirstTraverseIterator(elemOfBinaryTreeSearch<T> *start = nullptr);
    ~binaryTreeSearchBreadthFirstTraverseIterator() = default;

    elemOfBinaryTreeSearch<T> *getCurrent() const;
    void setCurrent(elemOfBinaryTreeSearch<T> *current);

    elemOfBinaryTreeSearch<T> next() override;
    bool hasNext() override;
};

#include "../../src/iterators/binaryTreeSearchBreadthFirstTraverseIterator.cpp"


#endif //LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_H
