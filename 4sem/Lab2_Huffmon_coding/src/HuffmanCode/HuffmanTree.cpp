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

        std::shared_ptr<ElemOfHuffmanTree> leftElem;
        std::shared_ptr<ElemOfHuffmanTree> rightElem;

        if (leafsList.getSize() > 2) {
            if (leafsList.at(1)->frequency_ + leafsList.at(2)->frequency_ <
                leafsList.at(0)->frequency_ + leafsList.at(1)->frequency_) {
                leftElem = leafsList.at(1);
                rightElem = leafsList.at(2);

                leafsList.remove(1);
                leafsList.remove(1);
            } else {
                leftElem = leafsList.at(0);
                rightElem = leafsList.at(1);
                leafsList.popFront();
                leafsList.popFront();
            }
        } else {
            leftElem = leafsList.at(0);
            rightElem = leafsList.at(1);
            leafsList.popFront();
            leafsList.popFront();
        }

        elemType newElem;
        newElem = std::make_shared<ElemOfHuffmanTree>('@', leftElem->frequency_ + rightElem->frequency_,
                                                      TypeElem::SPECIAL, false,
                                                      nullptr, leftElem, rightElem);
        leftElem->parent_ = newElem;
        rightElem->parent_ = newElem;
        leafsList.pushFront(newElem);
        ++size;
    }
    head_ = leafsList.at(0);
    leafsList.popFront();
}


void HuffmanTree::clear() {
    head_ = nullptr;
    size = 0;
}