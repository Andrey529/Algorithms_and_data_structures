#ifndef LAB2_HUFFMON_CODING_ASSOCIATIVEARRAY_CPP
#define LAB2_HUFFMON_CODING_ASSOCIATIVEARRAY_CPP

#include "../../headers/AssociativeArray/AssociativeArray.h"

template<class T_key, class T_value, class comparator>
AssociativeArray<T_key, T_value, comparator>::AssociativeArray() {
    try {
        this->rbTree_ = std::make_unique<RedBlackTree<T_key, T_value, comparator>>();
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T_key, class T_value, class comparator>
AssociativeArray<T_key, T_value, comparator>::AssociativeArray(const T_key &key, const T_value &value) {
    try {
        this->rbTree_ = std::make_unique<RedBlackTree<T_key, T_value, comparator>>(key, value);
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T_key, class T_value, class comparator>
AssociativeArray<T_key, T_value, comparator>::AssociativeArray(const AssociativeArray<T_key, T_value> &other) {
    try {
        this->rbTree_ = std::make_unique<RedBlackTree<T_key, T_value, comparator>>(*other.rbTree_.get());
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T_key, class T_value, class comparator>
AssociativeArray<T_key, T_value, comparator>&
AssociativeArray<T_key, T_value, comparator>::operator=(const AssociativeArray<T_key, T_value> &other) &{
    try {
        this->rbTree_->clear();
        this->rbTree_ = std::make_unique<RedBlackTree<T_key, T_value, comparator>>(*other.rbTree_.get());
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T_key, class T_value, class comparator>
bool AssociativeArray<T_key, T_value, comparator>::isEmpty() const {
    return rbTree_->isEmpty();
}

template<class T_key, class T_value, class comparator>
void AssociativeArray<T_key, T_value, comparator>::insert(const T_key &key, const T_value &value) {
    rbTree_->insert(key, value);
}

template<class T_key, class T_value, class comparator>
void AssociativeArray<T_key, T_value, comparator>::remove(const T_key &key) {
    rbTree_->remove(key);
}

template<class T_key, class T_value, class comparator>
std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>
AssociativeArray<T_key, T_value, comparator>::find(const T_key &key) const {
    return rbTree_->find(key);
}

template<class T_key, class T_value, class comparator>
bool AssociativeArray<T_key, T_value, comparator>::contains(const T_key &key) {
    return rbTree_->contains(key);
}

template<class T_key, class T_value, class comparator>
void AssociativeArray<T_key, T_value, comparator>::clear() {
    rbTree_->clear();
}

template<class T_key, class T_value, class comparator>
List<T_key> AssociativeArray<T_key, T_value, comparator>::getKeys() {
    return rbTree_->getKeys();
}

template<class T_key, class T_value, class comparator>
List<T_value> AssociativeArray<T_key, T_value, comparator>::getValues() {
    return rbTree_->getValues();
}

template<class T_key, class T_value, class comparator>
void AssociativeArray<T_key, T_value, comparator>::print() {
    rbTree_->print();
}

template<class T_key, class T_value, class comparator>
std::unique_ptr<Iterator<std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>>>
AssociativeArray<T_key, T_value, comparator>::createBftIterator() {
    if (rbTree_->isEmpty())
        throw std::logic_error("An Iterator cannot be created because there is no element in the associative array.");
    return rbTree_->createBftIterator();
}

template<class Key, class Value>
std::ostream &operator<<(std::ostream &out, AssociativeArray<Key, Value> &map) {
    auto it = map.createBftIterator();
    while (it->hasNext()) {
        auto elem = it->next();
        out << elem->getKey() << ' ' << elem->getValue() << std::endl;
    }
    return out;
}




#endif //LAB2_HUFFMON_CODING_ASSOCIATIVEARRAY_CPP
