#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP

#include "../../headers/redBlackTree/redBlackTree.h"

template<class T_key, class T_value, class comparator>
redBlackTree<T_key, T_value, comparator>::redBlackTree(const T_key &key,
                                                       const T_value &value) { // root color always black
    try {
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
bool redBlackTree<T_key, T_value, comparator>::isEmpty() const {
    return this->head == nullptr;
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::insert(const T_key &key, const T_value &value) {

    if (isEmpty()) {
        try {
            this->head = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);
            auto nilLeft = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(this->head);
            auto nilRight = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(this->head);
            this->head->setNextLeft(std::move(nilLeft));
            this->head->setNextRight(std::move(nilRight));
        }
        catch (const std::bad_alloc &error) {
            std::cout << error.what();
            return;
        }
    } else {
        comparator cmp = comparator{};
        std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> newElem;
        try {
            newElem = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::RED);
        }
        catch (const std::bad_alloc &error) {
            std::cout << error.what();
            return;
        }
        auto tempElem = this->head;


        // insert new element in red-black tree

        try {

            // !(tempElem->getNextLeft()->isNil()) && !(tempElem->getNextRight()->isNil())
            // without when only 1 elem in tree
            while (true) {
                if (cmp(tempElem->getKey(), key)) { // if (key > tempElem->getKey())
                    if (tempElem->getNextRight()->isNil()) {
                        auto nilRight = tempElem->getNextRight();
                        nilRight->setParent(newElem);
                        auto nilLeft = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(newElem);

                        tempElem->setNextRight(newElem);

                        newElem->setParent(tempElem);
                        newElem->setNextLeft(std::move(nilLeft));
                        newElem->setNextRight(std::move(nilRight));

                        break;
                    } else {
                        tempElem = tempElem->getNextRight();
                    }
                } else { // key <= tempElem->getKey()
                    if (tempElem->getNextLeft()->isNil()) {
                        auto nilLeft = tempElem->getNextLeft();
                        nilLeft->setParent(newElem);
                        auto nilRight = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(newElem);

                        tempElem->setNextLeft(newElem);

                        newElem->setParent(tempElem);
                        newElem->setNextLeft(std::move(nilLeft));
                        newElem->setNextRight(std::move(nilRight));

                        break;
                    } else {
                        tempElem = tempElem->getNextLeft();
                    }
                }
            }
        }
        catch (const std::bad_alloc &error) {
            std::cout << error.what();
            return;
        }
        catch (const std::logic_error &error) {
            std::cout << error.what();
            return;
        }


        // function repair red-black tree

    }
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
