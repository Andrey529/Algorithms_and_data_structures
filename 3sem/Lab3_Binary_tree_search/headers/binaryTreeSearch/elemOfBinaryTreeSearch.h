#ifndef LAB3_ELEMOFBINARYTREESEARCH_H
#define LAB3_ELEMOFBINARYTREESEARCH_H

template<class T>
class elemOfBinaryTreeSearch{
private:
    T data;
    elemOfBinaryTreeSearch *parent;
    elemOfBinaryTreeSearch *nextLeft;
    elemOfBinaryTreeSearch *nextRight;
public:
    elemOfBinaryTreeSearch(T data = 0, elemOfBinaryTreeSearch *parent = nullptr,
                           elemOfBinaryTreeSearch *nextLeft = nullptr, elemOfBinaryTreeSearch *nextRight = nullptr)
                           : data(data), parent(parent), nextLeft(nextLeft), nextRight(nextRight) {}
    ~elemOfBinaryTreeSearch() = default;

    T getData() const;
    void setData(T data);

    elemOfBinaryTreeSearch *getParent() const;
    void setParent(elemOfBinaryTreeSearch *parent);

    elemOfBinaryTreeSearch *getNextLeft() const;
    void setNextLeft(elemOfBinaryTreeSearch *nextLeft);

    elemOfBinaryTreeSearch *getNextRight() const;
    void setNextRight(elemOfBinaryTreeSearch *nextRight);

};

#include "../../src/binaryTreeSearch/elemOfBinaryTreeSearch.cpp"


#endif //LAB3_ELEMOFBINARYTREESEARCH_H
