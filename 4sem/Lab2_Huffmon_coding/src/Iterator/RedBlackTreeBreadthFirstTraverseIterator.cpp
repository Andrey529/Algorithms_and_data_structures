#ifndef LAB2_HUFFMON_CODING_REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_CPP
#define LAB2_HUFFMON_CODING_REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_CPP

#include "../../headers/Iterator/RedBlackTreeBreadthFirstTraverseIterator.h"

template<class T_key, class T_value>
RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::RedBlackTreeBreadthFirstTraverseIterator(
        RedBlackTreeBreadthFirstTraverseIterator::elemType start) {

    current_ = start;
    queue_ = std::make_unique<Queue<std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>>>();
    queue_->push(current_);

}

template<class T_key, class T_value>
typename RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::elemType
RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::getCurrent() {
    return current_;
}

template<class T_key, class T_value>
void RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::setCurrent(
        RedBlackTreeBreadthFirstTraverseIterator::elemType current) {
    current_ = current;
}

template<class T_key, class T_value>
bool RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::hasNext() {
    return ( (current_ != nullptr) && (queue_->getFront().lock() != nullptr) );
}

template<class T_key, class T_value>
typename RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::elemType
RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::next() {

    if (!hasNext()) {
        throw std::out_of_range("No more elements in red black tree search. Function next()");
    }

    current_ = queue_->getFront().lock()->data_;
    queue_->pop();  // delete current in queue

    if (!(current_->getNextLeft()->isNil()))  // set in queue childs of current
        queue_->push(current_->getNextLeft());
    if (!(current_->getNextRight()->isNil()))
        queue_->push(current_->getNextRight());

    return current_;
}

#endif //LAB2_HUFFMON_CODING_REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_CPP
