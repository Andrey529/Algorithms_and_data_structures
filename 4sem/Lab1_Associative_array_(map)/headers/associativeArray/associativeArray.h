#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H

//#include <initializer_list>

#include "../redBlackTree/redBlackTree.h"

template<class T_key, class T_value>
class associativeArray{
private:
    std::unique_ptr<redBlackTree<T_key, T_value>> rbTree;
public:
    associativeArray();
    associativeArray(T_key key, T_value value);
//    associativeArray(std::initializer_list);
    ~associativeArray() = default;

    void insert(T_key key, T_value value); // добавление элемента с ключом и значением
    void remove(T_key key); // удаление элемента по ключу

    // посмотреть как возвращать умный указатель на элемента, чтобы элемент нельзя было изменять
    std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> find(T_key key) const; // поиск элемента по ключу

    void clear(); // очищение ассоциативного массива


    std::unique_ptr<T_key[]> get_keys(); // возвращает список ключей
    std::unique_ptr<T_value[]> get_values(); // возвращает список значений

    void print(); // вывод в консоль
};

#include "../../src/associativeArray/associativeArray.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
