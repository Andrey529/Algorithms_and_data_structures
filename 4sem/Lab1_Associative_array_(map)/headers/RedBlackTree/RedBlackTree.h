#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H

#include "ElemOfRedBlackTree.h"
#include "../iterator/RedBlackTreeBreadthFirstTraverseIterator.h"
#include "../List/List.h"
#include <iostream>

template<class T_key, class T_value, class comparator = std::less<T_key>>
class RedBlackTree {
private:
    std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> head_;

    void leftRotate(std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> elem);
    void rightRotate(std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> elem);

    void repairTreeAfterInsert(std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> newElem);
    void repairTreeAfterRemove(std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> elem);
public:

    RedBlackTree(const T_key &key, const T_value &value);
    RedBlackTree() : head_(nullptr) {}
    ~RedBlackTree() = default;

    /**
     * Сhecks if a red black tree is empty
     * @return true if empty, false if not empty
     */
    bool isEmpty() const;

    /**
     * Inserts value by key
     * @param key
     * @param value
     */
    void insert(const T_key &key, const T_value &value);

    /**
     * Returns an iterator to width
     */
    std::unique_ptr<Iterator<std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>>> createDftIterator();

    /**
     * Removes the element with key = key
     * @param key
     */
    void remove(const T_key &key);

    /**
     * Finding an element by a key equal to key
     * @param key
     * @return shared pointer to founded element
     */
    std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> find(const T_key &key) const;

    /**
     * Checks if there is an element with a key equal to key
     * @param key
     */
    bool contains(const T_key &key);

    /**
     * Clears an red black tree leaving it empty
     */
    void clear();

    /**
     * Returns a list of all keys bypassing the red black tree in width
     */
    List<T_key> getKeys();

    /**
     * Returns a list of all values bypassing the red black tree in width
     */
    List<T_value> getValues();

    /**
     * Prints {key : value} pairs to the console
     */
    void print();
};


#include "../../src/RedBlackTree/RedBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
