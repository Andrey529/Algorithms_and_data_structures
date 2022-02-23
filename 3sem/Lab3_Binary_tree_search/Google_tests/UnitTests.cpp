#include "gtest/gtest.h"

#include "../headers/binaryTreeSearch/binaryTreeSearch.h"

class TestBinaryTreeSearch : public ::testing::Test {
protected:
    binaryTreeSearch<int> *treeOfInts;
public:
    TestBinaryTreeSearch() {
        this->treeOfInts = new binaryTreeSearch<int>;
    }
    ~TestBinaryTreeSearch() {
        delete this->treeOfInts;
    }

    void setUpNotEmptyTree(){
        treeOfInts->insert(10);
        treeOfInts->insert(8);
        treeOfInts->insert(13);
        treeOfInts->insert(5);
        treeOfInts->insert(12);
        treeOfInts->insert(17);
    }
    void setUpEmptyTree() { }
};

TEST_F(TestBinaryTreeSearch, insertInEmptyTree) {
    setUpEmptyTree();
    treeOfInts->insert(5);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, insertInNotEmptyTree1) {
    setUpNotEmptyTree();
    treeOfInts->insert(2);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),2);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, insertInNotEmptyTree2) {
    setUpNotEmptyTree();
    treeOfInts->insert(9);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),9);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, insertInNotEmptyTree3) {
    setUpNotEmptyTree();
    treeOfInts->insert(11);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),11);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, containsInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(treeOfInts->contains(5));
}

TEST_F(TestBinaryTreeSearch, containsRootInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(10));
    GTEST_ASSERT_EQ(treeOfInts->contains(10), true);
}

TEST_F(TestBinaryTreeSearch, containsHaveChildInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(8));
    GTEST_ASSERT_EQ(treeOfInts->contains(8), true);
}

TEST_F(TestBinaryTreeSearch, containsLeafInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(12));
    GTEST_ASSERT_EQ(treeOfInts->contains(12), true);
}

TEST_F(TestBinaryTreeSearch, containsBadInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(100));
    GTEST_ASSERT_EQ(treeOfInts->contains(100), false);
}

TEST_F(TestBinaryTreeSearch, removeInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(treeOfInts->remove(10));
}

TEST_F(TestBinaryTreeSearch, removeHeadInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(10));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeWhen1ChildInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(8));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeWhen2ChildInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(13));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeTreeLeafInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(12));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeBadInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_ANY_THROW(treeOfInts->remove(7));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, isEmptyInEmptyTree) {
    setUpEmptyTree();
    GTEST_ASSERT_EQ(treeOfInts->isEmpty(), true);
}

TEST_F(TestBinaryTreeSearch, isEmptyInNotEmptyTree) {
    setUpNotEmptyTree();
    GTEST_ASSERT_EQ(treeOfInts->isEmpty(), false);
}

TEST_F(TestBinaryTreeSearch, breadthIteratorInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator());
}

TEST_F(TestBinaryTreeSearch, breadthIteratorInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator());

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, depthIteratorInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorDepth = treeOfInts->create_dft_iterator());
}

TEST_F(TestBinaryTreeSearch, depthIteratorInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorDepth = treeOfInts->create_dft_iterator());

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorDepth = treeOfInts->create_dft_iterator();

    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorDepth->hasNext(), false);
}

class TestQueue : public ::testing::Test {
protected:
    queue<int> *Queue;
public:
    TestQueue() {
        this->Queue = new queue<int>;
    }
    ~TestQueue() {
        delete this->Queue;
    }

    void setUpNotEmptyQueue(){
        Queue->push(1);
        Queue->push(2);
        Queue->push(3);
        Queue->push(4);
        Queue->push(5);
    }
    void setUpEmptyQueue() { }
};

TEST_F(TestQueue, isEmptyInEmptyQueue) {
    setUpEmptyQueue();
    GTEST_ASSERT_EQ(this->Queue->isEmpty(), true);
}

TEST_F(TestQueue, isEmptyInNotEmptyQueue) {
    setUpNotEmptyQueue();
    GTEST_ASSERT_EQ(this->Queue->isEmpty(), false);
}

TEST_F(TestQueue, getSizeInEmptyQueue) {
    setUpEmptyQueue();
    GTEST_ASSERT_EQ(this->Queue->getSize(), 0);
}

TEST_F(TestQueue, getSizeInNotEmptyQueue) {
    setUpNotEmptyQueue();
    GTEST_ASSERT_EQ(this->Queue->getSize(), 5);
}

TEST_F(TestQueue, getBackInEmptyQueue) {
    setUpEmptyQueue();
    GTEST_ASSERT_EQ(this->Queue->getBack(), nullptr);
}

TEST_F(TestQueue, getBackInNotEmptyQueue) {
    setUpNotEmptyQueue();
    GTEST_ASSERT_EQ(*(this->Queue->getBack()->getData()), 5);
}

TEST_F(TestQueue, getFrontInEmptyQueue) {
    setUpEmptyQueue();
    GTEST_ASSERT_EQ(this->Queue->getFront(), nullptr);
}

TEST_F(TestQueue, getFrontInNotEmptyQueue) {
    setUpNotEmptyQueue();
    GTEST_ASSERT_EQ(*(this->Queue->getFront()->getData()), 1);
}

TEST_F(TestQueue, popInEmptyQueue) {
    setUpEmptyQueue();
    ASSERT_ANY_THROW(this->Queue->pop());
}

TEST_F(TestQueue, popInNotEmptyQueue) {
    setUpNotEmptyQueue();

    ASSERT_NO_THROW(this->Queue->pop());
    GTEST_ASSERT_EQ(*(this->Queue->getFront()->getData()),2);
    GTEST_ASSERT_EQ(this->Queue->getSize(),4);
}

