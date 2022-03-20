#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H

template<class T_first, class T_second>
class dataPair{
private:
    T_first first_;
    T_second second_;
public:
    dataPair() : first_(), second_() { }

    dataPair(const T_first  &first, const T_second &second) : first_(first), second_(second) { }
    dataPair(T_first &&first, T_second &&second) : first_(std::move(first)), second_(std::move(second)) { }
    dataPair(const T_first &first, T_second &&second) : first_(first), second_(std::move(second)) { }
    dataPair(T_first &&first, const T_second &second) : first_(std::move(first)), second_(second) { }

    dataPair(const dataPair<T_first, T_second> &pair) : first_(pair.first), second_(pair.second) { }
    dataPair(dataPair<T_first, T_second> &&pair)  noexcept : first_(std::move(pair.first)), second_(std::move(pair.second)) { }
    ~dataPair() = default;

    dataPair& operator=(const dataPair<T_first, T_second> &other);
    dataPair& operator=(dataPair<T_first, T_second> &&other) noexcept ;

    T_first getFirst() const;
    void setFirst(const T_first &first);
    void setFirst(T_first &&first);
    T_second getSecond() const;
    void setSecond(const T_second &second);
    void setSecond(T_second &&second);
};

template<class T_first, class T_second>
T_first dataPair<T_first, T_second>::getFirst() const {
    return first_;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setFirst(const T_first &first) {
    first_ = first;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setFirst(T_first &&first) {
    first_ = std::move(first);
}

template<class T_first, class T_second>
T_second dataPair<T_first, T_second>::getSecond() const {
    return second_;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setSecond(const T_second &second) {
    second_ = second;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setSecond(T_second &&second) {
    second_ = std::move(second);
}

template<class T_first, class T_second>
dataPair<T_first, T_second> &dataPair<T_first, T_second>::operator=(const dataPair<T_first, T_second> &other) {
    if (this == &other) {
        return *this;
    }
    first_ = other.first;
    second_ = other.second;
    return *this;
}

template<class T_first, class T_second>
dataPair<T_first, T_second> &dataPair<T_first, T_second>::operator=(dataPair<T_first, T_second> &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    first_ = std::move(other.first);
    second_ = std::move(other.second);
    return *this;
}

//template<class T_key, class T_data>
//class mapDataPair : public dataPair<const T_key, T_data> {
//public:

//};

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H