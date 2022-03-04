#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H

#include "elemOfRedBlackTree.h"


template<class T_key, class T_value>
class redBlackTree{
private:
    std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> head;
public:
    redBlackTree(T_key key, T_value value);
    redBlackTree(std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> head = nullptr);

    ~redBlackTree() = default;

};


#include "../../src/redBlackTree/redBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
