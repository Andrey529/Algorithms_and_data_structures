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

//HuffmanTree &HuffmanCode::getHuffmanTree() {
//    if (string_.empty()) {
//        throw std::logic_error("Source string to encoding is empty.");
//    }
//    return huffmanTree_;
//}

AssociativeArray<char, List<bool>> &HuffmanCode::getTable() {
    if (string_.empty()) {
        throw std::logic_error("Source string to encoding is empty.");
    }
    return table_;
}

size_t HuffmanCode::getCountBytesByTheSourceString() const {
    return string_.size() * sizeof(char) * 8;
}

size_t HuffmanCode::getCountBytesByTheEncodedString() const {
    return encodedString_.size() * sizeof(char);
}

void HuffmanCode::clear() {
    string_ = "";
    encodedString_ = "";
    symbolsFrequency_.clear();
    huffmanTree_.clear();
    table_.clear();
}

double HuffmanCode::getCompressionRatio() {
    if (!string_.empty() && !encodedString_.empty())
        return static_cast<double>(this->getCountBytesByTheSourceString()) / static_cast<double>(this->getCountBytesByTheEncodedString());
    else
        throw std::logic_error("It is impossible to calculate the compression ratio.");
}

void HuffmanCode::constructingTheTable() {

    auto current = huffmanTree_.head_;
    if (current->nextLeft_ == nullptr && current->nextRight_ == nullptr) {
        table_.insert(current->symbol_, List<bool>(true));
        return;
    }

    List<bool> bitList;
    while (true) {
        if (current->nextLeft_ != nullptr && !current->nextLeft_->haveBeenVisited_) {
            bitList.pushBack(true);
            current = current->nextLeft_;
        } else if (current->nextRight_ != nullptr && !current->nextRight_->haveBeenVisited_) {
            bitList.pushBack(false);
            current = current->nextRight_;
        } else {
            if (current->typeElem_ == HuffmanTree::TypeElem::DEFAULT) {
                table_.insert(current->symbol_, bitList);
            }
            current->haveBeenVisited_ = true;
            if (current == huffmanTree_.head_) break;
            bitList.popBack();
            current = current->parent_;
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




