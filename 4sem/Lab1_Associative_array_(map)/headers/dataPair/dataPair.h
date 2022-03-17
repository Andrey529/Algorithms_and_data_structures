#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H

template<class T_key, class T_value>
class dataPair{
    const T_key key;
    T_value value;
public:
    dataPair(const T_key &key, const T_value &value) : key(key), value(value) {}
    dataPair(T_key &&key, T_value &&value) : key(std::move(key)), value(std::move(value)) {}
    ~dataPair() = default;
    T_key getKey() const;
    T_value getValue() const;
    void setValue(const T_value &value);
    void setValue(T_value &&value);
};

template<class T_key, class T_value>
T_key dataPair<T_key, T_value>::getKey() const {
    return this->key;
}

template<class T_key, class T_value>
T_value dataPair<T_key, T_value>::getValue() const {
    return this->value;
}

template<class T_key, class T_value>
void dataPair<T_key, T_value>::setValue(const T_value &value) {
    this->value = value;
}

template<class T_key, class T_value>
void dataPair<T_key, T_value>::setValue(T_value &&value) {
    this->value = std::move(value);
}

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H
