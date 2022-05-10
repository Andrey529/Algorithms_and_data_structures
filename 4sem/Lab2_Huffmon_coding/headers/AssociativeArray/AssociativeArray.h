#ifndef LAB2_HUFFMON_CODING_ASSOCIATIVEARRAY_H
#define LAB2_HUFFMON_CODING_ASSOCIATIVEARRAY_H

#include "../RedBlackTree/RedBlackTree.h"

template<class T_key, class T_value, class comparator = std::less<T_key>>
class AssociativeArray{
private:
    std::unique_ptr<RedBlackTree<T_key, T_value>> rbTree_;
public:
    AssociativeArray();
    AssociativeArray(const T_key &key, const T_value &value);
    explicit AssociativeArray(const AssociativeArray<T_key, T_value> &other);
    AssociativeArray& operator=(const AssociativeArray<T_key, T_value> &other) & ;
    ~AssociativeArray() = default;

    /**
     * Сhecks if an associative array is empty
     * @return true if empty, false if not empty
     */
    bool isEmpty() const;

    /**
    * Inserts value by key
    * @param key
    * @param value
    */
    void insert(const T_key &key, const T_value &value);

    /**
     * Returns an Iterator to width
     */
    std::unique_ptr<Iterator<std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>>> createBftIterator();

    /**
     * Removes the element with key = key
     * @param key
     */
    void remove(const T_key &key);

    /**
     * Finding an element by a key equal to key
     * @param key
     * @return shared pointer to founded element
     */
    std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>> find(const T_key &key) const;

    /**
    * Checks if there is an element with a key equal to key
    * @param key
    */
    bool contains(const T_key &key);

    /**
     * Clears an associative array leaving it empty
     */
    void clear();

    /**
     * Returns a list of all keys bypassing the associative array in width
     */
    List<T_key> getKeys();

    /**
     *  Returns a list of all values bypassing the associative array in width
     */
    List<T_value> getValues();

    /**
     * Prints {key : value} pairs to the console
     */
    void print();

    template<class Key, class Value>
    friend std::ostream& operator<< (std::ostream &out, AssociativeArray<T_key, T_value> &map); // overloading operator <<

};

#include "../../src/AssociativeArray/AssociativeArray.cpp"

#endif //LAB2_HUFFMON_CODING_ASSOCIATIVEARRAY_H
