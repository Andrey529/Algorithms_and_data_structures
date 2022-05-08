#ifndef LAB2_HUFFMON_CODING_STACK_CPP
#define LAB2_HUFFMON_CODING_STACK_CPP

#include "../../headers/Stack/Stack.h"

template<class T>
Stack<T>::Stack(const T &data) {
    try {
        head_ = std::make_shared<ElemOfStack>(data);
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
Stack<T>::Stack(T &&data) {
    try {
        head_ = std::make_shared<ElemOfStack>(std::move(data));
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
bool Stack<T>::isEmpty() const {
    return head_ == nullptr;
}

template<class T>
Stack<T>::Stack(const Stack<T> &other) {
    try {
        if (other.isEmpty()) {
            head_ = nullptr;
        } else {
            head_ = std::make_shared<ElemOfStack>(other.head_->data_);

            std::shared_ptr<ElemOfStack> tempForNextElem = head_;
            std::shared_ptr<ElemOfStack> otherElem = other.head_->nextElem_;

            while (otherElem != nullptr) {
                tempForNextElem->nextElem_ = std::make_shared<ElemOfStack>(otherElem->data_);

                tempForNextElem = tempForNextElem->nextElem_;
                otherElem = otherElem->nextElem_;
            }
            tempForNextElem->nextElem_ = nullptr;
        }

    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
Stack<T>::Stack(Stack<T> &&other) noexcept {
    head_.swap(other.head_);
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other) &{
    try {
        if (this == &other) {
            return *this;
        }
        if (other.isEmpty()) {
            head_ = nullptr;
            return *this;
        } else {
            head_ = std::make_shared<ElemOfStack>(other.head_->data_);

            std::shared_ptr<ElemOfStack> tempForNextElem = head_;
            std::shared_ptr<ElemOfStack> otherElem = other.head_->nextElem_;

            while (otherElem != nullptr) {
                tempForNextElem->nextElem_ = std::make_shared<ElemOfStack>(otherElem->data_);

                tempForNextElem = tempForNextElem->nextElem_;
                otherElem = otherElem->nextElem_;
            }
            tempForNextElem->nextElem_ = nullptr;
            return *this;
        }

    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
Stack<T> &Stack<T>::operator=(Stack<T> &&other) & noexcept {
    if (this == &other) {
        return *this;
    }
    head_ = other.head_;
    other.~Queue();
    return *this;
}


template<class T>
void Stack<T>::push(const T &data) {
    auto newElem = std::make_shared<ElemOfStack>(data);
    if (head_ == nullptr) {
        head_ = newElem;
        return;
    }

    auto temp = head_;
    head_ = newElem;
    newElem->nextElem_ = temp;
}

template<class T>
void Stack<T>::push(T &&data) {
    auto newElem = std::make_shared<ElemOfStack>(std::move(data));
    if (head_ == nullptr) {
        head_ = newElem;
        return;
    }

    auto temp = head_;
    head_ = newElem;
    newElem->nextElem_ = temp;
}

template<class T>
void Stack<T>::pop() {
    if (head_ == nullptr) throw std::logic_error("The stack is already empty in function pop()");
    if (head_->nextElem_ == nullptr) {
        head_ = nullptr;
        return;
    }
    head_ = head_->nextElem_;
}

template<class T>
std::weak_ptr<typename Stack<T>::ElemOfStack> Stack<T>::getFront() {
    return head_;
}

template<class T>
std::weak_ptr<typename Stack<T>::ElemOfStack> Stack<T>::getBack() {
    if (head_ == nullptr) return {};
    auto elem = head_;
    while (elem->nextElem_ != nullptr) {
        elem = elem->nextElem_;
    }
    return elem;
}

template<class T>
size_t Stack<T>::getSize() const {
    auto elem = head_;
    size_t size = 0;
    while (elem != nullptr) {
        elem = elem->nextElem_;
        ++size;
    }
    return size;
}



#endif //LAB2_HUFFMON_CODING_STACK_CPP