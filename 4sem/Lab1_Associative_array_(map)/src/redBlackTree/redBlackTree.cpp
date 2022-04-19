#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP

#include "../../headers/redBlackTree/redBlackTree.h"

template<class T_key, class T_value, class comparator>
redBlackTree<T_key, T_value, comparator>::redBlackTree(const T_key &key,
                                                       const T_value &value) { // root color always black
    try {
        head_ = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);

        auto nilLeft = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(head_);
        auto nilRight = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(head_);

        head_->setNextLeft(std::move(nilLeft));
        head_->setNextRight(std::move(nilRight));
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
    return head_ == nullptr;
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::insert(const T_key &key, const T_value &value) {

    if (isEmpty()) {
        try {
            head_ = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);
            auto nilLeft = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(head_);
            auto nilRight = std::make_shared<elemOfRedBlackTree<T_key, T_value>>(head_);
            head_->setNextLeft(std::move(nilLeft));
            head_->setNextRight(std::move(nilRight));
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
        auto tempElem = head_;


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

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::clear() {
    head_ = nullptr;
}

template<class T_key, class T_value, class comparator>
std::unique_ptr<iterator<std::shared_ptr<elemOfRedBlackTree<T_key, T_value>>>>
redBlackTree<T_key, T_value, comparator>::createDftIterator() {
    if (head_ == nullptr)
        throw std::logic_error("An iterator cannot be created because there is no element in the tree.");
    return std::make_unique<RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>>(head_);

//    return new binaryTreeSearchDepthFirstTraverseIterator(this->head_);

}

template<class T_key, class T_value, class comparator>
List<T_key> redBlackTree<T_key, T_value, comparator>::getKeys() {

    auto it = createDftIterator();
    List<T_key> list;
    while (it->hasNext()) {
        list.pushBack(it->next()->getKey());
    }
    return list;
}

template<class T_key, class T_value, class comparator>
List<T_value> redBlackTree<T_key, T_value, comparator>::getValues() {
    auto it = createDftIterator();
    List<T_key> list;
    while (it->hasNext()) {
        list.pushBack(it->next()->getValue());
    }
    return list;
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::print() {
    auto it = createDftIterator();
    while (it->hasNext()) {
        auto elem = it->next();
        std::cout << "{" << elem->getKey() << ": " << elem->getValue() << "}\n";
    }
}

template<class T_key, class T_value, class comparator>
bool redBlackTree<T_key, T_value, comparator>::find(const T_key &key) const {
    if (isEmpty())
        throw std::logic_error("Cannot find element with this key because there is no element in the tree.");

    auto elem = head_;
    comparator cmp = comparator{};

    while (true) {
        if (cmp(elem->getKey(), key) && !(elem->getNextRight()->isNil())) {  // elem->getKey() < key and elem->right not nill
            elem = elem->getNextRight();
            continue;
        } else if (cmp(elem->getKey(), key) && (elem->getNextRight()->isNil())) { // elem->getKey() < key and elem->right = nill
            return false;
        } else if (cmp(key, elem->getKey()) && !(elem->getNextLeft()->isNil())) { // elem->getKey() > key and elem->left not nill
            elem = elem->getNextLeft();
            continue;
        } else if (cmp(key, elem->getKey()) && (elem->getNextLeft()->isNil())) { // elem->getKey() > key and elem->left = nill
            return false;
        }
        else if (!cmp(key, elem->getKey()) && !cmp(elem->getKey(), key)) {
            return true;
        }
    }
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
