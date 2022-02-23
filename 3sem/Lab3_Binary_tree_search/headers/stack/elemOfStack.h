#ifndef LAB3_ELEMOFSTACK_H
#define LAB3_ELEMOFSTACK_H

template<class T>
class elemOfStack{
private:
    T data;
    elemOfStack *nextElem;
public:
    elemOfStack();
    elemOfStack(T data);
    elemOfStack(elemOfStack<T> *elem);
    ~elemOfStack() = default;

    T getData() const;
    T *getData();
    void setData(T data);

    elemOfStack *getNextElem() const;
    void setNextElem(elemOfStack *nextElem);

};

#include "../../src/stack/elemOfStack.cpp"

#endif //LAB3_ELEMOFSTACK_CPP
