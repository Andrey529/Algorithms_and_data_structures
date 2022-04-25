#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H

#include <memory>
#include <iostream>
#include "../DataPair/DataPair.h"

enum class COLOR {
    BLACK,
    RED,
};

template<class T_key, class T_value>
class ElemOfRedBlackTree{  //  : public std::enable_shared_from_this<ElemOfRedBlackTree<T_key, T_value>>
private:
    COLOR color_;
    std::unique_ptr<DataPair<T_key, T_value>> data_;
    std::weak_ptr<ElemOfRedBlackTree> parent_;
    std::shared_ptr<ElemOfRedBlackTree> nextLeft_;
    std::shared_ptr<ElemOfRedBlackTree> nextRight_;
public:

    ElemOfRedBlackTree(const T_key &key, const T_value &value, const COLOR &color,   // default constructor
                       std::weak_ptr<ElemOfRedBlackTree> parent = {},
                       std::shared_ptr<ElemOfRedBlackTree> nextLeft = nullptr,
                       std::shared_ptr<ElemOfRedBlackTree> nextRight = nullptr);

    explicit ElemOfRedBlackTree(std::weak_ptr<ElemOfRedBlackTree> parent = {});   //constructor for nils
    ~ElemOfRedBlackTree() = default;

    const T_key &getKey() const;
    T_key &getKey();

    const T_value &getValue() const;
    T_value &getValue();
    void setValue(const T_value &value);
    void setValue(T_value &&value);

    const COLOR &getColor() const;
    COLOR &getColor();
    void setColor(const COLOR &color);

    std::weak_ptr<ElemOfRedBlackTree> getParent() const;
    void setParent(std::weak_ptr<ElemOfRedBlackTree> parent);

    std::shared_ptr<ElemOfRedBlackTree> getNextLeft() const;
    void setNextLeft(std::shared_ptr<ElemOfRedBlackTree> nextLeft);

    std::shared_ptr<ElemOfRedBlackTree> getNextRight() const;
    void setNextRight(std::shared_ptr<ElemOfRedBlackTree> nextRight);

    bool isNil() const;
};

#include "../../src/RedBlackTree/ElemOfRedBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H