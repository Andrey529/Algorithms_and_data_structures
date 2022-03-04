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


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ASSOCIATIVEARRAY_CPP
