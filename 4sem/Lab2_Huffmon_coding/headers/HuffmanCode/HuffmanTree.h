#ifndef LAB2_HUFFMON_CODING_HUFFMANTREE_H
#define LAB2_HUFFMON_CODING_HUFFMANTREE_H

#include <memory>
#include "../List/List.h"
#include "../AssociativeArray/AssociativeArray.h"
class HuffmanTree {
private:
    struct ElemOfHuffmanTree {
        char symbol_;
        size_t frequency_;

        std::shared_ptr<ElemOfHuffmanTree> parent_;
        std::shared_ptr<ElemOfHuffmanTree> nextLeft_;
        std::shared_ptr<ElemOfHuffmanTree> nextRight_;

        ElemOfHuffmanTree() : symbol_(), frequency_() { }
        ElemOfHuffmanTree(const char &symbol, const size_t &frequency) : symbol_(symbol), frequency_(frequency) { }
    };

    using elemType = std::shared_ptr<ElemOfHuffmanTree>;
    elemType head_;
    List<elemType> leafsList_;

public:
    explicit HuffmanTree(AssociativeArray<char, size_t> &symbolsFrequency) {

        auto it = symbolsFrequency.createDftIterator();
        while (it->hasNext()) {
            auto symbolWithFrequency = it->next();
            elemType newElem = std::make_shared<ElemOfHuffmanTree>(symbolWithFrequency->getKey(), symbolWithFrequency->getValue());
            leafsList_.pushBack(newElem);
        }


    }
};

#endif //LAB2_HUFFMON_CODING_HUFFMANTREE_H
