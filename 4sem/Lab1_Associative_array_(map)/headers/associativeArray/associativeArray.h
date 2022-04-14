#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H

//#include <initializer_list>

#include "../redBlackTree/redBlackTree.h"

template<class T_key, class T_value, class comparator = std::less<T_key>>
class associativeArray{
private:
    std::unique_ptr<redBlackTree<T_key, T_value>> rbTree;
public:
    associativeArray();
    associativeArray(const T_key &key, const T_value &value);
    ~associativeArray() = default;

    void insert(const T_key &key, const T_value &value); // добавление элемента с ключом и значением


    //    void remove(T_key key); // удаление элемента по ключу

    // посмотреть как возвращать умный указатель на элемента, чтобы элемент нельзя было изменять
//    const std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> find(T_key key) const; // поиск элемента по ключу
//
//    void clear(); // очищение ассоциативного массива
//
//
//    std::unique_ptr<T_key[]> getKeys(); // возвращает список ключей
//    std::unique_ptr<T_value[]> getValues(); // возвращает список значений
//
//    void print(); // вывод в консоль

//    associativeArray(std::initializer_list);

};

#include "../../src/associativeArray/associativeArray.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_H
