#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_H
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_H


#include "iterator.h"
#include "../Queue/Queue.h"
#include "../redBlackTree/elemOfRedBlackTree.h"

template<class T_key, class T_value>
class RedBlackTreeBreadthFirstTraverseIterator : public iterator<std::shared_ptr<elemOfRedBlackTree<T_key, T_value>>>{
private:
    using elemType = std::shared_ptr<elemOfRedBlackTree<T_key, T_value>>;
    using queueType = std::unique_ptr<Queue<elemType>>;
    elemType current_;
    queueType queue_;
public:
    explicit RedBlackTreeBreadthFirstTraverseIterator(elemType start = nullptr);
    ~RedBlackTreeBreadthFirstTraverseIterator() = default;

    elemType getCurrent() override;
    void setCurrent(elemType current) override;

    elemType next() override;
    bool hasNext() override;
};


#include "../../src/iterator/RedBlackTreeBreadthFirstTraverseIterator.cpp"

#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_H
