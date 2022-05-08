#include "../../headers/HuffmanCode/HuffmanCode.h"

std::string &HuffmanCode::getSourceString() {
    return string_;
}

std::string &HuffmanCode::getEncodedString() {
    return encodedString_;
}

void HuffmanCode::calculateSymbolsFrequency() {
    if (string_.empty()) {
        throw std::invalid_argument("Source string to encoding is empty.");
    }
    for (char symbol: string_) {
        if (!symbolsFrequency_.contains(symbol)) {
            symbolsFrequency_.insert(symbol, 1);
        } else {
            symbolsFrequency_.find(symbol)->getValue()++;
        }
    }
}

AssociativeArray<char, size_t> &HuffmanCode::getSymbolsFrequency() {
    if (string_.empty()) {
        throw std::logic_error("Source string to encoding is empty.");
    }
    return symbolsFrequency_;
}

HuffmanTree &HuffmanCode::getHuffmanTree() {
    if (string_.empty()) {
        throw std::logic_error("Source string to encoding is empty.");
    }
    return huffmanTree_;
}

AssociativeArray<char, List<bool>> &HuffmanCode::getTable() {
    if (string_.empty()) {
        throw std::logic_error("Source string to encoding is empty.");
    }
    return table_;
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

double HuffmanCode::getCompressionRatio() {
    if (!string_.empty() && !encodedString_.empty())
        return string_.size() / encodedString_.size();
    else
        throw std::logic_error("It is impossible to calculate the compression ratio.");
}

void HuffmanCode::constructingTheTable() {

    auto current = huffmanTree_.head_;
    if (current->nextLeft_ == nullptr && current->nextRight_ == nullptr) {
        table_.insert(current->symbol_, List<bool>(true));
        return;
    }

    Stack<bool> bitStack;
    int visited = 1;
    int mustVisit = huffmanTree_.size;
    while (true) {
        if (current->nextLeft_ != nullptr) {
            if (!current->nextLeft_->haveBeenVisited_) {
                bitStack.push(true);
                current = current->nextLeft_;
                ++visited;
            }
        } else if (current->nextRight_ != nullptr) {
            if (!current->nextRight_->haveBeenVisited_) {
                bitStack.push(false);
                current = current->nextRight_;
                ++visited;
            }
        } else {
            table_.insert(current->symbol_, bitStack.getAllData());
            bitStack.pop();
            current->haveBeenVisited_ = true;
            current = current->parent_;
            if (visited == mustVisit) {
                break;
            }
        }

    }

}

void HuffmanCode::constructingTheEncodedString() {
    for (int i = 0; i < string_.size(); ++i) {
        std::string newSubStringOfBits;
        auto charWithCodeBits = table_.find(string_[i]);
        auto bitsList = charWithCodeBits->getValue();
        for (auto it = bitsList.begin(); it != bitsList.end(); ++it) {

            char bit;
            if (*it == 0) bit = '0';
            else bit = '1';

            newSubStringOfBits.push_back(bit);
        }

        encodedString_ += newSubStringOfBits;
        encodedString_.push_back('-');
    }
}




