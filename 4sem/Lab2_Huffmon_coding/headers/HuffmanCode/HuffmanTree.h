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

        using elemType = std::shared_ptr<ElemOfHuffmanTree>;

        elemType parent_;
        elemType nextLeft_;
        elemType nextRight_;

//        ElemOfHuffmanTree() : symbol_(), frequency_() { }
        ElemOfHuffmanTree(const char &symbol, const size_t &frequency, elemType parent = nullptr,
                          elemType nextLeft = nullptr, elemType nextRight = nullptr)
                          : symbol_(symbol), frequency_(frequency), parent_(parent), nextLeft_(nextLeft), nextRight_(nextRight) {}

        bool operator<(const ElemOfHuffmanTree &elem) const {
            return frequency_ < elem.frequency_;
        }

    };

    struct ElemOfHuffmanTreeComparator {
        bool
        operator()(const std::shared_ptr<ElemOfHuffmanTree> &elem1, const std::shared_ptr<ElemOfHuffmanTree> &elem2) {
            return elem1->frequency_ < elem2->frequency_;
        }
    };

    using elemType = std::shared_ptr<ElemOfHuffmanTree>;
    elemType head_;
    List<elemType> leafsList_;

public:
    HuffmanTree() : head_(), leafsList_() {}

    void buildTree(AssociativeArray<char, size_t> &symbolsFrequency) {
        auto it = symbolsFrequency.createDftIterator();
        while (it->hasNext()) {
            auto symbolWithFrequency = it->next();
            elemType newElem = std::make_shared<ElemOfHuffmanTree>(symbolWithFrequency->getKey(),
                                                                   symbolWithFrequency->getValue());
            leafsList_.pushBack(newElem);
        }
        leafsList_.sort(ElemOfHuffmanTreeComparator());

//        auto listSize = leafsList_.getSize();
        bool flagFirstEntry = true;
        while (!leafsList_.isEmpty()) {
            auto elem0 = leafsList_.at(0);
            auto elem1 = leafsList_.at(1);
//            if (flagFirstEntry) {
//                auto
//            } else {
//
//            }

        }

//        for (int i = 0; i < listSize; ++i) {
//            auto elem = leafsList_.at(i);
//            std::cout << elem->symbol_ << ' ' << elem->frequency_ << std::endl;
//        }

//        std::cout << leafsList_;
    }
};

#endif //LAB2_HUFFMON_CODING_HUFFMANTREE_H
