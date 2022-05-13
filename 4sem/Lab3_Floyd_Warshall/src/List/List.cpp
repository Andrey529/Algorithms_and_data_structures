#ifndef LAB3_FLOYD_WARSHALL_LIST_CPP
#define LAB3_FLOYD_WARSHALL_LIST_CPP

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

template<typename U>
std::ostream &operator<<(std::ostream &out, const List<U> &list) {
    int i = 1;
    for (size_t index = 0; index < list.getSize(); index++) {
        out << list.at(index);
        i++;
    }
    return out;
}


template<class T>
typename List<T>::ListIterator List<T>::begin() {
    if (head_ == nullptr)
        throw std::logic_error("An Iterator cannot be created because there is no element in the list.");
    return ListIterator(head_);
}

template<class T>
typename List<T>::ListIterator List<T>::end() {
    if (head_ == nullptr)
        throw std::logic_error("An Iterator cannot be created because there is no element in the list.");
    return ListIterator(nullptr);
}

template<class T>
typename List<T>::ListIteratorConst List<T>::cbegin() const{
    if (head_ == nullptr)
        throw std::logic_error("An Iterator cannot be created because there is no element in the list.");
    return ListIteratorConst(head_);
}

template<class T>
typename List<T>::ListIteratorConst List<T>::cend() const{
    if (head_ == nullptr)
        throw std::logic_error("An Iterator cannot be created because there is no element in the list.");
    return ListIteratorConst(nullptr);
}

template<class T>
template<typename Comparator>
void List<T>::sort(Comparator comparator) {
    if (isEmpty()) return;
    if (head_->nextElem_ == nullptr) return;

    elemType current = head_;
    elemType index;

    int size = getSize() - 1;
    while (size--) {
        elemType prev = nullptr;
        elemType cur = head_;
        while (cur->nextElem_ != nullptr) {
            if (comparator(cur->nextElem_->data_, cur->data_)) {
                if (prev == nullptr) {
                    //first node
                    auto nxt = cur->nextElem_;
                    cur->nextElem_ = nxt->nextElem_;
                    nxt->nextElem_ = cur;
                    prev = nxt;
                    head_ = prev;
                } else {
                    auto nxt = cur->nextElem_;
                    prev->nextElem_ = nxt;
                    cur->nextElem_ = nxt->nextElem_;
                    nxt->nextElem_ = cur;
                    prev = nxt;
                }
            } else {
                prev = cur;
                cur = cur->nextElem_;
            }
        }
    }

}

template<class T>
typename List<T>::elemType List<T>::getPrevious(List::elemType elem) {
    if (elem == head_) {
        return nullptr;
    }
    auto tmp = head_;
    while (tmp->nextElem_ != nullptr) {
        if (tmp->nextElem_ == elem) {
            return tmp;
        }
        tmp = tmp->nextElem_;
    }
    return nullptr;
}

template<class T>
void List<T>::swap(elemType elem1, elemType elem2) {
    if (elem1 == head_) {
        if (elem1->nextElem_ == elem2) { // elem1 elem2 . . . . .
            head_ = elem2;
            elem1->nextElem_ = elem2->nextElem_;
            elem2->nextElem_ = elem1;
        } else { // elem1 . . . . . . elem2 . . . .
            auto elem2Prev = getPrevious(elem2);
            auto elem2Next = elem2->nextElem_;
            head_ = elem2;
            elem2->nextElem_ = elem1->nextElem_;

            elem2Prev->nextElem_ = elem1;
            elem1->nextElem_ = elem2Next;
        }

    } else {
        if (elem1->nextElem_ == elem2) { // . . . . elem1 elem2 . . . . .
            auto elem1Prev = getPrevious(elem1);
            elem1Prev->nextElem_ = elem2;
            elem1->nextElem_ = elem2->nextElem_;
            elem2->nextElem_ = elem1;
        } else { // . . . . . . elem1 . . . . . . elem2 . . . .
            auto elem1Prev = getPrevious(elem1);
            auto elem1Next = elem1->nextElem_;
            auto elem2Prev = getPrevious(elem2);
            auto elem2Next = elem2->nextElem_;

            elem1Prev->nextElem_ = elem2;
            elem2->nextElem_ = elem1Next;

            elem2Prev->nextElem_ = elem1;
            elem1->nextElem_ = elem2Next;
        }
    }
}

