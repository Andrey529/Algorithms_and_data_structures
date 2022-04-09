#include "gtest/gtest.h"

#include "../headers/Queue/Queue.h"

TEST(Queue, constructorDefault){
    Queue<int> queue;
    ASSERT_EQ(true, queue.isEmpty());
}

TEST(Queue, constructorCopyParameters){
    int a = 2;
    Queue<int> queue(a);
    ASSERT_EQ(1, queue.getSize());
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, constructorMoveParameters){
    Queue<int> queue(3);
    ASSERT_EQ(1, queue.getSize());
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, constructorCopyFromAnother){
    Queue<int> queueTemp;
    for (int i = 0; i < 5; ++i) {
        queueTemp.push(i);
    }

    Queue<int> queue(queueTemp);
    ASSERT_EQ(5, queue.getSize());
    ASSERT_EQ(queueTemp.getBack().lock()->data_ /*4*/, queue.getBack().lock()->data_);
    ASSERT_EQ(queueTemp.getFront().lock()->data_ /*0*/, queue.getFront().lock()->data_);
}

TEST(Queue, constructorMoveFromAnother){
    Queue<int> queueTemp;
    for (int i = 0; i < 5; ++i) {
        queueTemp.push(i);
    }

    Queue<int> queue(std::move(queueTemp));
    ASSERT_EQ(5, queue.getSize());
    ASSERT_EQ(4, queue.getBack().lock()->data_);
    ASSERT_EQ(0, queue.getFront().lock()->data_);
    ASSERT_EQ(nullptr, queueTemp.getFront().lock());
    ASSERT_EQ(nullptr, queueTemp.getBack().lock());
}

TEST(Queue, pushCopy){
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }
    ASSERT_EQ(5, queue.getSize());
    ASSERT_EQ(4, queue.getBack().lock()->data_);
    ASSERT_EQ(0, queue.getFront().lock()->data_);
}

TEST(Queue, pushMove){
    Queue<int> queue;
    queue.push(0);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    ASSERT_EQ(5, queue.getSize());
    ASSERT_EQ(4, queue.getBack().lock()->data_);
    ASSERT_EQ(0, queue.getFront().lock()->data_);
}

TEST(Queue, pop){
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }
    ASSERT_EQ(5, queue.getSize());

    ASSERT_NO_THROW(queue.pop());
    ASSERT_EQ(4, queue.getSize());
    ASSERT_EQ(4, queue.getBack().lock()->data_);
    ASSERT_EQ(1, queue.getFront().lock()->data_);
}

TEST(Queue, isEmptyTrue){
    Queue<int> queue;
    ASSERT_EQ(true, queue.isEmpty());
}

TEST(Queue, isEmptyFalse){
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }

    ASSERT_EQ(false, queue.isEmpty());
}

TEST(Queue, getSize0){
    Queue<int> queue;
    ASSERT_EQ(0, queue.getSize());
}

TEST(Queue, getSizeNot0){
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }
    ASSERT_EQ(5, queue.getSize());
}

