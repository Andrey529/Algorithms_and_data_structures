#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H

#include <memory>
#include <iostream>
#include "../dataPair/dataPair.h"

enum class COLOR{
    BLACK,
    RED,
};

template<class T_key, class T_value>
class elemOfRedBlackTree{
private:
    COLOR color;
    std::unique_ptr<dataPair<T_key, T_value>> data;
    std::shared_ptr<elemOfRedBlackTree> parent;
    std::shared_ptr<elemOfRedBlackTree> nextLeft;
    std::shared_ptr<elemOfRedBlackTree> nextRight;
public:

    elemOfRedBlackTree(const T_key &key, const T_value &value, const COLOR &color,   // default constructor
                       std::shared_ptr<elemOfRedBlackTree> parent = nullptr,
                       std::shared_ptr<elemOfRedBlackTree> nextLeft = nullptr,
                       std::shared_ptr<elemOfRedBlackTree> nextRight = nullptr);

    elemOfRedBlackTree(std::shared_ptr<elemOfRedBlackTree> parent = nullptr);   //constructor for nils
    ~elemOfRedBlackTree() = default;

    T_key getKey() const;

    T_value getValue() const;
    void setValue(const T_value &value);

    COLOR getColor() const;
    void setColor(const COLOR &color);

    std::shared_ptr<elemOfRedBlackTree> getParent() const;
    void setParent(std::shared_ptr<elemOfRedBlackTree> parent);

    std::shared_ptr<elemOfRedBlackTree> getNextLeft() const;
    void setNextLeft(std::shared_ptr<elemOfRedBlackTree> nextLeft);

    std::shared_ptr<elemOfRedBlackTree> getNextRight() const;
    void setNextRight(std::shared_ptr<elemOfRedBlackTree> nextRight);

    bool isNil() const;
};

#include "../../src/redBlackTree/elemOfRedBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H