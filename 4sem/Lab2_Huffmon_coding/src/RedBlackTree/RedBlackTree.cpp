#ifndef LAB2_HUFFMON_CODING_REDBLACKTREE_CPP
#define LAB2_HUFFMON_CODING_REDBLACKTREE_CPP

#include "../../headers/RedBlackTree/RedBlackTree.h"

template<class T_key, class T_value, class comparator>
RedBlackTree<T_key, T_value, comparator>::RedBlackTree(const T_key &key,
                                                       const T_value &value) { // root color always black
    try {
        head_ = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);

        auto nilLeft = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(head_);
        auto nilRight = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(head_);

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
RedBlackTree<T_key, T_value, comparator>::RedBlackTree(RedBlackTree<T_key, T_value> &other) {
    try {
        T_key key = other.head_->getKey();
        T_value value = other.head_->getValue();
        head_ = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);

        auto nilLeft = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(head_);
        auto nilRight = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(head_);

        head_->setNextLeft(std::move(nilLeft));
        head_->setNextRight(std::move(nilRight));

        auto firstHead = other.head_;
        auto it = other.createBftIterator();
        while (it->hasNext()) {
            auto elem = it->next();
            if (elem->getKey() == firstHead->getKey()) continue;
            auto elemKey = elem->getKey();
            auto elemValue = elem->getValue();
            this->insert(elemKey, elemValue);
        }

    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
    catch (const std::logic_error &error) {
        std::cout << error.what();
    }
}

template<class T_key, class T_value, class comparator>
bool RedBlackTree<T_key, T_value, comparator>::isEmpty() const {
    return head_ == nullptr;
}

template<class T_key, class T_value, class comparator>
void RedBlackTree<T_key, T_value, comparator>::insert(const T_key &key, const T_value &value) {

    if (isEmpty()) {
        try {
            head_ = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::BLACK);
            auto nilLeft = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(head_);
            auto nilRight = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(head_);
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
        std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> newElem;
        try {
            newElem = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(key, value, COLOR::RED);
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
                        auto nilLeft = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(newElem);

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
                        auto nilRight = std::make_shared<ElemOfRedBlackTree<T_key, T_value>>(newElem);

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
void RedBlackTree<T_key, T_value, comparator>::clear() {
    head_ = nullptr;
}

template<class T_key, class T_value, class comparator>
std::unique_ptr<Iterator<std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>>>
RedBlackTree<T_key, T_value, comparator>::createBftIterator() {
    if (head_ == nullptr)
        throw std::logic_error("An Iterator cannot be created because there is no element in the tree.");
    return std::make_unique<RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>>(head_);
}

template<class T_key, class T_value, class comparator>
List<T_key> RedBlackTree<T_key, T_value, comparator>::getKeys() {

    auto it = createBftIterator();
    List<T_key> list;
    while (it->hasNext()) {
        list.pushBack(it->next()->getKey());
    }
    return list;
}

template<class T_key, class T_value, class comparator>
List<T_value> RedBlackTree<T_key, T_value, comparator>::getValues() {
    auto it = createBftIterator();
    List<T_key> list;
    while (it->hasNext()) {
        list.pushBack(it->next()->getValue());
    }
    return list;
}

template<class T_key, class T_value, class comparator>
void RedBlackTree<T_key, T_value, comparator>::print() {
    auto it = createBftIterator();
    while (it->hasNext()) {
        auto elem = it->next();
        std::cout << "{" << elem->getKey() << ": " << elem->getValue() << "}\n";
    }
}

template<class T_key, class T_value, class comparator>
std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>
RedBlackTree<T_key, T_value, comparator>::find(const T_key &key) const {
    if (isEmpty())
        return std::make_shared<ElemOfRedBlackTree<T_key, T_value>>();

    auto elem = head_;
    comparator cmp = comparator{};

    while (true) {
        if (cmp(elem->getKey(), key) &&
            !(elem->getNextRight()->isNil())) {  // elem->getKey() < key and elem->right not nill
            elem = elem->getNextRight();
            continue;
        } else if (cmp(elem->getKey(), key) &&
                   (elem->getNextRight()->isNil())) { // elem->getKey() < key and elem->right = nill
            return std::make_shared<ElemOfRedBlackTree<T_key, T_value>>();
        } else if (cmp(key, elem->getKey()) &&
                   !(elem->getNextLeft()->isNil())) { // elem->getKey() > key and elem->left not nill
            elem = elem->getNextLeft();
            continue;
        } else if (cmp(key, elem->getKey()) &&
                   (elem->getNextLeft()->isNil())) { // elem->getKey() > key and elem->left = nill
            return std::make_shared<ElemOfRedBlackTree<T_key, T_value>>();
        } else if (!cmp(key, elem->getKey()) && !cmp(elem->getKey(), key)) {
            return elem;
        }
    }
}

template<class T_key, class T_value, class comparator>
bool RedBlackTree<T_key, T_value, comparator>::contains(const T_key &key) {
    return !(find(key)->isNil());
}

template<class T_key, class T_value, class comparator>
void RedBlackTree<T_key, T_value, comparator>::leftRotate(std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> elem) {
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
void RedBlackTree<T_key, T_value, comparator>::rightRotate(std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> elem) {
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
void RedBlackTree<T_key, T_value, comparator>::repairTreeAfterInsert(
        std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> newElem) {

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
        } else {/* if (parent == grandParent->getNextRight()) {*/
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
void RedBlackTree<T_key, T_value, comparator>::remove(const T_key &key) {
    std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> elemToBeDeleted;
    try {
        elemToBeDeleted = find(key);
    }
    catch (const std::exception &error) {
        std::cout << error.what();
        return;
    }

    if (!(elemToBeDeleted->isNil())) {
        auto originalColor = elemToBeDeleted->getColor();

        std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> x;

        if (elemToBeDeleted->getNextLeft()->isNil()) {
            x = elemToBeDeleted->getNextRight();

            auto parentOfDeletedElem = elemToBeDeleted->getParent().lock();
            if (parentOfDeletedElem->getNextLeft() == elemToBeDeleted) {
                parentOfDeletedElem->setNextLeft(x);
                x->setParent(parentOfDeletedElem);
            } else /*parentOfDeletedElem->getNextRight() == elemToBeDeleted*/ {
                parentOfDeletedElem->setNextRight(x);
                x->setParent(parentOfDeletedElem);
            }
        } else if (elemToBeDeleted->getNextRight()->isNil()) {
            x = elemToBeDeleted->getNextLeft();

            auto parentOfDeletedElem = elemToBeDeleted->getParent().lock();
            if (parentOfDeletedElem->getNextLeft() == elemToBeDeleted) {
                parentOfDeletedElem->setNextLeft(x);
                x->setParent(parentOfDeletedElem);
            } else /*parentOfDeletedElem->getNextRight() == elemToBeDeleted*/ {
                parentOfDeletedElem->setNextRight(x);
                x->setParent(parentOfDeletedElem);
            }
        } else { // 5
            auto y = elemToBeDeleted->getNextRight();
            while (!(y->getNextLeft()->isNil())) {
                y = y->getNextLeft();
            }

            originalColor = y->getColor();
            x = y->getNextRight();

            if (y->getParent().lock() == elemToBeDeleted) { // ??
                x->setParent(y);
            } else {  // ??
                auto yParent = y->getParent().lock();
                auto yNextRight = y->getNextRight();

                if (yParent->getNextLeft() == y) {
                    yParent->setNextLeft(yNextRight);
                } else { /*yParent->getNextRight() == y*/
                    yParent->setNextRight(yNextRight);
                }
                yNextRight->setParent(yParent);

                // ?
                y->setNextRight(elemToBeDeleted->getNextRight());
                y->getNextRight()->setParent(y);
                // ?
            }


            // e
            auto parentOfDeletedElem = elemToBeDeleted->getParent().lock();
            if (parentOfDeletedElem->getNextLeft() == elemToBeDeleted) {
                parentOfDeletedElem->setNextLeft(y);
            } else { /*parentOfDeletedElem->getNextRight() == elemToBeDeleted*/
                parentOfDeletedElem->setNextRight(y);
            }
            y->setParent(parentOfDeletedElem);

            // ??
            y->setColor(originalColor);

            // ?
            y->setNextLeft(elemToBeDeleted->getNextLeft());
            y->getNextLeft()->setParent(y);

            y->setColor(elemToBeDeleted->getColor());
            // ?
        }

        if (originalColor == COLOR::BLACK) {
            repairTreeAfterRemove(x);
        }
    }

}

template<class T_key, class T_value, class comparator>
void RedBlackTree<T_key, T_value, comparator>::repairTreeAfterRemove(
        std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> elem) {

    std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> w;
    auto x = elem;

    auto xParent = x->getParent().lock();

    while (x != head_ && x->getColor() == COLOR::BLACK) {
        if (x == xParent->getNextLeft()) {

            w = xParent->getNextRight();
            if (w->getColor() == COLOR::RED) {
                w->setColor(COLOR::BLACK);
                xParent->setColor(COLOR::RED);
                leftRotate(xParent);
                w = xParent->getNextRight();
            }

            if (w->getNextLeft()->getColor() == COLOR::BLACK && w->getNextRight()->getColor() == COLOR::BLACK) {
                w->setColor(COLOR::RED);
                x = xParent;
                xParent = x->getParent().lock();
            } else {
                if (w->getNextRight()->getColor() == COLOR::BLACK) {
                    w->getNextLeft()->setColor(COLOR::BLACK);
                    w->setColor(COLOR::RED);
                    rightRotate(w);
                    w = xParent->getNextRight();
                } else {
                    w->setColor(xParent->getColor());
                    xParent->setColor(COLOR::BLACK);
                    w->getNextRight()->setColor(COLOR::BLACK);
                    leftRotate(xParent);
                    x = head_;
                    xParent = nullptr;
                }
            }
        } else /*x == x->getParent().lock()->getNextRight()*/ {

            w = xParent->getNextLeft();
            if (w->getColor() == COLOR::RED) {
                w->setColor(COLOR::BLACK);
                xParent->setColor(COLOR::RED);
                rightRotate(xParent);
                w = xParent->getNextLeft();
            }

            if (w->getNextLeft()->getColor() == COLOR::BLACK && w->getNextRight()->getColor() == COLOR::BLACK) {
                w->setColor(COLOR::RED);
                x = xParent;
                xParent = x->getParent().lock();
            } else {
                if (w->getNextLeft()->getColor() == COLOR::BLACK) {
                    w->getNextRight()->setColor(COLOR::BLACK);
                    w->setColor(COLOR::RED);
                    leftRotate(w);
                    w = xParent->getNextLeft();
                } else {
                    w->setColor(xParent->getColor());
                    xParent->setColor(COLOR::BLACK);
                    w->getNextLeft()->setColor(COLOR::BLACK);
                    rightRotate(xParent);
                    x = head_;
                    xParent = nullptr;
                }
            }
        }
    }
    x->setColor(COLOR::BLACK);
}



#endif //LAB2_HUFFMON_CODING_REDBLACKTREE_CPP
