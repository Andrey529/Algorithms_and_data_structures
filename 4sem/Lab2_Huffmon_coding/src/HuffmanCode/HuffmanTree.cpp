#include "../../headers/HuffmanCode/HuffmanTree.h"

void HuffmanTree::buildTree(AssociativeArray<char, size_t> &symbolsFrequency) {
    auto it = symbolsFrequency.createDftIterator();
    while (it->hasNext()) {
        auto symbolWithFrequency = it->next();
        elemType newElem = std::make_shared<ElemOfHuffmanTree>(symbolWithFrequency->getKey(),
                                                               symbolWithFrequency->getValue());
        leafsList_.pushBack(newElem);
    }

    while (leafsList_.getSize() != 1) {
        leafsList_.sort(ElemOfHuffmanTreeComparator());

        auto leftElem = leafsList_.at(0);
        auto rightElem = leafsList_.at(1);
        leafsList_.popFront();
        leafsList_.popFront();

        elemType newElem = std::make_shared<ElemOfHuffmanTree>('@', leftElem->frequency_ + rightElem->frequency_, nullptr, leftElem, rightElem);
        leftElem->parent_ = newElem;
        rightElem->parent_ = newElem;
        leafsList_.pushBack(newElem);
    }
    head_ = leafsList_.at(0);
    leafsList_.popFront();
}


void HuffmanTree::clear() {
    leafsList_.clear();
    head_ = nullptr;
}