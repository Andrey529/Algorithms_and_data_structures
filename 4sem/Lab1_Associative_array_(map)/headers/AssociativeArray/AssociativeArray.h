#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H

//#include <initializer_list>

#include "../RedBlackTree/RedBlackTree.h"

template<class T_key, class T_value, class comparator = std::less<T_key>>
class AssociativeArray{
private:
    std::unique_ptr<RedBlackTree<T_key, T_value>> rbTree_;
public:
    AssociativeArray() : rbTree_(nullptr) { }
    AssociativeArray(const T_key &key, const T_value &value);
    ~AssociativeArray() = default;

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

#include "../../src/AssociativeArray/AssociativeArray.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
