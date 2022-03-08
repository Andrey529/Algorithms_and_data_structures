#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_CPP

#include "../../headers/associativeArray/associativeArray.h"

template<class T_key, class T_value, class comparator>
associativeArray<T_key, T_value, comparator>::associativeArray() {
    this->rbTree = nullptr;
}

template<class T_key, class T_value, class comparator>
associativeArray<T_key, T_value, comparator>::associativeArray(const T_key &key, const T_value &value) {
    try {
        this->rbTree = std::make_unique<redBlackTree<T_key, T_value, comparator>>(key, value);
    }
    catch (const std::bad_alloc &error) {
        std::cout << error.what();
    }
}

template<class T_key, class T_value, class comparator>
void associativeArray<T_key, T_value, comparator>::insert(const T_key &key, const T_value &value) {
    this->rbTree->insert(key, value);
}

//template<class T_key, class T_value>
//void associativeArray<T_key, T_value>::remove(T_key key) {
//    this->rbTree->remove(key);
//}
//
//template<class T_key, class T_value>
//void associativeArray<T_key, T_value>::clear() {
//    this->rbTree->clear();
//}
//
//template<class T_key, class T_value>
//void associativeArray<T_key, T_value>::print() {
//    this->rbTree->print();
//}

//template<class T_key, class T_value>
//const std::unique_ptr <elemOfRedBlackTree<T_key, T_value>> associativeArray<T_key, T_value>::find(T_key key) const {
//    std::unique_ptr<elemOfRedBlackTree<T_key, T_value>> tmp = this->rbTree->find(key);
//    return std::move(tmp);
//}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_CPP
