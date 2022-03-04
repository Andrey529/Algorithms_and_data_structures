#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP

#include "../../headers/redBlackTree/elemOfRedBlackTree.h"

template<class T_key, class T_value>
elemOfRedBlackTree<T_key, T_value>::elemOfRedBlackTree(T_key key, T_value value, COLOR color,
                                                       std::unique_ptr<elemOfRedBlackTree> parent,
                                                       std::unique_ptr<elemOfRedBlackTree> nextLeft,
                                                       std::unique_ptr<elemOfRedBlackTree> nextRight) {
    try {
        this->data = std::make_unique<dataPair>(key, value, color);
    }
    catch (const std::bad_alloc &e) {
        std::cout << e.what();
    }
    this->parent = std::move(parent);
    this->nextLeft = std::move(nextLeft);
    this->nextRight = std::move(nextRight);
}

template<class T_key, class T_value>
elemOfRedBlackTree<T_key, T_value>::elemOfRedBlackTree(std::unique_ptr<elemOfRedBlackTree> parent) {
    this->data = nullptr;

    if (parent) this->parent = std::move(parent);
    else this->parent = nullptr;

    this->nextLeft = nullptr;
    this->nextRight = nullptr;
}

template<class T_key, class T_value>
T_key elemOfRedBlackTree<T_key, T_value>::getKey() const{
    return this->data->key;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setKey(T_key key) {
    this->data->key = key;
}

template<class T_key, class T_value>
T_value elemOfRedBlackTree<T_key, T_value>::getValue() const{
    return this->data->value;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setValue(T_value value) {
    this->data->value = value;
}

template<class T_key, class T_value>
COLOR elemOfRedBlackTree<T_key, T_value>::getColor() const{
    return this->data->color;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setColor(COLOR color) {
    this->data->color = color;
}

template<class T_key, class T_value>
std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getParent() const {
    return this->parent;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setParent(std::unique_ptr<elemOfRedBlackTree> parent) {
    this->parent = std::move(parent);
}

template<class T_key, class T_value>
std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getNextLeft() const {
    return this->nextLeft;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setNextLeft(std::unique_ptr<elemOfRedBlackTree> nextLeft) {
    this->nextLeft = std::move(nextLeft);
}

template<class T_key, class T_value>
std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> elemOfRedBlackTree<T_key, T_value>::getNextRight() const {
    return this->nextRight;
}

template<class T_key, class T_value>
void elemOfRedBlackTree<T_key, T_value>::setNextRight(std::unique_ptr<elemOfRedBlackTree> nextRight) {
    this->nextRight = std::move(nextRight);
}



#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_CPP