TEST_F(TestQueue, pushByDefaultInEmptyQueue) {
    setUpEmptyQueue();
    this->Queue->push();
    GTEST_ASSERT_EQ(*(this->Queue->getFront()->getData()),0);
    GTEST_ASSERT_EQ(this->Queue->getSize(),1);
}

TEST_F(TestQueue, pushByDefaultInNotEmptyQueue) {
    setUpNotEmptyQueue();
    this->Queue->push();
    GTEST_ASSERT_EQ(*(this->Queue->getBack()->getData()),0);
    GTEST_ASSERT_EQ(this->Queue->getSize(),6);
}

TEST_F(TestQueue, pushInEmptyQueue) {
    setUpEmptyQueue();
    this->Queue->push(100);
    GTEST_ASSERT_EQ(*(this->Queue->getFront()->getData()),100);
    GTEST_ASSERT_EQ(this->Queue->getSize(),1);
}

TEST_F(TestQueue, pushInNotEmptyQueue) {
    setUpNotEmptyQueue();
    this->Queue->push(100);
    GTEST_ASSERT_EQ(*(this->Queue->getBack()->getData()),100);
    GTEST_ASSERT_EQ(this->Queue->getSize(),6);
}

TEST_F(TestQueue, pushElementOfQueueInEmptyQueue) {
    setUpEmptyQueue();
    auto *newElem = new elemOfQueue<int>(100);
    this->Queue->push(newElem);
    GTEST_ASSERT_EQ(*(this->Queue->getFront()->getData()),100);
    GTEST_ASSERT_EQ(this->Queue->getSize(),1);
}

TEST_F(TestQueue, pushElementOfQueueInNotEmptyQueue) {
    setUpNotEmptyQueue();
    auto *newElem = new elemOfQueue<int>(100);
    this->Queue->push(newElem);
    GTEST_ASSERT_EQ(*(this->Queue->getBack()->getData()),100);
    GTEST_ASSERT_EQ(this->Queue->getSize(),6);
}


class TestStack : public ::testing::Test {
protected:
    stack<int> *Stack;
public:
    TestStack() {
        this->Stack = new stack<int>;
    }
    ~TestStack() {
        delete this->Stack;
    }

    void setUpNotEmptyStack(){
        Stack->push(1);
        Stack->push(2);
        Stack->push(3);
        Stack->push(4);
        Stack->push(5);
    }
    void setUpEmptyStack() { }
};

TEST_F(TestStack, isEmptyInEmptyStack) {
    setUpEmptyStack();
    GTEST_ASSERT_EQ(this->Stack->isEmpty(), true);
}

TEST_F(TestStack, isEmptyInNotEmptyStack) {
    setUpNotEmptyStack();
    GTEST_ASSERT_EQ(this->Stack->isEmpty(), false);
}

TEST_F(TestStack, getSizeInEmptyStack) {
    setUpEmptyStack();
    GTEST_ASSERT_EQ(this->Stack->getSize(), 0);
}

TEST_F(TestStack, getSizeInNotEmptyStack) {
    setUpNotEmptyStack();
    GTEST_ASSERT_EQ(this->Stack->getSize(), 5);
}

TEST_F(TestStack, getBackInEmptyStack) {
    setUpEmptyStack();
    GTEST_ASSERT_EQ(this->Stack->getBack(), nullptr);
}

TEST_F(TestStack, getBackInNotEmptyStack) {
    setUpNotEmptyStack();
    GTEST_ASSERT_EQ(*(this->Stack->getBack()->getData()), 1);
}

TEST_F(TestStack, getFrontInEmptyStack) {
    setUpEmptyStack();
    GTEST_ASSERT_EQ(this->Stack->getFront(), nullptr);
}

TEST_F(TestStack, getFrontInNotEmptyStack) {
    setUpNotEmptyStack();
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()), 5);
}

TEST_F(TestStack, popInEmptyStack) {
    setUpEmptyStack();
    ASSERT_ANY_THROW(this->Stack->pop());
}

TEST_F(TestStack, popInNotEmptyStack) {
    setUpNotEmptyStack();

    ASSERT_NO_THROW(this->Stack->pop());
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()),4);
    GTEST_ASSERT_EQ(this->Stack->getSize(),4);
}

TEST_F(TestStack, pushByDefaultInEmptyStack) {
    setUpEmptyStack();
    this->Stack->push();
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()),0);
    GTEST_ASSERT_EQ(this->Stack->getSize(),1);
}

TEST_F(TestStack, pushByDefaultInNotEmptyStack) {
    setUpNotEmptyStack();
    this->Stack->push();
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()),0);
    GTEST_ASSERT_EQ(this->Stack->getSize(),6);
}

TEST_F(TestStack, pushInEmptyStack) {
    setUpEmptyStack();
    this->Stack->push(100);
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()),100);
    GTEST_ASSERT_EQ(this->Stack->getSize(),1);
}

TEST_F(TestStack, pushInNotEmptyStack) {
    setUpNotEmptyStack();
    this->Stack->push(100);
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()),100);
    GTEST_ASSERT_EQ(this->Stack->getSize(),6);
}

TEST_F(TestStack, pushElementOfStackInEmptyStack) {
    setUpEmptyStack();
    auto *newElem = new elemOfStack<int>(100);
    this->Stack->push(newElem);
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()),100);
    GTEST_ASSERT_EQ(this->Stack->getSize(),1);
}

TEST_F(TestStack, pushElementOfStackInNotEmptyStack) {
    setUpNotEmptyStack();
    auto *newElem = new elemOfStack<int>(100);
    this->Stack->push(newElem);
    GTEST_ASSERT_EQ(*(this->Stack->getFront()->getData()),100);
    GTEST_ASSERT_EQ(this->Stack->getSize(),6);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}