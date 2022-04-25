#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H

//#include <initializer_list>

#include "../redBlackTree/redBlackTree.h"

template<class T_key, class T_value, class comparator = std::less<T_key>>
class associativeArray{
private:
    std::unique_ptr<redBlackTree<T_key, T_value>> rbTree_;
public:
    associativeArray() : rbTree_(nullptr) { }
    associativeArray(const T_key &key, const T_value &value);
    ~associativeArray() = default;

    bool isEmpty() const;
    void insert(const T_key &key, const T_value &value); // добавление элемента с ключом и значением
    std::unique_ptr<iterator<std::shared_ptr<elemOfRedBlackTree<T_key, T_value>>>> createDftIterator();

    void remove(const T_key &key); // удаление элемента по ключу
    std::shared_ptr<elemOfRedBlackTree<T_key, T_value>> find(const T_key &key) const; // поиск элемента по ключу
    bool contains(const T_key &key);
    void clear(); // очищение ассоциативного массива
    List<T_key> getKeys(); // возвращает список ключей
    List<T_value> getValues(); // возвращает список значений
    void print(); // вывод в консоль
};

#include "../../src/associativeArray/associativeArray.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
