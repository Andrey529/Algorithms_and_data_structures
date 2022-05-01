#ifndef LAB2_HUFFMON_CODING_HUFFMANCODE_H
#define LAB2_HUFFMON_CODING_HUFFMANCODE_H

#include <string>
#include "../List/List.h"
#include "../AssociativeArray/AssociativeArray.h"

class HuffmanCode {
private:
    std::string string_;
    std::string encodedString_;
    AssociativeArray<char, size_t> symbolsFrequency_;
public:
    HuffmanCode() : string_(), encodedString_() { }
    explicit HuffmanCode(const std::string &str) : string_(str), encodedString_() { }
    explicit HuffmanCode(std::string &&str) : string_(std::move(str)), encodedString_() { }

    std::string &getString();
    std::string &getEncodedString();
    AssociativeArray<char, size_t> &getSymbolsFrequency();
    void calculateSymbolsFrequency();
};

#endif //LAB2_HUFFMON_CODING_HUFFMANCODE_H
