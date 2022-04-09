#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__LIST_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__LIST_CPP

#include "../../headers/List/List.h"

template<class T>
bool List<T>::isEmpty() const {
    return head_ == nullptr;
}

template<class T>
List<T>::List(const T &data) {
    try {
        head_ = std::make_shared<ElemOfList>(data);
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
List<T>::List(T &&data) {
    try {
        head_ = std::make_shared<ElemOfList>(std::move(data));
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
List<T>::List(const List<T> &list) {
    try {
        if (list.isEmpty()) {
            head_ = nullptr;
        } else {
            head_ = std::make_shared<ElemOfList>(list.head_->data_);

            std::shared_ptr<ElemOfList> tempForNextElem = head_;
            std::shared_ptr<ElemOfList> other = list.head_->nextElem_;

            while (other != nullptr) {
                tempForNextElem->nextElem_ = std::make_shared<ElemOfList>(other->data_);

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
List<T>::List(List<T> &&list) noexcept {
    head_.swap(list.head_);

}

template<class T>
void List<T>::pushBack(const T &data) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfList>(data);
        } else{
            auto temp = head_;
            while (temp->nextElem_ != nullptr) {
                temp = temp->nextElem_;
            }
            temp->nextElem_ = std::make_shared<ElemOfList>(data);
        }
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
void List<T>::pushBack(T &&data) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfList>(std::move(data));
        } else{
            auto temp = head_;
            while (temp->nextElem_ != nullptr) {
                temp = temp->nextElem_;
            }
            temp->nextElem_ = std::make_shared<ElemOfList>(std::move(data));
        }
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
void List<T>::pushFront(const T &data) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfList>(data);
        } else{
            auto newElem = std::make_shared<ElemOfList>(data);
            newElem->nextElem_ = head_;
            head_ = newElem;
        }
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
void List<T>::pushFront(T &&data) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfList>(std::move(data));
        } else{
            auto newElem = std::make_shared<ElemOfList>(std::move(data));
            newElem->nextElem_ = head_;
            head_ = newElem;
        }
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
void List<T>::popBack() {
    if (this->isEmpty()) throw std::logic_error("The list is already empty in function popBack()");
    if (head_.nextElem_ == nullptr) {
        head_ = nullptr;
        return;
    }
    auto elem = head_;

    while (elem->nextElem_->nextElem_ != nullptr) {
        elem = elem->nextElem_;
    }
    elem->nextElem_ = nullptr;
}

template<class T>
void List<T>::popFront() {
    if (this->isEmpty()) throw std::logic_error("The list is already empty in function popBack()");
    head_ = head_->nextElem_;
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__LIST_CPP
