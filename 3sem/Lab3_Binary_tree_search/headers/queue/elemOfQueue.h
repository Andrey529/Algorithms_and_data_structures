#ifndef LAB3_ELEMOFQUEUE_H
#define LAB3_ELEMOFQUEUE_H

template<class T>
class elemOfQueue{
private:
    T data;
    elemOfQueue *nextElem;
public:
    elemOfQueue();
    elemOfQueue(T data);
    elemOfQueue(elemOfQueue<T> *elem);
    ~elemOfQueue() = default;

    T getData() const;
    T *getData();

    void setData(T data);

    elemOfQueue *getNextElem() const;
    void setNextElem(elemOfQueue *nextElem);

};

#include "../../src/queue/elemOfQueue.cpp"

#endif //LAB3_ELEMOFQUEUE_H
