#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H

#include "elemOfRedBlackTree.h"
#include "../iteretor/RedBlackTreeBreadthFirstTraverseIterator.h"

template<class T_key, class T_value, class comparator = std::less<T_key>>
class redBlackTree{
private:
    std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> head;
public:
    redBlackTree(const T_key &key, const T_value &value);
    redBlackTree() : head(nullptr) {}
    ~redBlackTree() = default;

    bool isEmpty() const;
    void insert(const T_key &key, const T_value &value); // добавление элемента с ключом и значением

    iterator<elemOfRedBlackTree<T_key, T_value>> *create_dft_iterator();;

//    void remove(T_key key); // удаление элемента по ключу
//    const std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> find(T_key key) const; // поиск элемента по ключу
    void clear(); // очищение ассоциативного массива
//    std::unique_ptr<T_key[]> get_keys(); // возвращает список ключей
//    std::unique_ptr<T_value[]> get_values(); // возвращает список значений
//    void print(); // вывод в консоль

};


#include "../../src/redBlackTree/redBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
