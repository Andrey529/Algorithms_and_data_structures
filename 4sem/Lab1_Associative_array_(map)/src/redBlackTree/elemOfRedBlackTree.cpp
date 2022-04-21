#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP

#include "../../headers/redBlackTree/elemOfRedBlackTree.h"

template<class T_key, class T_value>
elemOfRedBlackTree<T_key, T_value>::elemOfRedBlackTree(const T_key &key, const T_value &value, const COLOR &color,
                                                       std::weak_ptr<elemOfRedBlackTree> parent,
                                                       std::shared_ptr<elemOfRedBlackTree> nextLeft,
                                                       std::shared_ptr<elemOfRedBlackTree> nextRight) {
    try {
        data_ = std::make_unique<dataPair<T_key, T_value>>(key, value);
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
    color_ = color;
    parent_ = parent;
    nextLeft_ = nextLeft;
    nextRight_ = nextRight;
}

template<class T_key, class T_value>
elemOfRedBlackTree<T_key, T_value>::elemOfRedBlackTree(std::weak_ptr<elemOfRedBlackTree> parent) {
    data_ = nullptr;

    parent_ = parent;

    color_ = COLOR::BLACK;
    nextLeft_ = nullptr;
    nextRight_ = nullptr;
}

template<class T_key, class T_value>
const T_key &elemOfRedBlackTree<T_key, T_value>::getKey() const {
    if (!this) throw std::logic_error("getKey(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getKey(): Attempt to interact with nil");
    return data_->getFirst();
}

template<class T_key, class T_value>
T_key &elemOfRedBlackTree<T_key, T_value>::getKey() {
    if (!this) throw std::logic_error("getKey(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getKey(): Attempt to interact with nil");
    return data_->getFirst();
}

template<class T_key, class T_value>
const T_value &elemOfRedBlackTree<T_key, T_value>::getValue() const {
    if (!this) throw std::logic_error("getValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getValue(): Attempt to interact with nil");
    return data_->getSecond();
}

template<class T_key, class T_value>
T_value &elemOfRedBlackTree<T_key, T_value>::getValue() {
    if (!this) throw std::logic_error("getValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getValue(): Attempt to interact with nil");
    return data_->getSecond();
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setValue(const T_value &value) {
    if (!this) throw std::logic_error("setValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("setValue(): Attempt to interact with nil");
    data_->setSecond(value);
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setValue(T_value &&value) {
    if (!this) throw std::logic_error("setValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("setValue(): Attempt to interact with nil");
    data_->setSecond(std::move(value));
}

template<class T_key, class T_value>
const COLOR &elemOfRedBlackTree<T_key, T_value>::getColor() const {
    if (!this) throw std::logic_error("getColor(): Attempt to interact with a null pointer");
    return color_;
}

template<class T_key, class T_value>
COLOR &elemOfRedBlackTree<T_key, T_value>::getColor() {
    if (!this) throw std::logic_error("getColor(): Attempt to interact with a null pointer");
    return color_;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setColor(const COLOR &color) {
    if (!this) throw std::logic_error("setColor(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("setColor(): Attempt to interact with nil");
    color_ = color;
}






template<class T_key, class T_value>
std::weak_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getParent() const {
    if (!this) throw std::logic_error("getParent(): Attempt to interact with a null pointer");
    return parent_;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setParent(std::weak_ptr<elemOfRedBlackTree> parent) {
    if (!this) throw std::logic_error("setParent(): Attempt to interact with a null pointer");
    parent_ = parent;
}

template<class T_key, class T_value>
std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getNextLeft() const {
    if (!this) throw std::logic_error("getNextLeft(): Attempt to interact with a null pointer");
    return nextLeft_;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setNextLeft(std::shared_ptr<elemOfRedBlackTree> nextLeft) {
    if (!this) throw std::logic_error("setNextLeft(): Attempt to interact with a null pointer");
    nextLeft_ = nextLeft;
}

template<class T_key, class T_value>
std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getNextRight() const {
    if (!this) throw std::logic_error("getNextRight(): Attempt to interact with a null pointer");
    return nextRight_;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setNextRight(std::shared_ptr<elemOfRedBlackTree> nextRight) {
    if (!this) throw std::logic_error("setNextRight(): Attempt to interact with a null pointer");
    nextRight_ = nextRight;
}

template<class T_key, class T_value>
bool elemOfRedBlackTree<T_key, T_value>::isNil() const {
    return data_ == nullptr;
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP