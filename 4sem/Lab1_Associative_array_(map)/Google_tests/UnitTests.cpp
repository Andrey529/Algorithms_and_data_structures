#include "gtest/gtest.h"

#include "../headers/Queue/Queue.h"
#include "../headers/List/List.h"

TEST(Queue, constructorDefault) {
    Queue<int> queue;
    ASSERT_EQ(true, queue.isEmpty());
}

TEST(Queue, constructorCopyParameters) {
    int a = 2;
    Queue<int> queue(a);
    ASSERT_EQ(1, queue.getSize());
    ASSERT_EQ(2, queue.getBack().lock()->data_);
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, constructorMoveParameters) {
    Queue<int> queue(3);
    ASSERT_EQ(1, queue.getSize());
    ASSERT_EQ(3, queue.getBack().lock()->data_);
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, constructorCopyFromAnother) {
    Queue<int> queueTemp;
    for (int i = 0; i < 5; ++i) {
        queueTemp.push(i);
    }

    Queue<int> queue(queueTemp);
    ASSERT_EQ(5, queue.getSize());
    ASSERT_EQ(queueTemp.getBack().lock()->data_ /*4*/, queue.getBack().lock()->data_);
    ASSERT_EQ(queueTemp.getFront().lock()->data_ /*0*/, queue.getFront().lock()->data_);
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, constructorCopyFromAnother1Elem) {
    Queue<int> queueTemp;
    queueTemp.push(1);

    Queue<int> queue(queueTemp);
    ASSERT_EQ(1, queue.getSize());
    ASSERT_EQ(queueTemp.getBack().lock()->data_ /*1*/, queue.getBack().lock()->data_);
    ASSERT_EQ(queueTemp.getFront().lock()->data_ /*1*/, queue.getFront().lock()->data_);
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, constructorCopyFromAnotherEmpty) {
    Queue<int> queueTemp;

    Queue<int> queue(queueTemp);
    ASSERT_EQ(0, queue.getSize());
    ASSERT_EQ(nullptr, queue.getBack().lock());
    ASSERT_EQ(nullptr, queue.getFront().lock());
}

TEST(Queue, constructorMoveFromAnother) {
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

TEST(Queue, constructorMoveFromAnotherEmpty) {
    Queue<int> queueTemp;

    Queue<int> queue(std::move(queueTemp));
    ASSERT_EQ(0, queue.getSize());
    ASSERT_EQ(nullptr, queue.getBack().lock());
    ASSERT_EQ(nullptr, queue.getFront().lock());
}

TEST(Queue, pushCopy) {
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }
    ASSERT_EQ(5, queue.getSize());
    ASSERT_EQ(4, queue.getBack().lock()->data_);
    ASSERT_EQ(0, queue.getFront().lock()->data_);
}

TEST(Queue, pushCopy2Elem) {
    Queue<int> queue(1);
    int i = 2;
    queue.push(i);

    ASSERT_EQ(2, queue.getSize());
    ASSERT_EQ(i, queue.getBack().lock()->data_);
    ASSERT_EQ(1, queue.getFront().lock()->data_);
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, pushCopyInEmpty) {
    Queue<int> queue;
    int i = 1;
    queue.push(i);
    ASSERT_EQ(1, queue.getSize());
    ASSERT_EQ(1, queue.getBack().lock()->data_);
    ASSERT_EQ(1, queue.getFront().lock()->data_);
    ASSERT_EQ(nullptr, queue.getFront().lock()->nextElem_);
}

