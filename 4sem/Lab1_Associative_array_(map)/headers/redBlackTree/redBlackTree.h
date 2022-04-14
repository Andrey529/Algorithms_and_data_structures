#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H

#include "elemOfRedBlackTree.h"
#include "../iterator/RedBlackTreeBreadthFirstTraverseIterator.h"
#include "../List/List.h"
#include <iostream>

template<class T_key, class T_value, class comparator = std::less<T_key>>
class redBlackTree {
private:
    std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> head_;
public:
    redBlackTree(const T_key &key, const T_value &value);
    redBlackTree() : head_(nullptr) {}
    ~redBlackTree() = default;

    bool isEmpty() const;
    void insert(const T_key &key, const T_value &value); // добавление элемента с ключом и значением
    std::unique_ptr<iterator<std::shared_ptr<elemOfRedBlackTree<T_key, T_value>>>> createDftIterator();

//    void remove(T_key key); // удаление элемента по ключу
//    std::weak_ptr<elemOfRedBlackTree<T_key, T_value>> find(const T_key &key) const; // поиск элемента по ключу
    void clear(); // очищение ассоциативного массива
    List<T_key> getKeys(); // возвращает список ключей
    List<T_value> getValues(); // возвращает список значений
    void print(); // вывод в консоль
};


#include "../../src/redBlackTree/redBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
