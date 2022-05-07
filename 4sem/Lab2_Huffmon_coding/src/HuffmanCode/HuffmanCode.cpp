#include "../../headers/HuffmanCode/HuffmanCode.h"

std::string &HuffmanCode::getSourceString() {
    return string_;
}

std::string &HuffmanCode::getEncodedString() {
    return encodedString_;
}

void HuffmanCode::calculateSymbolsFrequency() {
    for (char symbol: string_) {
        if (!symbolsFrequency_.contains(symbol)) {
            symbolsFrequency_.insert(symbol, 1);
        } else {
            symbolsFrequency_.find(symbol)->getValue()++;
        }
    }
}

AssociativeArray<char, size_t> &HuffmanCode::getSymbolsFrequency() {
    calculateSymbolsFrequency();
    return symbolsFrequency_;
}

HuffmanTree &HuffmanCode::getHuffmanTree() {
    return huffmanTree_;
}

int HuffmanCode::getCountBytesByTheSourceString() const {
    return string_.size() * 8;
}

int HuffmanCode::getCountBytesByTheEncodedString() const {
    return encodedString_.size() * 8;
}

void HuffmanCode::clear() {
    string_ = "";
    encodedString_ = "";
    symbolsFrequency_.clear();
    huffmanTree_.clear();
}



