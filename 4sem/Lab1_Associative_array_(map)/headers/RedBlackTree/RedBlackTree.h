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

    bool isEmpty() const;
    void insert(const T_key &key, const T_value &value); // добавление элемента с ключом и значением
    std::unique_ptr<Iterator<std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>>> createDftIterator();

    void remove(const T_key &key); // удаление элемента по ключу
    std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> find(const T_key &key) const; // поиск элемента по ключу
    bool contains(const T_key &key);
    void clear(); // очищение ассоциативного массива
    List<T_key> getKeys(); // возвращает список ключей
    List<T_value> getValues(); // возвращает список значений
    void print(); // вывод в консоль
};


#include "../../src/RedBlackTree/RedBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
