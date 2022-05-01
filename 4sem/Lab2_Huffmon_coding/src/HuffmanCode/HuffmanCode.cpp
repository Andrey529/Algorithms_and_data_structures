#include "../../headers/HuffmanCode/HuffmanCode.h"

std::string &HuffmanCode::getString() {
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
    return symbolsFrequency_;
}
