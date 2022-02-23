#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

template<class T>
class iterator{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};


#endif //LAB3_ITERATOR_H
