#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__QUEUE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__QUEUE_CPP

#include "../../headers/Queue/Queue.h"

template<class T>
bool Queue<T>::isEmpty() const {
    return head_ == nullptr;
}

template<class T>
Queue<T>::Queue(const T &data) {
    try {
        head_ = std::make_shared<ElemOfQueue>(data);
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
Queue<T>::Queue(T &&data) {
    try {
        head_ = std::make_shared<ElemOfQueue>(std::move(data));
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
Queue<T>::Queue(const Queue<T> &queue) {
    try {
        if (queue.isEmpty()) {
            head_ = nullptr;
            return;
        } else {
            head_ = std::make_shared<ElemOfQueue>(queue.head_->data_);

            std::shared_ptr<ElemOfQueue> tempForNextElem = head_;
            std::shared_ptr<ElemOfQueue> other = queue.head_->nextElem_;

            while (other != nullptr) {
                tempForNextElem->nextElem_ = std::make_shared<ElemOfQueue>(other->data_);

                tempForNextElem = tempForNextElem->nextElem_;
                other = other->nextElem_;
            }
            tempForNextElem->nextElem_ = nullptr;
        }

    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
Queue<T>::Queue(Queue<T> &&queue) noexcept {
    head_.swap(queue.head_);
}

template<class T>
void Queue<T>::push(const T &data) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfQueue>(data);
        } else{

            auto temp = head_;
            while (temp->nextElem_ != nullptr) {
                temp = temp->nextElem_;
            }
            temp->nextElem_ = std::make_shared<ElemOfQueue>(data);
        }
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
void Queue<T>::push(T &&data) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfQueue>(std::move(data));
            return;
        }

        auto temp = head_;
        while (temp->nextElem_ != nullptr) {
            temp = temp->nextElem_;
        }
        temp->nextElem_ = std::make_shared<ElemOfQueue>(std::move(data));
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
void Queue<T>::pop() {
    if (this->isEmpty()) throw std::logic_error("The queue is already empty in function pop()");
    head_ = head_->nextElem_;
}

template<class T>
std::weak_ptr<typename Queue<T>::ElemOfQueue> Queue<T>::getFront() {
    return head_;
}

template<class T>
std::weak_ptr<typename Queue<T>::ElemOfQueue> Queue<T>::getBack() {
    if (this->isEmpty()) return {};
    auto elem = head_;
    while (elem->nextElem_ != nullptr) {
        elem = elem->nextElem_;
    }
    return elem;
}

template<class T>
size_t Queue<T>::getSize() const {
    size_t size = 0;
    auto elem = head_;
    while (elem != nullptr) {
        elem = elem->nextElem_;
        ++size;
    }
    return size;
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__QUEUE_CPP
