#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include "elemOfStack.h"
#include <cstddef>
#include <stdexcept>
template<class T>
class stack{
private:
    elemOfStack<T> *head;
public:
    stack(elemOfStack<T> *elemOfStack);
    stack(T data);
    stack();

    void push(elemOfStack<T> *newElem);
    void push(T data);
    void push();
    void pop();
    elemOfStack<T> *getFront();
    elemOfStack<T> *getBack();
    bool isEmpty() const;
    size_t getSize() const;
    ~stack();
};

#include "../../src/stack/stack.cpp"

#endif //LAB3_STACK_H