TEST(Queue, pushMove) {
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

TEST(Queue, pushMove2Elem) {
    Queue<int> queue(1);
    queue.push(2);

    ASSERT_EQ(2, queue.getSize());
    ASSERT_EQ(2, queue.getBack().lock()->data_);
    ASSERT_EQ(1, queue.getFront().lock()->data_);
    ASSERT_EQ(nullptr, queue.getBack().lock()->nextElem_);
}

TEST(Queue, pushMoveInEmpty) {
    Queue<int> queue;
    queue.push(1);
    ASSERT_EQ(1, queue.getSize());
    ASSERT_EQ(1, queue.getBack().lock()->data_);
    ASSERT_EQ(1, queue.getFront().lock()->data_);
    ASSERT_EQ(nullptr, queue.getFront().lock()->nextElem_);
}

TEST(Queue, pop) {
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

TEST(Queue, popEmpty) {
    Queue<int> queue;
    ASSERT_ANY_THROW(queue.pop());
}

TEST(Queue, isEmptyTrue) {
    Queue<int> queue;
    ASSERT_EQ(true, queue.isEmpty());
}

TEST(Queue, isEmptyFalse) {
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }

    ASSERT_EQ(false, queue.isEmpty());
}

TEST(Queue, getSize0) {
    Queue<int> queue;
    ASSERT_EQ(0, queue.getSize());
}

TEST(Queue, getSizeNot0) {
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }
    ASSERT_EQ(5, queue.getSize());
}


TEST(List, isEmptyTrue) {
    List<int> list;
    ASSERT_EQ(true, list.isEmpty());
}

TEST(List, isEmptyFalse) {
    List<int> list(1);
    ASSERT_EQ(false, list.isEmpty());
}

TEST(List, getSize0) {
    List<int> list;
    ASSERT_EQ(0, list.getSize());
}

TEST(List, getSizeNot0) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    ASSERT_EQ(5, list.getSize());
}

TEST(List, contructorDefault) {
    List<int> list;
    ASSERT_EQ(true, list.isEmpty());
}

TEST(List, constructorCopyParameters) {
    int a = 2;
    List<int> list(a);
    ASSERT_EQ(1, list.getSize());
    ASSERT_EQ(2, list.at(0));
}

TEST(List, constructorMoveParameters) {
    List<int> list(3);
    ASSERT_EQ(1, list.getSize());
    ASSERT_EQ(3, list.at(0));
}

TEST(List, constructorCopyFromAnother) {
    List<int> listTemp;
    for (int i = 0; i < 5; ++i) {
        listTemp.pushBack(i);
    }

    List<int> list(listTemp);
    ASSERT_EQ(5, list.getSize());
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(listTemp.at(i), list.at(i));
    }
}

TEST(List, constructorCopyFromAnother1Elem) {
    List<int> listTemp;
    listTemp.pushBack(1);

    List<int> list(listTemp);
    ASSERT_EQ(1, list.getSize());
    ASSERT_EQ(listTemp.at(0), list.at(0));
}

TEST(List, constructorCopyFromAnotherEmpty) {
    List<int> listTemp;

    List<int> list(listTemp);
    ASSERT_EQ(0, list.getSize());
}

TEST(List, constructorMoveFromAnother) {
    List<int> listTemp;
    for (int i = 0; i < 5; ++i) {
        listTemp.pushBack(i);
    }

    List<int> list(std::move(listTemp));
    ASSERT_EQ(5, list.getSize());
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
}

TEST(List, constructorMoveFromAnotherEmpty) {
    List<int> listTemp;

    List<int> list(std::move(listTemp));
    ASSERT_EQ(0, list.getSize());
}


TEST(List, pushBackCopy) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    ASSERT_EQ(5, list.getSize());

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
}

TEST(List, pushBackCopy2Elem) {
    List<int> list(1);
    int i = 2;
    list.pushBack(i);

    ASSERT_EQ(2, list.getSize());
    ASSERT_EQ(i, list.at(1));
    ASSERT_EQ(1, list.at(0));
}

TEST(List, pushBackCopyInEmpty) {
    List<int> list;
    int i = 1;
    list.pushBack(i);
    ASSERT_EQ(1, list.getSize());
    ASSERT_EQ(1, list.at(0));
}

TEST(List, pushBackMove) {
    List<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    ASSERT_EQ(5, list.getSize());
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
}

TEST(List, pushBackMove2Elem) {
    List<int> list(1);
    list.pushBack(2);

    ASSERT_EQ(2, list.getSize());
    ASSERT_EQ(2, list.at(1));
    ASSERT_EQ(1, list.at(0));
}

TEST(List, pushBackMoveInEmpty) {
    List<int> list;
    list.pushBack(1);
    ASSERT_EQ(1, list.getSize());
    ASSERT_EQ(1, list.at(0));
}


TEST(List, pushFrontCopy) {
    List<int> list;
    for (int i = 4; i >= 0; --i) {
        list.pushFront(i);
    }
    ASSERT_EQ(5, list.getSize());

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
}

TEST(List, pushFrontCopy2Elem) {
    List<int> list(1);
    int i = 0;
    list.pushFront(i);

    ASSERT_EQ(2, list.getSize());
    ASSERT_EQ(1, list.at(1));
    ASSERT_EQ(0, list.at(0));
}

TEST(List, pushFrontCopyInEmpty) {
    List<int> list;
    int i = 1;
    list.pushFront(i);
    ASSERT_EQ(1, list.getSize());
    ASSERT_EQ(1, list.at(0));
}

TEST(List, pushFrontMove) {
    List<int> list;
    list.pushFront(4);
    list.pushFront(3);
    list.pushFront(2);
    list.pushFront(1);
    list.pushFront(0);
    ASSERT_EQ(5, list.getSize());
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
}

TEST(List, pushFrontMove2Elem) {
    List<int> list(1);
    list.pushFront(0);

    ASSERT_EQ(2, list.getSize());
    ASSERT_EQ(1, list.at(1));
    ASSERT_EQ(0, list.at(0));
}

TEST(List, pushFrontMoveInEmpty) {
    List<int> list;
    list.pushFront(1);
    ASSERT_EQ(1, list.getSize());
    ASSERT_EQ(1, list.at(0));
}

TEST(List, popBack) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    ASSERT_NO_THROW(list.popBack());
    ASSERT_EQ(4, list.getSize());
    for (int i = 0; i < 4; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
}

TEST(List, popBackEmpty) {
    List<int> list;
    ASSERT_ANY_THROW(list.popBack());
}

TEST(List, popFront) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    ASSERT_NO_THROW(list.popFront());
    ASSERT_EQ(4, list.getSize());
    for (int i = 1; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i-1));
    }
}

TEST(List, popFrontEmpty) {
    List<int> list;
    ASSERT_ANY_THROW(list.popFront());
}

TEST(List, insertInBegin) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    int a = -1;
    ASSERT_NO_THROW(list.insert(a, 0));
    for (int i = -1; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i + 1));
    }
}

TEST(List, insertInEnd) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    int a = 5;
    ASSERT_NO_THROW(list.insert(a, 4));
    for (int i = 0; i < 4; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
    ASSERT_EQ(5, list.at(4));
    ASSERT_EQ(4, list.at(5));
}

TEST(List, insertInMiddle) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    int a = 10;
    ASSERT_NO_THROW(list.insert(a, 2));
    ASSERT_EQ(0, list.at(0));
    ASSERT_EQ(1, list.at(1));
    ASSERT_EQ(10, list.at(2));
    ASSERT_EQ(2, list.at(3));
    ASSERT_EQ(3, list.at(4));
    ASSERT_EQ(4, list.at(5));
}

TEST(List, insertInEmpty) {
    List<int> list;
    int a = 10;
    ASSERT_NO_THROW(list.insert(a, 0));
    ASSERT_EQ(10, list.at(0));
    ASSERT_EQ(1, list.getSize());
}

TEST(List, at){
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.pushBack(i);
    }
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i, list.at(i));
    }
}

TEST(List, atEmpty){
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        ASSERT_ANY_THROW(list.at(i));
    }
}
