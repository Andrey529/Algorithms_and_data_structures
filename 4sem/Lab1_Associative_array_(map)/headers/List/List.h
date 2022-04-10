#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__LIST_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__LIST_H

#include <memory>
#include <iostream>

template<class T>
class List{
private:
    struct ElemOfList{
        T data_;
        std::shared_ptr<ElemOfList> nextElem_;
        explicit ElemOfList(const T &data) : data_(data), nextElem_(nullptr) { }
        explicit ElemOfList(T &&data) : data_(std::move(data)), nextElem_(nullptr) { }
    };

    std::shared_ptr<ElemOfList> head_;

public:
    List() : head_() { }
    explicit List(const T &data);
    explicit List(T &&data);
    List(const List<T> &other);
    List(List<T> &&other) noexcept ;
    ~List() = default;

    bool isEmpty() const; // checking if the list is empty
    void pushBack(const T &data); //adding new element in the end of the list
    void pushBack(T &&data);

    void pushFront(const T &data); //adding new element in the begin of the list
    void pushFront(T &&data);

    void popBack(); // deleting last element in the list
    void popFront(); // deleting first element in the list

    void insert(const T& data, size_t index); // adding an element at index
    void insert(T &&data, size_t index);
    // (insertion before an item that was previously accessible at that index)

    const T& at(size_t index) const; // getting an element data at the index
    T& at(size_t index);

    size_t getSize() const; // getting list size
//    void set(size_t index, const T &data); // replacing the element by index with the passed element
//    void set(size_t index, T &&data);

//    void remove(size_t index); // deleting an element by index
//    void clear(); // removing all list elements

//    friend std::ostream& operator<< (std::ostream &out, const List &list); // overloading operator <<
};


#include "../../src/List/List.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__LIST_H