template<class T>
void List<T>::clear() {
    head_ = nullptr;
}

template<class T>
void List<T>::remove(size_t index) {
    if (head_ == nullptr) throw std::invalid_argument("List already empty");
    if (index > this->getSize()-1) {
        throw std::invalid_argument("Does not have element with that index, function remove()");
    }

    if (index == 0) {
        head_ = head_->nextElem_;
        return;
    }

    auto prevElem = head_;
    for (int i = 0; i < index-1; ++i) {
        prevElem = prevElem->nextElem_;
    }

    prevElem->nextElem_ = prevElem->nextElem_->nextElem_;
}

template<class T>
bool List<T>::operator==(const List<T> &other) {
    if (this->getSize() != other.getSize()) return false;

    ListIteratorConst itThis = this->cbegin();
    ListIteratorConst itOther = other.cbegin();
    for (; itThis != this->cend(); ++itThis) {
        if (*itThis != *itOther) {
            return false;
        }
        ++itOther;
    }
    return true;
}

template<typename U>
std::wostream &operator<<(std::wostream &out, const List<U> &list) {
    int i = 1;
    for (size_t index = 0; index < list.getSize(); index++) {
        out << list.at(index);
        i++;
    }
    return out;
}

template<class T>
bool List<T>::contains(const T &data) {
    auto elem = head_;
    while (elem != nullptr) {
        if (elem->data_ == data) return true;
        elem = elem->nextElem_;
    }
    return false;
}


template<class T>
typename List<T>::ListIterator &List<T>::ListIterator::operator=(const List::ListIterator &other) {
    current_ = other.current_;
    return *this;
}



template<class T>
typename List<T>::ListIterator &List<T>::ListIterator::operator=(List::elemType pNode) {
    current_ = pNode;
    return *this;
}

template<class T>
typename List<T>::ListIterator &List<T>::ListIterator::operator++() {
    if (current_)
        current_ = current_->nextElem_;
    return *this;
}

template<class T>
typename List<T>::ListIterator List<T>::ListIterator::operator++(int) {
    ListIterator iterator = *this;
    ++*this;
    return iterator;
}

template<class T>
bool List<T>::ListIterator::operator!=(const List::ListIterator &iterator) {
    return current_ != iterator.current_;
}

template<class T>
T &List<T>::ListIterator::operator*() {
    return current_->data_;
}

template<class T>
typename List<T>::ListIteratorConst &List<T>::ListIteratorConst::operator=(const List::ListIteratorConst &other) {
    current_ = other.current_;
    return *this;
}

template<class T>
typename List<T>::ListIteratorConst &List<T>::ListIteratorConst::operator=(std::shared_ptr<const ElemOfList> pNode) {
    current_ = pNode;
    return *this;
}

template<class T>
typename List<T>::ListIteratorConst &List<T>::ListIteratorConst::operator++() {
    if (current_)
        current_ = current_->nextElem_;
    return *this;
}

template<class T>
const typename List<T>::ListIteratorConst List<T>::ListIteratorConst::operator++(int) {
    ListIterator iterator = *this;
    ++*this;
    return iterator;
}

template<class T>
bool List<T>::ListIteratorConst::operator!=(const List::ListIteratorConst &iterator) {
    return current_ != iterator.current_;
}

template<class T>
const T &List<T>::ListIteratorConst::operator*() const {
    return current_->data_;
}

#endif //LAB3_FLOYD_WARSHALL_LIST_CPP