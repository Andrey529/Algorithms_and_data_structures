#ifndef LAB2_HUFFMON_CODING_HUFFMANCODE_H
#define LAB2_HUFFMON_CODING_HUFFMANCODE_H

#include <string>
#include "../List/List.h"
#include "../AssociativeArray/AssociativeArray.h"
#include "HuffmanTree.h"
#include "../Stack/Stack.h"

class HuffmanCode {
private:
    std::string string_;
    std::string encodedString_;
    AssociativeArray<char, size_t> symbolsFrequency_;
    HuffmanTree huffmanTree_;
    AssociativeArray<char, List<bool>> table_;

    void calculateSymbolsFrequency();
    AssociativeArray<char, size_t> &getSymbolsFrequency();
    void constructingTheEncodedString();
    void constructingTheTable();
public:
    HuffmanCode() = default;
    explicit HuffmanCode(const std::string &str) : string_(str) {
        calculateSymbolsFrequency();
        huffmanTree_.buildTree(symbolsFrequency_);
        constructingTheTable();
        constructingTheEncodedString();
    }
    explicit HuffmanCode(std::string &&str) : string_(std::move(str)), encodedString_() {
        calculateSymbolsFrequency();
        huffmanTree_.buildTree(symbolsFrequency_);
        constructingTheTable();
        constructingTheEncodedString();
    }

    void setSourceString(const std::string &str) {
        string_ = str;
        calculateSymbolsFrequency();
        huffmanTree_.buildTree(symbolsFrequency_);
        constructingTheTable();
        constructingTheEncodedString();
    }

    void setSourceString(std::string &&str) {
        string_ = str;
        calculateSymbolsFrequency();
        huffmanTree_.buildTree(symbolsFrequency_);
        constructingTheTable();
        constructingTheEncodedString();
    }

    std::string &getSourceString();
    std::string &getEncodedString();
    HuffmanTree &getHuffmanTree();
    AssociativeArray<char, List<bool>> &getTable();
    int getCountBytesByTheSourceString() const;
    int getCountBytesByTheEncodedString() const;
    void clear();
    double getCompressionRatio();

};

#endif //LAB2_HUFFMON_CODING_HUFFMANCODE_H
