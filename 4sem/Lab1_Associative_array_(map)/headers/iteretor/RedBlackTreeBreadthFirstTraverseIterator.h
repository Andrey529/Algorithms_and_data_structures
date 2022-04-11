#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_H


#include "iterator.h"
#include "../Queue/Queue.h"
#include "../redBlackTree/elemOfRedBlackTree.h"

template<class T_key, class T_value>
class RedBlackTreeBreadthFirstTraverseIterator : public iterator<T_key>{
private:
    using elemType = std::shared_ptr<elemOfRedBlackTree<T_key, T_value>>;
    using queueType = std::unique_ptr<Queue<elemOfRedBlackTree<T_key, T_value>>>;
    elemType current_;
    queueType queue_;
public:
    RedBlackTreeBreadthFirstTraverseIterator(elemType start = nullptr);
    ~RedBlackTreeBreadthFirstTraverseIterator() = default;

    elemType getCurrent();
    void setCurrent(elemType current);

    elemOfRedBlackTree<T_key, T_value> next() override;
    bool hasNext() override;

//    binaryTreeSearchBreadthFirstTraverseIterator(elemOfBinaryTreeSearch<T> *start = nullptr);
//    ~binaryTreeSearchBreadthFirstTraverseIterator() = default;
//
//    elemOfBinaryTreeSearch<T> *getCurrent() const;
//    void setCurrent(elemOfBinaryTreeSearch<T> *current);
//
//    elemOfBinaryTreeSearch<T> next() override;
//    bool hasNext() override;
};

template<class T_key, class T_value>
RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::RedBlackTreeBreadthFirstTraverseIterator(
        RedBlackTreeBreadthFirstTraverseIterator::elemType start) {

}

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_H
