#ifndef LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_CPP
#define LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_CPP

#include "../../headers/iterator/RedBlackTreeBreadthFirstTraverseIterator.h"

template<class T_key, class T_value>
RedBlackTreeBreadthFirstTraverseIterator<T_key, T_value>::RedBlackTreeBreadthFirstTraverseIterator(
        RedBlackTreeBreadthFirstTraverseIterator::elemType start) {

    current_ = start;
    queue_ = std::make_unique<Queue<std::shared_ptr<ElemOfRedBlackTree<T_key, T_value>>>>();
    queue_->push(current_);

//    std::unique_ptr<Queue<std::shared_ptr<ElemOfRedBlackTree<int, int>>>> queue;
//    queue = std::make_unique<Queue<std::shared_ptr<ElemOfRedBlackTree<int, int>>>>();
//    queue->push(std::make_shared<ElemOfRedBlackTree<int, int>>(1,1,COLOR::RED));

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

//    if (current_->isNil()) {
//        std::cout << "Nil";
//    }

    if (!(current_->getNextLeft()->isNil()))  // set in queue childs of current
        queue_->push(current_->getNextLeft());
    if (!(current_->getNextRight()->isNil()))
        queue_->push(current_->getNextRight());

//    if (current_->getNextLeft() != nullptr)
//    if (current_->getNextRight() != nullptr)

    return current_;

//    return *(current_.get()); // return current
//    return ElemOfRedBlackTree<T_key, T_value>();
}


#endif //LAB1_ASSOCIATIVE_ARRAY__MAP__REDBLACKTREEBREADTHFIRSTTRAVERSEITERATOR_CPP
