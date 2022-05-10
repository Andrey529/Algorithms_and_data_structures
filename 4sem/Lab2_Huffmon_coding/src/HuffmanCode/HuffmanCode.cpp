#ifndef LAB2_HUFFMON_CODING_HUFFMANCODE_CPP
#define LAB2_HUFFMON_CODING_HUFFMANCODE_CPP

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
        return static_cast<double>(this->getCountBytesByTheSourceString()) /
               static_cast<double>(this->getCountBytesByTheEncodedString());
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
    }
}

void HuffmanCode::encode(const std::string &str) {
    clear();
    string_ = str;
    calculateSymbolsFrequency();
    huffmanTree_.buildTree(symbolsFrequency_);
    constructingTheTable();
    constructingTheEncodedString();
}

void HuffmanCode::encode(std::string &&str) {
    clear();
    string_ = std::move(str);
    calculateSymbolsFrequency();
    huffmanTree_.buildTree(symbolsFrequency_);
    constructingTheTable();
    constructingTheEncodedString();
}

void HuffmanCode::decode(const std::string &str, const AssociativeArray<char, List<bool>> &table) {
    clear();
    table_ = table;
    encodedString_ = str;

    size_t index = 0;
    auto strSize = str.size();
    std::string subString;
    while (index != strSize) {
        subString += str[index];
        auto it = table_.createBftIterator();
        while (it->hasNext()) {
            List<bool> listFromEncodedStr = strToListBools(subString);
            List<bool> listFromTable = it->next()->getValue();
            if (listFromEncodedStr == listFromTable) {
                string_ += it.operator*().getCurrent()->getKey();
                subString = "";
            }
        }

        ++index;
    }
}

void HuffmanCode::decode(std::string &&str, const AssociativeArray<char, List<bool>> &table) {
    clear();
    table_ = table;
    encodedString_ = std::move(str);

    size_t index = 0;
    auto strSize = str.size();
    std::string subString;
    while (index != strSize) {
        subString += str[index];
        auto it = table_.createBftIterator();
        while (it->hasNext()) {
            List<bool> listFromEncodedStr = strToListBools(subString);
            List<bool> listFromTable = it->next()->getValue();
            if (listFromEncodedStr == listFromTable) {
                string_ += it.operator*().getCurrent()->getKey();
                subString = "";
            }
        }

        ++index;
    }
}

List<bool> HuffmanCode::strToListBools(const std::string &str) {
    List<bool> list;
    for (char symbol: str) {
        if (symbol == '0')
            list.pushBack(false);
        else if (symbol == '1')
            list.pushBack(true);
        else throw std::invalid_argument("Input string must have only 0 and 1 characters");
    }
    return list;
}

#endif //LAB2_HUFFMON_CODING_HUFFMANCODE_CPP
