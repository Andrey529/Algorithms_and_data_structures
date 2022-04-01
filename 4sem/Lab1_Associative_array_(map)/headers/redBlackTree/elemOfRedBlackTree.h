#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H

#include <memory>
#include <iostream>
#include "../dataPair/dataPair.h"

enum class COLOR {
    BLACK,
    RED,
};

template<class T_key, class T_value>
class elemOfRedBlackTree : public std::enable_shared_from_this<elemOfRedBlackTree<T_key, T_value>> {
private:
    COLOR color_;
    std::unique_ptr<dataPair<T_key, T_value>> data_;
    std::weak_ptr<elemOfRedBlackTree> parent_;
    std::shared_ptr<elemOfRedBlackTree> nextLeft_;
    std::shared_ptr<elemOfRedBlackTree> nextRight_;
public:

    elemOfRedBlackTree(const T_key &key, const T_value &value, const COLOR &color,   // default constructor
                       std::weak_ptr<elemOfRedBlackTree> parent = {},
                       std::shared_ptr<elemOfRedBlackTree> nextLeft = nullptr,
                       std::shared_ptr<elemOfRedBlackTree> nextRight = nullptr);

    explicit elemOfRedBlackTree(std::weak_ptr<elemOfRedBlackTree> parent = {});   //constructor for nils
    ~elemOfRedBlackTree() = default;

    const T_key &getKey() const;
    T_key &getKey();

    const T_value &getValue() const;
    T_value &getValue();
    void setValue(const T_value &value);
    void setValue(T_value &&value);

    const COLOR &getColor() const;
    COLOR &getColor();
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