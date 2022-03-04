#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H

#include "elemOfRedBlackTree.h"


template<class T_key, class T_value>
class redBlackTree{
private:
    std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> head;
public:
    redBlackTree(T_key key, T_value value);
    redBlackTree(std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> head = nullptr);

    ~redBlackTree() = default;

    void insert(T_key key, T_value value); // добавление элемента с ключом и значением
    void remove(T_key key); // удаление элемента по ключу
    std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> find(T_key key) const; // поиск элемента по ключу
    void clear(); // очищение ассоциативного массива
    std::unique_ptr<T_key[]> get_keys(); // возвращает список ключей
    std::unique_ptr<T_value[]> get_values(); // возвращает список значений
    void print(); // вывод в консоль

};


#include "../../src/redBlackTree/redBlackTree.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREE_H
