#ifndef LAB2_HUFFMON_CODING_HUFFMANTREE_H
#define LAB2_HUFFMON_CODING_HUFFMANTREE_H

#include <memory>
#include "../List/List.h"
#include "../AssociativeArray/AssociativeArray.h"

class HuffmanTree {
public:
    enum class TypeElem {
        DEFAULT, // have symbol with its frequency
        SPECIAL  // need to build tree
    };

    struct ElemOfHuffmanTree {
        char symbol_;
        size_t frequency_;
        TypeElem typeElem_;
        bool haveBeenVisited_;

        using elemType = std::shared_ptr<ElemOfHuffmanTree>;

        elemType parent_;
        elemType nextLeft_;
        elemType nextRight_;

        ElemOfHuffmanTree(const char &symbol, const size_t &frequency, const TypeElem &typeElem,
                          const bool &haveBeenVisited, const elemType &parent = nullptr,
                          const elemType &nextLeft = nullptr, const elemType &nextRight = nullptr)
                : symbol_(symbol), frequency_(frequency), typeElem_(typeElem), haveBeenVisited_(haveBeenVisited),
                parent_(parent), nextLeft_(nextLeft), nextRight_(nextRight) {}

        bool operator<(const ElemOfHuffmanTree &elem) const {
            return frequency_ < elem.frequency_;
        }

    };

    struct ElemOfHuffmanTreeComparator {
        bool
        operator()(const std::shared_ptr<ElemOfHuffmanTree> &elem1, const std::shared_ptr<ElemOfHuffmanTree> &elem2) {
            if (elem1->frequency_ < elem2->frequency_)
                return true;
            else if (elem1->frequency_ > elem2->frequency_) {
                return false;
            } else {
                if ((elem1->typeElem_ == TypeElem::DEFAULT) && (elem2->typeElem_ == TypeElem::SPECIAL))
                    return false;
                else
                    return true;
            }
        }
    };

    using elemType = std::shared_ptr<ElemOfHuffmanTree>;
    elemType head_;
    int size;
public:
    HuffmanTree() : head_(), size(0) {}

    void buildTree(AssociativeArray<char, size_t> &symbolsFrequency);

    void clear();
};


#endif //LAB2_HUFFMON_CODING_HUFFMANTREE_H
