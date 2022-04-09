#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__QUEUE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__QUEUE_H

#include <cstddef>
#include <stdexcept>
#include <memory>
#include <iostream>

template<class T>
class Queue{
private:

    struct ElemOfQueue{
        T data_;
        std::shared_ptr<ElemOfQueue> nextElem_;
        explicit ElemOfQueue(const T& data) : data_(data), nextElem_(nullptr) { }
        explicit ElemOfQueue(T &&data) noexcept : data_(std::move(data)), nextElem_(nullptr) { }
    };

    std::shared_ptr<ElemOfQueue> head_;
public:
    Queue() : head_() { }
    explicit Queue(const T& data);
    explicit Queue(T&& data);
    Queue(const Queue<T>& queue);
    Queue(Queue<T>&& queue) noexcept ;

    void push(const T& data);
    void push(T&& data);
    void pop();
    std::weak_ptr<ElemOfQueue> getFront();
    std::weak_ptr<ElemOfQueue> getBack();
    bool isEmpty() const;
    size_t getSize() const;
    ~Queue() = default;
};

#include "../../src/Queue/Queue.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__QUEUE_H
