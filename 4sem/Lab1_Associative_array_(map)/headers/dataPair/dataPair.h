#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H

template<class T_key, typename T_value>
class dataPair{
public:
    const T_key key;
    T_value value;
    dataPair(const T_key &key, T_value &value) : key(key), value(value) {}
    ~dataPair() = default;
};

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__DATAPAIR_H
