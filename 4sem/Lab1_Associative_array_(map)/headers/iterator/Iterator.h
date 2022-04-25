#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__ITERATOR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__ITERATOR_H

template<class T>
class Iterator{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
    virtual T getCurrent() = 0;
    virtual void setCurrent(T current) = 0;
};

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__ITERATOR_H
