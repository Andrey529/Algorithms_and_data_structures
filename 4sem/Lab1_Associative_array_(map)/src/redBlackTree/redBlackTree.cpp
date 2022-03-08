#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP

#include "../../headers/redBlackTree/redBlackTree.h"

template<class T_key, class T_value, class comparator>
redBlackTree<T_key, T_value, comparator>::redBlackTree(const T_key &key, const T_value &value) { // root color always black
    try{
        this->head = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);
        auto nilLeft = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(this->head);
        auto nilRight = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(this->head);
        this->head->setNextLeft(std::move(nilLeft));
        this->head->setNextRight(std::move(nilRight));
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
    catch (const std::logic_error &error) {
        std::cout << error.what();
    }
}

template<class T_key, class T_value, class comparator>
bool redBlackTree<T_key, T_value, comparator>::isEmpty() const{
    return this->head == nullptr;
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::insert(const T_key &key, const T_value &value) {

    if (isEmpty()) {
        try {
            this->head = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);
        }
        catch (const std::bad_alloc &error) {
            std::cout << error.what();
        }
    }
    else{
//        comparator cmp = comparator{};
//        if (cmp(this->head->getKey(), key)){ // if (key > this->head->getKey())
//
//        }
//        auto newElem = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::RED);
//        while ()

    }





//    else {
//        elemOfBinaryTreeSearch<T> *tempElem = this->head;
//        while (true) {
//            if ( (data <= tempElem->getData()) && (tempElem->getNextLeft() == nullptr) ){
//                auto *newElem = new elemOfBinaryTreeSearch<T>(data,tempElem);
//                tempElem->setNextLeft(newElem);
//                return;
//            }
//            else if ( (data <= tempElem->getData()) && (tempElem->getNextLeft() != nullptr) ){
//                tempElem = tempElem->getNextLeft();
//                continue;
//            }
//            else if ( (data > tempElem->getData()) && (tempElem->getNextRight() == nullptr) ){
//                auto *newElem = new elemOfBinaryTreeSearch<T>(data,tempElem);
//                tempElem->setNextRight(newElem);
//                return;
//            }
//            else if ( (data > tempElem->getData()) && (tempElem->getNextRight() != nullptr) ){
//                tempElem = tempElem->getNextRight();
//                continue;
//            }
//        }
//    }
}




#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
