#ifndef LAB3_FLOYD_WARSHALL_LIST_H
#define LAB3_FLOYD_WARSHALL_LIST_H


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

        bool operator!=(const ElemOfList &other) {
            return data_ != other.data_;
        }

        bool operator==(const ElemOfList &other) {
            return data_ == other.data_;
        }
    };
    using elemType = std::shared_ptr<ElemOfList>;
    elemType head_;

    elemType getPrevious(elemType elem);
    void swap(elemType elem1, elemType elem2);
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

    void remove(size_t index); // deleting an element by index
    void clear(); // removing all list elements
    bool contains(const T &data);

    bool operator==(const List<T>& other);

    template<typename U>
    friend std::ostream& operator<< (std::ostream &out, const List<U> &list); // overloading operator <<

    template<typename U>
    friend std::wostream& operator<< (std::wostream &out, const List<U> &list); // overloading operator <<


    template<typename Comparator = std::less<T>>
    void sort(Comparator comparator = std::less<T>());

    class ListIterator;
    ListIterator begin();
    ListIterator end();

    class ListIteratorConst;
    ListIteratorConst cbegin() const; // ?
    ListIteratorConst cend() const;   // ?

    class ListIteratorConst {
    private:
        std::shared_ptr<const ElemOfList> current_;

    public:
        ListIteratorConst() noexcept : current_ (nullptr) { }
        explicit ListIteratorConst(std::shared_ptr<const ElemOfList> pNode) noexcept : current_ (pNode) { }
        explicit ListIteratorConst(const ListIterator &other) : current_ (other.current_) { }

        ListIteratorConst& operator=(const ListIteratorConst &other);
        ListIteratorConst& operator=(std::shared_ptr<const ElemOfList> pNode);

        ListIteratorConst& operator++();  // Prefix ++ overload
        const ListIteratorConst operator++(int); // Postfix ++ overload
        bool operator!=(const ListIteratorConst& iterator);
        const T& operator*() const;
    };

    class ListIterator {
    private:
        elemType current_;

    public:
        ListIterator() noexcept : current_ (nullptr) { }
        explicit ListIterator(const elemType pNode) noexcept : current_ (pNode) { }
        ListIterator(const ListIterator &other) : current_ (other.current_) { }
//        ListIterator(const ListIterator &&other) noexcept : current_ (std::move(other.current_)) { }

        ListIterator& operator=(const ListIterator &other);
//        ListIterator& operator=(const ListIterator &&other) noexcept {
//            current_ = std::move(other.current_);
//            return *this;
//        }

        ListIterator& operator=(elemType pNode);

        ListIterator& operator++();  // Prefix ++ overload
        ListIterator operator++(int); // Postfix ++ overload
        bool operator!=(const ListIterator& iterator);
        T& operator*();
    };

};


#include "../../src/List/List.cpp"

#endif //LAB3_FLOYD_WARSHALL_LIST_H
