#ifndef LAB1_LIST_DATA_H
#define LAB1_LIST_DATA_H

class data {
private:
    int number;
    data *nextElem;
public:
    data(int number = 0, data *nextElem = nullptr) : number(number), nextElem(nextElem)
    { }
    ~data();

    int getNumber() const;
    void setNumber(int number);
    data *getNextElem() const;
    void setNextElem(data *elem);
};

int data::getNumber() const {
    return this->number;
}

void data::setNumber(int number) {
    this->number = number;
}

data *data::getNextElem() const {
    return this->nextElem;
}

void data::setNextElem(data *elem) {
    this->nextElem = elem;
}

data::~data() = default;


#endif //LAB1_LIST_DATA_H
