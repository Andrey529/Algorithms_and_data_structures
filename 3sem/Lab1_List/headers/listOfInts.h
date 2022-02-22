#ifndef LAB1_LIST_LISTOFINTS_H
#define LAB1_LIST_LISTOFINTS_H

#include "data.h"
#include <cstddef>
#include "iostream"

class listOfInts {
private:
    data *head;
public:
    listOfInts(data *elem = nullptr);
    ~listOfInts();

    bool isEmpty(); // checking if the list is empty
    void push_back(int number); //adding new element in the end of the list
    void push_front(int number); //adding new element in the begin of the list
    void pop_back(); // deleting last element in the list
    void pop_front(); // deleting first element in the list
    void insert(int number, size_t index); // adding an element at index
    // (insertion before an item that was previously accessible at that index)

    int at(size_t index) const; // getting an element data at the index
    size_t get_size() const; // getting list size
    void set(size_t index, int number); // replacing the element by index with the passed element

    void remove(size_t index); // deleting an element by index
    void clear(); // removing all list elements

    friend std::ostream& operator<< (std::ostream &out, const listOfInts &list); // overloading operator <<

    void reverse(); // reverses the order of the elements in the list
};

listOfInts::listOfInts(data *elem) {
    if(elem == nullptr){
        this->head = nullptr;
        return;
    }

    auto *newElem = new data(elem->getNumber(), elem->getNextElem());
    this->head = newElem;
}

listOfInts::~listOfInts() {
    data *elem = this->head;
    data *tempElem;
    while(elem != nullptr){
        tempElem = elem;
        elem = elem->getNextElem();
        delete tempElem;
    }
}

bool listOfInts::isEmpty() {
    return head == nullptr;
}

void listOfInts::push_back(int number) {

    auto *newElem = new data(number);

    data *elem = this->head;
    if(elem == nullptr){
        this->head = newElem;
        return;
    }

    while(elem->getNextElem() != nullptr){
        elem = elem->getNextElem();
    }

    elem->setNextElem(newElem);
}

void listOfInts::push_front(int number) {
    auto *newElem = new data(number);

    data *elem = this->head;
    if(elem == nullptr){
        this->head = newElem;
    }

    this->head = newElem;
    newElem->setNextElem(elem);

}

void listOfInts::pop_back() {
    if(this->head == nullptr){
        throw std::runtime_error("List is empty in function pop_back()");
    }
    data *elem = this->head;
    data *tempElem;
    while(elem->getNextElem() != nullptr){
        tempElem = elem;
        elem = elem->getNextElem();
    }
    delete elem;
    tempElem->setNextElem(nullptr);
}

void listOfInts::pop_front() {
    if(this->head == nullptr){
        throw std::runtime_error("List is empty in function pop_front()");
    }
    data *elem = this->head;
    this->head = this->head->getNextElem();
    delete elem;
}

void listOfInts::insert(int number, size_t index) {

    data *newElem = new data(number);

    if(this->head == nullptr){
        this->head = newElem;
        return;
    }

    if (index + 1 > get_size()) {
        throw std::invalid_argument("Index greater than size of array in function insert()");
    }

    if(index == 0){
        newElem->setNextElem(this->head);
        this->head = newElem;
        return;
    }


    data *elem = this->head;
    for(int i = 0; i < index-1; i++){
        elem = elem->getNextElem();
    }

    newElem->setNextElem(elem->getNextElem());
    elem->setNextElem(newElem);

}

int listOfInts::at(size_t index) const{
    data *elem = this->head;

    if ((index + 1) > get_size()) {
        throw std::invalid_argument("Index greater than size of array in function at()");
    }

    int i = 0;
    while(i != index){
        elem = elem->getNextElem();
        i++;
    }
    return elem->getNumber();
}

void listOfInts::remove(size_t index) {

    if (index + 1 > get_size()) {
        throw std::invalid_argument("Index greater than size of array in function remove()");
    }

    if(this->head == nullptr){
        return;
    }

    data *elem = this->head;

    if(index == 0){
        this->head = this->head->getNextElem();
        delete elem;
        return;
    }



    for(int i = 0; i < index-1; i++){
        elem = elem->getNextElem();
    }

    data *delElem = elem->getNextElem();
    elem->setNextElem(delElem->getNextElem());
    delete delElem;
}

size_t listOfInts::get_size() const{
    data *elem = this->head;
    int sizeList = 0;
    while(elem != nullptr){
        sizeList++;
        elem = elem->getNextElem();
    }
    return sizeList;
}

void listOfInts::clear() {
    data *elem = this->head;
    this->head = nullptr;
    data *tempElem;
    while(elem != nullptr){
        tempElem = elem;
        elem = elem->getNextElem();
        delete tempElem;
    }
}

void listOfInts::set(size_t index, int number) {

    if (index + 1 > get_size()) {
        throw std::invalid_argument("Index greater than size of array in function set()");
    }

    if(index == 0){
        this->head->setNumber(number);
        return;
    }

    data *elem = this->head;

    for(int i = 0; i < index; i++){
        elem = elem->getNextElem();
    }

    elem->setNumber(number);
}

std::ostream &operator<<(std::ostream &out, const listOfInts &list) {

    out << "List of integers:" << std::endl;
    int i = 1;
    for (size_t index = 0; index < list.get_size(); index++){
        out << i << " element: number = " << list.at(index) << std::endl;
        i++;
    }
    return out;
}

void listOfInts::reverse() {
    if(get_size() <= 1)    return;

    int tmpElem;
    for(size_t i = 0; i < get_size()/2; i++){
        tmpElem = at(i);
        set(i,at(get_size()-1-i));
        set(get_size()-1-i,tmpElem);
    }
}


#endif //LAB1_LIST_LISTOFINTS_H
