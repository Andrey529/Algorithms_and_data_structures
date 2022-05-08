#include "../../headers/HuffmanCode/HuffmanTree.h"

void HuffmanTree::buildTree(AssociativeArray<char, size_t> &symbolsFrequency) {
    List<elemType> leafsList;

    auto it = symbolsFrequency.createDftIterator();
    while (it->hasNext()) {
        auto symbolWithFrequency = it->next();
        elemType newElem = std::make_shared<ElemOfHuffmanTree>(symbolWithFrequency->getKey(),
                                                               symbolWithFrequency->getValue(),
                                                               TypeElem::DEFAULT, false);
        leafsList.pushBack(newElem);
        ++size;
    }

    while (leafsList.getSize() != 1) {
        leafsList.sort(ElemOfHuffmanTreeComparator());

        auto leftElem = leafsList.at(0);
        auto rightElem = leafsList.at(1);
        leafsList.popFront();
        leafsList.popFront();

        elemType newElem;
        newElem = std::make_shared<ElemOfHuffmanTree>('@', leftElem->frequency_ + rightElem->frequency_,
                                                      TypeElem::SPECIAL, false,
                                                      nullptr, leftElem, rightElem);
        leftElem->parent_ = newElem;
        rightElem->parent_ = newElem;
        leafsList.pushBack(newElem);
        ++size;
    }
    head_ = leafsList.at(0);
    leafsList.popFront();
}


void HuffmanTree::clear() {
    head_ = nullptr;
    size = 0;
}