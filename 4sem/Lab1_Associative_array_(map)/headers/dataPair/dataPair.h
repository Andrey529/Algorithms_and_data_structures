#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H

template<class T_first, class T_second>
class dataPair{
private:
    T_first first;
    T_second second;
public:
    dataPair() : first(), second() { }

    dataPair(const T_first  &first, const T_second &second) : first(first), second(second) { }
    dataPair(T_first &&first, T_second &&second) : first(std::move(first)), second(std::move(second)) { }
    dataPair(const T_first &first, T_second &&second) : first(first), second(std::move(second)) { }
    dataPair(T_first &&first, const T_second &second) : first(std::move(first)), second(second) { }

    dataPair(const dataPair<T_first, T_second> &pair) : first(pair.first), second(pair.second) { }
    dataPair(dataPair<T_first, T_second> &&pair)  noexcept : first(std::move(pair.first)), second(std::move(pair.second)) { }
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
    return this->first;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setFirst(const T_first &first) {
    this->first = first;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setFirst(T_first &&first) {
    this->first = std::move(first);
}

template<class T_first, class T_second>
T_second dataPair<T_first, T_second>::getSecond() const {
    return this->second;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setSecond(const T_second &second) {
    this->second = second;
}

template<class T_first, class T_second>
void dataPair<T_first, T_second>::setSecond(T_second &&second) {
    this->second = std::move(second);
}

template<class T_first, class T_second>
dataPair<T_first, T_second> &dataPair<T_first, T_second>::operator=(const dataPair<T_first, T_second> &other) {
    this->first = other.first;
    this->second = other.second;
    return *this;
}

template<class T_first, class T_second>
dataPair<T_first, T_second> &dataPair<T_first, T_second>::operator=(dataPair<T_first, T_second> &&other) noexcept {
    this->first = std::move(other.first);
    this->second = std::move(other.second);
    return *this;
}

//template<class T_key, class T_data>
//class mapDataPair : public dataPair<const T_key, T_data> {
//public:

//};

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H