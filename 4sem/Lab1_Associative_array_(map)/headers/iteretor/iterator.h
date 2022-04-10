#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ITERATOR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ITERATOR_H

template<class T_key>
class iterator{
public:
    virtual T_key next() = 0;
    virtual bool hasNext() = 0;
};

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ITERATOR_H
