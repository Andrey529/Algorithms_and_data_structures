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

    void encode(const std::string &str) {
        clear();
        string_ = str;
        calculateSymbolsFrequency();
        huffmanTree_.buildTree(symbolsFrequency_);
        constructingTheTable();
        constructingTheEncodedString();
    }

    void encode(std::string &&str) {
        clear();
        string_ = str;
        calculateSymbolsFrequency();
        huffmanTree_.buildTree(symbolsFrequency_);
        constructingTheTable();
        constructingTheEncodedString();
    }

    void decode(const std::string &str, const AssociativeArray<char, List<bool>> &table) {
        clear();
//        table_ = table;
        encodedString_ = str;

        size_t index = 0;
        while (true) {

        }
    }

    void decode(std::string &&str) {

    }


    std::string &getSourceString();
    std::string &getEncodedString();
//    HuffmanTree &getHuffmanTree();
    AssociativeArray<char, List<bool>> &getTable();
    size_t getCountBytesByTheSourceString() const;
    size_t getCountBytesByTheEncodedString() const;
    void clear();
    double getCompressionRatio();

};

#endif //LAB2_HUFFMON_CODING_HUFFMANCODE_H
