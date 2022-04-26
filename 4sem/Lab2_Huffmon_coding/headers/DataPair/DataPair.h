#ifndef LAB2_HUFFMON_CODING_DATAPAIR_H
#define LAB2_HUFFMON_CODING_DATAPAIR_H

template<class T_first, class T_second>
class DataPair{
private:
    T_first first_;
    T_second second_;
public:
    DataPair() : first_(), second_() { }

    DataPair(const T_first  &first, const T_second &second) : first_(first), second_(second) { }
    DataPair(T_first &&first, T_second &&second) : first_(std::move(first)), second_(std::move(second)) { }
    DataPair(const T_first &first, T_second &&second) : first_(first), second_(std::move(second)) { }
    DataPair(T_first &&first, const T_second &second) : first_(std::move(first)), second_(second) { }

    DataPair(const DataPair<T_first, T_second> &pair) : first_(pair.first), second_(pair.second) { }
    DataPair(DataPair<T_first, T_second> &&pair)  noexcept : first_(std::move(pair.first)), second_(std::move(pair.second)) { }
    ~DataPair() = default;

    DataPair& operator=(const DataPair<T_first, T_second> &other) & ;
    DataPair& operator=(DataPair<T_first, T_second> &&other) & noexcept;

    const T_first& getFirst() const;
    T_first& getFirst();
    void setFirst(const T_first &first);
    void setFirst(T_first &&first);

    const T_second& getSecond() const;
    T_second& getSecond();
    void setSecond(const T_second &second);
    void setSecond(T_second &&second);
};

template<class T_first, class T_second>
const T_first& DataPair<T_first, T_second>::getFirst() const {
    return first_;
}

template<class T_first, class T_second>
T_first &DataPair<T_first, T_second>::getFirst() {
    return first_;
}

template<class T_first, class T_second>
void DataPair<T_first, T_second>::setFirst(const T_first &first) {
    first_ = first;
}

template<class T_first, class T_second>
void DataPair<T_first, T_second>::setFirst(T_first &&first) {
    first_ = std::move(first);
}

template<class T_first, class T_second>
const T_second& DataPair<T_first, T_second>::getSecond() const {
    return second_;
}

template<class T_first, class T_second>
T_second& DataPair<T_first, T_second>::getSecond() {
    return second_;
}

template<class T_first, class T_second>
void DataPair<T_first, T_second>::setSecond(const T_second &second) {
    second_ = second;
}

template<class T_first, class T_second>
void DataPair<T_first, T_second>::setSecond(T_second &&second) {
    second_ = std::move(second);
}

template<class T_first, class T_second>
DataPair<T_first, T_second> &DataPair<T_first, T_second>::operator=(const DataPair<T_first, T_second> &other) & {
    if (this == &other) {
        return *this;
    }
    first_ = other.first;
    second_ = other.second;
    return *this;
}

template<class T_first, class T_second>
DataPair<T_first, T_second> &DataPair<T_first, T_second>::operator=(DataPair<T_first, T_second> &&other) & noexcept {
    if (this == &other) {
        return *this;
    }
    first_ = std::move(other.first);
    second_ = std::move(other.second);
    return *this;
}

#endif //LAB2_HUFFMON_CODING_DATAPAIR_H
