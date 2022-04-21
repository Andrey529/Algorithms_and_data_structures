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
        // check if the element with key already in the tree
        if (contains(key)) {
            throw std::invalid_argument("The element with the given key is already in the tree");
        }

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
        repairTreeAfterInsert(newElem);
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
std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> redBlackTree<T_key, T_value, comparator>::find(const T_key &key) const {
    if (isEmpty())
        throw std::logic_error("Cannot find element with this key because there is no element in the tree.");

    auto elem = head_;
    comparator cmp = comparator{};

    while (true) {
        if (cmp(elem->getKey(), key) &&
            !(elem->getNextRight()->isNil())) {  // elem->getKey() < key and elem->right not nill
            elem = elem->getNextRight();
            continue;
        } else if (cmp(elem->getKey(), key) &&
                   (elem->getNextRight()->isNil())) { // elem->getKey() < key and elem->right = nill
            return std::make_shared<elemOfRedBlackTree<T_key, T_value>>();
        } else if (cmp(key, elem->getKey()) &&
                   !(elem->getNextLeft()->isNil())) { // elem->getKey() > key and elem->left not nill
            elem = elem->getNextLeft();
            continue;
        } else if (cmp(key, elem->getKey()) &&
                   (elem->getNextLeft()->isNil())) { // elem->getKey() > key and elem->left = nill
            return std::make_shared<elemOfRedBlackTree<T_key, T_value>>();
        } else if (!cmp(key, elem->getKey()) && !cmp(elem->getKey(), key)) {
            return elem;
        }
    }
}

template<class T_key, class T_value, class comparator>
bool redBlackTree<T_key, T_value, comparator>::contains(const T_key &key) {
    return !(find(key)->isNil());
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::leftRotate(std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> elem) {
    auto x = elem;
    auto y = x->getNextRight();

    x->setNextRight(y->getNextLeft());
    x->getNextRight()->setParent(x);
    if (!(y->getNextLeft()->isNil())) {
        y->getNextLeft()->setParent(x);
    }
    y->setParent(x->getParent());

    if (!(x->getParent().lock())) { // x->getParent() == nullptr
        head_ = y;
    } else if (x->getParent().lock()->getNextLeft() == x) {
        x->getParent().lock()->setNextLeft(y);
        y->setParent(x->getParent().lock());
    } else {
        x->getParent().lock()->setNextRight(y);
        y->setParent(x->getParent().lock());
    }

    y->setNextLeft(x);
    x->setParent(y);
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::rightRotate(std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> elem) {
    auto y = elem;
    auto x = y->getNextLeft();

    y->setNextLeft(x->getNextRight());
    y->getNextLeft()->setParent(y);
    if (!(x->getNextRight()->isNil())) {
        x->getNextRight()->setParent(y);
    }
    x->setParent(y->getParent());

    if (!(y->getParent().lock())) {
        head_ = x;
    } else if (y->getParent().lock()->getNextRight() == y) {
        y->getParent().lock()->setNextRight(x);
        x->setParent(y->getParent().lock());
    } else {
        y->getParent().lock()->setNextLeft(x);
        x->setParent(y->getParent().lock());
    }

    x->setNextRight(y);
    y->setParent(x);
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::repairTreeAfterInsert(
        std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> newElem) {

    auto parent = newElem->getParent().lock();
    auto grandParent = parent->getParent().lock();
    while (parent->getColor() == COLOR::RED) {
        if (parent == grandParent->getNextLeft()) {
            if (grandParent->getNextRight()->getColor() == COLOR::RED) {
                grandParent->getNextLeft()->setColor(COLOR::BLACK);
                grandParent->getNextRight()->setColor(COLOR::BLACK);
                grandParent->setColor(COLOR::RED);

                newElem = grandParent;
            } else {
                if (newElem == parent->getNextRight()) {
                    newElem = parent;
                    leftRotate(newElem);
                    parent = newElem->getParent().lock();
                    grandParent = parent->getParent().lock();
                }

                parent->setColor(COLOR::BLACK);
                grandParent->setColor(COLOR::RED);
                rightRotate(grandParent);
            }
        }
        else {/* if (parent == grandParent->getNextRight()) {*/
            if (grandParent->getNextLeft()->getColor() == COLOR::RED) {
                grandParent->getNextLeft()->setColor(COLOR::BLACK);
                grandParent->getNextRight()->setColor(COLOR::BLACK);
                grandParent->setColor(COLOR::RED);

                newElem = grandParent;
            } else {
                if (newElem == parent->getNextLeft()) {
                    newElem = parent;
                    rightRotate(newElem);
                    parent = newElem->getParent().lock();
                    grandParent = parent->getParent().lock();
                }

                parent->setColor(COLOR::BLACK);
                grandParent->setColor(COLOR::RED);
                leftRotate(grandParent);
            }
        }

        if (newElem == head_)
            break;
    }
    head_->setColor(COLOR::BLACK);
}

template<class T_key, class T_value, class comparator>
void redBlackTree<T_key, T_value, comparator>::remove(const T_key &key) {
//    auto originalColor =
}




#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_CPP
