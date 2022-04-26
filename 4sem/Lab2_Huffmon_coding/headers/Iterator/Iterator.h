#ifndef LAB2_HUFFMON_CODING_ITERATOR_H
#define LAB2_HUFFMON_CODING_ITERATOR_H

template<class T>
class Iterator{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
    virtual T getCurrent() = 0;
    virtual void setCurrent(T current) = 0;
};

#endif //LAB2_HUFFMON_CODING_ITERATOR_H
