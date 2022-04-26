#ifndef LAB2_HUFFMON_CODING_ELEMOFREDBLACKTREE_CPP
#define LAB2_HUFFMON_CODING_ELEMOFREDBLACKTREE_CPP

#include "../../headers/RedBlackTree/ElemOfRedBlackTree.h"

template<class T_key, class T_value>
ElemOfRedBlackTree<T_key, T_value>::ElemOfRedBlackTree(const T_key &key, const T_value &value, const COLOR &color,
                                                       std::weak_ptr<ElemOfRedBlackTree> parent,
                                                       std::shared_ptr<ElemOfRedBlackTree> nextLeft,
                                                       std::shared_ptr<ElemOfRedBlackTree> nextRight) {
    try {
        data_ = std::make_unique<DataPair<T_key, T_value>>(key, value);
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
ElemOfRedBlackTree<T_key, T_value>::ElemOfRedBlackTree(std::weak_ptr<ElemOfRedBlackTree> parent) {
    data_ = nullptr;

    parent_ = parent;

    color_ = COLOR::BLACK;
    nextLeft_ = nullptr;
    nextRight_ = nullptr;
}

template<class T_key, class T_value>
const T_key &ElemOfRedBlackTree<T_key, T_value>::getKey() const {
    if (!this) throw std::logic_error("getKey(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getKey(): Attempt to interact with nil");
    return data_->getFirst();
}

template<class T_key, class T_value>
T_key &ElemOfRedBlackTree<T_key, T_value>::getKey() {
    if (!this) throw std::logic_error("getKey(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getKey(): Attempt to interact with nil");
    return data_->getFirst();
}

template<class T_key, class T_value>
const T_value &ElemOfRedBlackTree<T_key, T_value>::getValue() const {
    if (!this) throw std::logic_error("getValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getValue(): Attempt to interact with nil");
    return data_->getSecond();
}

template<class T_key, class T_value>
T_value &ElemOfRedBlackTree<T_key, T_value>::getValue() {
    if (!this) throw std::logic_error("getValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("getValue(): Attempt to interact with nil");
    return data_->getSecond();
}

template<class T_key, class T_value>
void ElemOfRedBlackTree<T_key, T_value>::setValue(const T_value &value) {
    if (!this) throw std::logic_error("setValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("setValue(): Attempt to interact with nil");
    data_->setSecond(value);
}

template<class T_key, class T_value>
void ElemOfRedBlackTree<T_key, T_value>::setValue(T_value &&value) {
    if (!this) throw std::logic_error("setValue(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("setValue(): Attempt to interact with nil");
    data_->setSecond(std::move(value));
}

template<class T_key, class T_value>
const COLOR &ElemOfRedBlackTree<T_key, T_value>::getColor() const {
    if (!this) throw std::logic_error("getColor(): Attempt to interact with a null pointer");
    return color_;
}

template<class T_key, class T_value>
COLOR &ElemOfRedBlackTree<T_key, T_value>::getColor() {
    if (!this) throw std::logic_error("getColor(): Attempt to interact with a null pointer");
    return color_;
}

template<class T_key, class T_value>
void ElemOfRedBlackTree<T_key, T_value>::setColor(const COLOR &color) {
    if (!this) throw std::logic_error("setColor(): Attempt to interact with a null pointer");
    if (!data_) throw std::logic_error("setColor(): Attempt to interact with nil");
    color_ = color;
}






template<class T_key, class T_value>
std::weak_ptr<ElemOfRedBlackTree<T_key, T_value>> ElemOfRedBlackTree<T_key, T_value>::getParent() const {
    if (!this) throw std::logic_error("getParent(): Attempt to interact with a null pointer");
    return parent_;
}

template<class T_key, class T_value>
void ElemOfRedBlackTree<T_key, T_value>::setParent(std::weak_ptr<ElemOfRedBlackTree> parent) {
    if (!this) throw std::logic_error("setParent(): Attempt to interact with a null pointer");
    parent_ = parent;
}

template<class T_key, class T_value>
std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> ElemOfRedBlackTree<T_key, T_value>::getNextLeft() const {
    if (!this) throw std::logic_error("getNextLeft(): Attempt to interact with a null pointer");
    return nextLeft_;
}

template<class T_key, class T_value>
void ElemOfRedBlackTree<T_key, T_value>::setNextLeft(std::shared_ptr<ElemOfRedBlackTree> nextLeft) {
    if (!this) throw std::logic_error("setNextLeft(): Attempt to interact with a null pointer");
    nextLeft_ = nextLeft;
}

template<class T_key, class T_value>
std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> ElemOfRedBlackTree<T_key, T_value>::getNextRight() const {
    if (!this) throw std::logic_error("getNextRight(): Attempt to interact with a null pointer");
    return nextRight_;
}

template<class T_key, class T_value>
void ElemOfRedBlackTree<T_key, T_value>::setNextRight(std::shared_ptr<ElemOfRedBlackTree> nextRight) {
    if (!this) throw std::logic_error("setNextRight(): Attempt to interact with a null pointer");
    nextRight_ = nextRight;
}

template<class T_key, class T_value>
bool ElemOfRedBlackTree<T_key, T_value>::isNil() const {
    return data_ == nullptr;
}

#endif //LAB2_HUFFMON_CODING_ELEMOFREDBLACKTREE_CPP
