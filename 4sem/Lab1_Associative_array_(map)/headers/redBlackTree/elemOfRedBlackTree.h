#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H

#include <memory>

template<class T_key, class T_value>
class elemOfRedBlackTree{
private:

    class dataPair{
    public:
        T_key key;
        T_value value;
        bool color;              // false = black, true = red
        dataPair(T_key key = 0, T_value value = 0, bool color = true) : key(key), value(value), color(color) {}
        ~dataPair() = default;
    };

    std::unique_ptr<dataPair> data;
    std::unique_ptr<elemOfRedBlackTree> parent;
    std::unique_ptr<elemOfRedBlackTree> nextLeft;
    std::unique_ptr<elemOfRedBlackTree> nextRight;
public:
    elemOfRedBlackTree(T_key key, T_value value, bool color = true,   // default constructor
                       std::unique_ptr<elemOfRedBlackTree> parent = nullptr,
                       std::unique_ptr<elemOfRedBlackTree> nextLeft = nullptr,
                       std::unique_ptr<elemOfRedBlackTree> nextRight = nullptr);
    elemOfRedBlackTree(std::unique_ptr<elemOfRedBlackTree> parent = nullptr);   //constructor for nils
    ~elemOfRedBlackTree() = default;

    T_key getKey() const;
    void setKey(T_key key);

    T_value getValue() const;
    void setValue(T_value value);

    bool getColor() const;
    void setColor(bool color);

    std::unique_ptr<elemOfRedBlackTree> getParent() const;
    void setParent(std::unique_ptr<elemOfRedBlackTree> parent);

    std::unique_ptr<elemOfRedBlackTree> getNextLeft() const;
    void setNextLeft(std::unique_ptr<elemOfRedBlackTree> nextLeft);

    std::unique_ptr<elemOfRedBlackTree> getNextRight() const;
    void setNextRight(std::unique_ptr<elemOfRedBlackTree> nextRight);

};

#include "../../src/redBlackTree/elemOfRedBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ELEMOFREDBLACKTREE_H