#ifndef LAB2_HUFFMON_CODING_HUFFMANCODE_H
#define LAB2_HUFFMON_CODING_HUFFMANCODE_H

#include <string>
#include "../List/List.h"
#include "../AssociativeArray/AssociativeArray.h"
#include "HuffmanTree.h"

class HuffmanCode {
private:
    std::string string_;
    std::string encodedString_;
    AssociativeArray<char, size_t> symbolsFrequency_;
    HuffmanTree huffmanTree;
    void calculateSymbolsFrequency();

public:
    HuffmanCode() = default;
    explicit HuffmanCode(const std::string &str) : string_(str) {
        calculateSymbolsFrequency();
        huffmanTree.buildTree(symbolsFrequency_);
    }
    explicit HuffmanCode(std::string &&str) : string_(std::move(str)), encodedString_() {
        calculateSymbolsFrequency();
        huffmanTree.buildTree(symbolsFrequency_);
    }

    void setSourceString(const std::string &str) {
        string_ = str;
        calculateSymbolsFrequency();
        huffmanTree.buildTree(symbolsFrequency_);
    }

    void setSourceString(std::string &&str) {
        string_ = str;
        calculateSymbolsFrequency();
        huffmanTree.buildTree(symbolsFrequency_);
    }

    std::string &getSourceString();
    std::string &getEncodedString();
    AssociativeArray<char, size_t> &getSymbolsFrequency();
    int getCountBytesByTheSourceString() const;
    int getCountBytesByTheEncodedString() const;

};

#endif //LAB2_HUFFMON_CODING_HUFFMANCODE_H
