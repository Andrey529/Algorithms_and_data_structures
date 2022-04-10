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
List<T>::List(const List<T> &other) {
    try {
        if (other.isEmpty()) {
            head_ = nullptr;
        } else {
            head_ = std::make_shared<ElemOfList>(other.head_->data_);

            std::shared_ptr<ElemOfList> tempForNextElem = head_;
            std::shared_ptr<ElemOfList> otherElem = other.head_->nextElem_;

            while (otherElem != nullptr) {
                tempForNextElem->nextElem_ = std::make_shared<ElemOfList>(otherElem->data_);

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
List<T>::List(List<T> &&other) noexcept {
    head_.swap(other.head_);

}

template<class T>
void List<T>::pushBack(const T &data) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfList>(data);
        } else {
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
        } else {
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
        } else {
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
        } else {
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
    if (getSize() == 1) {
        head_ = nullptr;
    } else {
        auto elem = head_;

        while (elem->nextElem_->nextElem_ != nullptr) {
            elem = elem->nextElem_;
        }
        elem->nextElem_ = nullptr;
    }
}

template<class T>
void List<T>::popFront() {
    if (this->isEmpty()) throw std::logic_error("The list is already empty in function popBack()");
    head_ = head_->nextElem_;
}

template<class T>
void List<T>::insert(const T &data, size_t index) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfList>(data);
            return;
        }

        if (index + 1 > getSize()) {
            throw std::invalid_argument("Index greater than size of list in function insert()");
        }

        if (index == 0) {
            auto newElem = std::make_shared<ElemOfList>(data);
            newElem->nextElem_ = head_;
            head_ = newElem;
            return;
        }

        auto elem = head_;
        for (int i = 0; i < index - 1; i++) {
            elem = elem->nextElem_;
        }
        auto newElem = std::make_shared<ElemOfList>(data);
        newElem->nextElem_ = elem->nextElem_;
        elem->nextElem_ = newElem;
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
void List<T>::insert(T &&data, size_t index) {
    try {
        if (this->isEmpty()) {
            head_ = std::make_shared<ElemOfList>(std::move(data));
            return;
        }

        if (index + 1 > getSize()) {
            throw std::invalid_argument("Index greater than size of list in function insert()");
        }

        if (index == 0) {
            auto newElem = std::make_shared<ElemOfList>(std::move(data));
            newElem->nextElem_ = head_;
            head_ = newElem;
            return;
        }

        auto elem = head_;
        for (int i = 0; i < index - 1; i++) {
            elem = elem->nextElem_;
        }
        auto newElem = std::make_shared<ElemOfList>(std::move(data));
        newElem->nextElem_ = elem->nextElem_;
        elem->nextElem_ = newElem;
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T>
size_t List<T>::getSize() const {
    size_t size = 0;
    auto elem = head_;
    while (elem != nullptr) {
        elem = elem->nextElem_;
        ++size;
    }
    return size;
}

template<class T>
const T &List<T>::at(size_t index) const {
    if ((index + 1) > getSize()) {
        throw std::invalid_argument("Index greater than size of list in function at()");
    }
    auto elem = head_;

    int i = 0;
    while (i != index) {
        elem = elem->nextElem_;
        i++;
    }
    return elem->data_;
}

template<class T>
T &List<T>::at(size_t index) {
    if ((index + 1) > getSize()) {
        throw std::invalid_argument("Index greater than size of list in function at()");
    }
    auto elem = head_;

    int i = 0;
    while (i != index) {
        elem = elem->nextElem_;
        i++;
    }
    return elem->data_;
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__LIST_CPP
