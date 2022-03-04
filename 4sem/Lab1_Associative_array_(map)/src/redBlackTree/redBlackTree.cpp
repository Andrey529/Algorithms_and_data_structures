#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP

#include "../../headers/redBlackTree/redBlackTree.h"

template<class T_key, class T_value>
redBlackTree<T_key, T_value>::redBlackTree(std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> head) {
    if (head->getColor() == COLOR::RED) throw std::invalid_argument("Color of the tree root must be black");
    else{
        if (head) this->head = std::move(head);
        else this->head = nullptr;
    }
}

template<class T_key, class T_value>
redBlackTree<T_key, T_value>::redBlackTree(T_key key, T_value value) { // root color always black
    try{
        this->head = std::make_unique<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);
    }
    catch (const std::bad_alloc &e) {
        std::cout << e.what();
    }
}

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
