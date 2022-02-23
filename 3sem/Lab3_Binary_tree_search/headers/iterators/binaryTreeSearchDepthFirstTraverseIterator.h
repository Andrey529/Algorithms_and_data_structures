#ifndef LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_H
#define LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_H

#include "iterator.h"
#include "../binaryTreeSearch/elemOfBinaryTreeSearch.h"
#include "../stack/stack.h"

template<class T>
class binaryTreeSearchDepthFirstTraverseIterator : public iterator<elemOfBinaryTreeSearch<T>>{   // методов обхода в глубину
private:
    elemOfBinaryTreeSearch<T> *current;
    stack<elemOfBinaryTreeSearch<T>> *Stack;
public:
    binaryTreeSearchDepthFirstTraverseIterator(elemOfBinaryTreeSearch<T> *start = nullptr);
    ~binaryTreeSearchDepthFirstTraverseIterator() = default;

    elemOfBinaryTreeSearch<T> *getCurrent() const;
    void setCurrent(elemOfBinaryTreeSearch<T> *current);

    elemOfBinaryTreeSearch<T> next() override;
    bool hasNext() override;
};

#include "../../src/iterators/binaryTreeSearchDepthFirstTraverseIterator.cpp"

#endif //LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_H