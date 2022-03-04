#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_CPP

#include "../../headers/associativeArray/associativeArray.h"

template<class T_key, class T_value>
associativeArray<T_key, T_value>::associativeArray() {
    this->rbTree = nullptr;
}

template<class T_key, class T_value>
associativeArray<T_key, T_value>::associativeArray(T_key key, T_value value) {
    try {
        this->rbTree = std::make_unique<redBlackTree<T_key, T_value>>(key, value);
    }
    catch (const std::bad_alloc &e) {
        std::cout << e.what();
    }
}

template<class T_key, class T_value>
void associativeArray<T_key, T_value>::insert(T_key key, T_value value) {
    this->rbTree->insert(key, value);
}

template<class T_key, class T_value>
void associativeArray<T_key, T_value>::remove(T_key key) {
    this->rbTree->remove(key);
}

template<class T_key, class T_value>
void associativeArray<T_key, T_value>::clear() {
    this->rbTree->clear();
}

template<class T_key, class T_value>
void associativeArray<T_key, T_value>::print() {
    this->rbTree->print();
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_CPP
