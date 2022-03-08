#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP

#include "../../headers/redBlackTree/elemOfRedBlackTree.h"

template<class T_key, class T_value>
elemOfRedBlackTree<T_key, T_value>::elemOfRedBlackTree(const T_key &key, const T_value &value, const COLOR &color,
                                                       std::shared_ptr<elemOfRedBlackTree> parent,
                                                       std::shared_ptr<elemOfRedBlackTree> nextLeft,
                                                       std::shared_ptr<elemOfRedBlackTree> nextRight) {
    try {
        this->data = std::make_unique<dataPair<T_key, T_value>>(key, value);
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
    this->color = color;
    this->parent = std::move(parent);
    this->nextLeft = std::move(nextLeft);
    this->nextRight = std::move(nextRight);
}

template<class T_key, class T_value>
elemOfRedBlackTree<T_key, T_value>::elemOfRedBlackTree(std::shared_ptr<elemOfRedBlackTree> parent) {
    this->data = nullptr;

    if (parent) this->parent = std::move(parent);
    else this->parent = nullptr;

    this->color = COLOR::BLACK;
    this->nextLeft = nullptr;
    this->nextRight = nullptr;
}

template<class T_key, class T_value>
T_key elemOfRedBlackTree<T_key, T_value>::getKey() const{
    if (!this) throw std::logic_error("getKey(): Attempt to interact with a null pointer");
    if (!(this->data)) throw std::logic_error("getKey(): Attempt to interact with nil");
    return this->data->key;
}

template<class T_key, class T_value>
T_value elemOfRedBlackTree<T_key, T_value>::getValue() const{
    if (!this) throw std::logic_error("getValue(): Attempt to interact with a null pointer");
    if (!(this->data)) throw std::logic_error("getValue(): Attempt to interact with nil");
    return this->data->value;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setValue(const T_value &value) {
    if (!this) throw std::logic_error("setValue(): Attempt to interact with a null pointer");
    if (!(this->data)) throw std::logic_error("setValue(): Attempt to interact with nil");
    this->data->value = value;
}

template<class T_key, class T_value>
COLOR elemOfRedBlackTree<T_key, T_value>::getColor() const{
    if (!this) throw std::logic_error("getColor(): Attempt to interact with a null pointer");
    return this->data->color;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setColor(const COLOR &color) {
    if (!this) throw std::logic_error("setColor(): Attempt to interact with a null pointer");
    if (!(this->data)) throw std::logic_error("setColor(): Attempt to interact with nil");
    this->data->color = color;
}

template<class T_key, class T_value>
std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getParent() const{
    if (!this) throw std::logic_error("getParent(): Attempt to interact with a null pointer");
    return this->parent;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setParent(std::shared_ptr<elemOfRedBlackTree> parent) {
    if (!this) throw std::logic_error("setParent(): Attempt to interact with a null pointer");
    this->parent = parent;
}

template<class T_key, class T_value>
std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getNextLeft() const {
    if (!this) throw std::logic_error("getNextLeft(): Attempt to interact with a null pointer");
    return this->nextLeft;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setNextLeft(std::shared_ptr<elemOfRedBlackTree> nextLeft) {
    if (!this) throw std::logic_error("setNextLeft(): Attempt to interact with a null pointer");
    this->nextLeft = nextLeft;
}

template<class T_key, class T_value>
std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getNextRight() const {
    if (!this) throw std::logic_error("getNextRight(): Attempt to interact with a null pointer");
    return this->nextRight;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setNextRight(std::shared_ptr<elemOfRedBlackTree> nextRight) {
    if (!this) throw std::logic_error("setNextRight(): Attempt to interact with a null pointer");
    this->nextRight = nextRight;
}

template<class T_key, class T_value>
bool elemOfRedBlackTree<T_key, T_value>::isNil() const {
    return this->data == nullptr;
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP