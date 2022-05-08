#ifndef LAB2_HUFFMON_CODING_STACK_H
#define LAB2_HUFFMON_CODING_STACK_H

#include <cstddef>
#include <stdexcept>
#include <memory>
#include <iostream>
#include "../List/List.h"

template<class T>
class Stack{
private:

    struct ElemOfStack{
        T data_;
        std::shared_ptr<ElemOfStack> nextElem_;
        explicit ElemOfStack(const T& data) : data_(data), nextElem_(nullptr) { }
        explicit ElemOfStack(T &&data) noexcept : data_(std::move(data)), nextElem_(nullptr) { }
    };

    std::shared_ptr<ElemOfStack> head_;

public:
    Stack() : head_() { }
    explicit Stack(const T& data);
    explicit Stack(T&& data);
    Stack(const Stack<T>& other);
    Stack(Stack<T>&& other) noexcept ;
    Stack& operator=(const Stack<T> &other) & ;
    Stack& operator=(Stack<T> &&other) & noexcept;

    void push(const T& data);
    void push(T&& data);
    void pop();
    std::weak_ptr<ElemOfStack> getFront();
    std::weak_ptr<ElemOfStack> getBack();
    bool isEmpty() const;
    size_t getSize() const;
    List<T> getAllData();
    ~Stack() = default;
};



#include "../../src/Stack/Stack.cpp"


#endif //LAB2_HUFFMON_CODING_STACK_H
