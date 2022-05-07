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

        ElemOfHuffmanTree(const char &symbol, const size_t &frequency, const elemType &parent = nullptr,
                          const elemType &nextLeft = nullptr, const elemType &nextRight = nullptr)
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

    void buildTree(AssociativeArray<char, size_t> &symbolsFrequency);
    void clear();
};




#endif //LAB2_HUFFMON_CODING_HUFFMANTREE_H
