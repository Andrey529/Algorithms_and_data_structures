#include "gtest/gtest.h"
#include "../headers/listOfInts.h"

TEST(isEmpty, listIsEmpty){
    listOfInts list;
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(isEmpty, listNotEmpty){
    listOfInts list;
    for(int i = 0; i < 3; i++){
        list.push_back(i);
    }
    ASSERT_EQ(list.isEmpty(), false);
}

TEST(push_back,listEmpty){
    listOfInts list;
    list.push_back(100);
    ASSERT_EQ(list.at(0),100);
    ASSERT_EQ(list.get_size(),1); // checks that the list has only 1 element
}

TEST(push_back,listNotEmpty){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }

    for (int i = 0; i < 5; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),5); // checks that the list has 5 elements
}

TEST(push_front,listEmpty){
    listOfInts list;
    list.push_front(100);

    ASSERT_EQ(list.at(0),100);
    ASSERT_EQ(list.get_size(),1); // checks that the list has only 1 element
}

TEST(push_front,listNotEmpty){
    listOfInts list;
    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }

    list.push_front(100);

    ASSERT_EQ(list.at(0),100);
    for (int i = 0; i < 5; i++){
        ASSERT_EQ(list.at(i+1),i);
    }
    ASSERT_EQ(list.get_size(),6); // checks that the list has 6 elements
}

TEST(pop_back, listEmpty){
    listOfInts list;
    ASSERT_ANY_THROW(list.pop_back());
    ASSERT_EQ(list.isEmpty(),true);
}

TEST(pop_back,listNotEmpty){
    listOfInts list;
    for( int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_NO_THROW(list.pop_back());

    for(int i = 0; i < 4; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),4);
}

TEST(pop_front, listEmpty){
    listOfInts list;
    ASSERT_ANY_THROW(list.pop_front());
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(pop_front,listNotEmpty){
    listOfInts list;
    for( int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_NO_THROW(list.pop_front());

    for (int i = 0; i < 4; i++){
        ASSERT_EQ(list.at(i),i+1);
    }
    ASSERT_EQ(list.get_size(),4);
}

TEST(insert,listEmptyIndex0){
    listOfInts list;
    ASSERT_NO_THROW(list.insert(100,0));
    ASSERT_EQ(list.at(0),100);
    ASSERT_EQ(list.get_size(),1);
}

TEST(insert,listEmptyIndex5){
    listOfInts list;
    ASSERT_NO_THROW(list.insert(100,5));
    ASSERT_EQ(list.at(0),100);
    ASSERT_EQ(list.get_size(),1);
}

TEST(insert,listNotEmptyIndex0){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_NO_THROW(list.insert(100,0));

    ASSERT_EQ(list.at(0),100);
    for (int i = 0; i < 5; i++){
        ASSERT_EQ(list.at(i+1),i);
    }
    ASSERT_EQ(list.get_size(),6);
}

TEST(insert,listNotEmptyIndexLastElement){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }


    ASSERT_NO_THROW(list.insert(100,4));

    for (int i = 0; i < 4; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.at(4),100);
    ASSERT_EQ(list.at(5),4);
    ASSERT_EQ(list.get_size(),6);
}

TEST(insert,listNotEmptyIndexNotLastAndNotBeginElement){
    listOfInts list;

    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_NO_THROW(list.insert(100,2));

    ASSERT_EQ(list.at(0),0);
    ASSERT_EQ(list.at(1),1);
    ASSERT_EQ(list.at(2),100);
    ASSERT_EQ(list.at(3),2);
    ASSERT_EQ(list.at(4),3);
    ASSERT_EQ(list.at(5),4);
    ASSERT_EQ(list.get_size(),6);

}

TEST(insert,listNotEmptyIndexMoreThanSizeList){
    listOfInts list;

    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_ANY_THROW(list.insert(100,10));

    for (int i = 0; i < 5; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),5);
}

TEST(at,listEmpty){
    listOfInts list;
    ASSERT_ANY_THROW(list.at(0));
}

TEST(at,listNotEmptyIndexGood){
    listOfInts list;

    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    ASSERT_NO_THROW(list.at(2));
    int number = list.at(2);
    ASSERT_EQ(number,2);
}

TEST(at,listNotEmptyIndexBad){
    listOfInts list;

    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    ASSERT_ANY_THROW(list.at(10));
}

TEST(get_size, listEmpty){
    listOfInts list;
    ASSERT_EQ(list.get_size(),0);
}

TEST(get_size, listNotEmpty){
    listOfInts list;
    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    ASSERT_EQ(list.get_size(),5);
}

TEST(set, listEmptyIndex0){
    listOfInts list;
    ASSERT_ANY_THROW(list.set(0,100));
}

TEST(set,listEmptyIndex10){
    listOfInts list;
    ASSERT_ANY_THROW(list.set(10,100));
}

TEST(set, listNotEmptyIndex0){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    ASSERT_NO_THROW(list.set(0,100));
    ASSERT_EQ(list.at(0),100);
    for(int i = 1; i < 5; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),5);
}

TEST(set, listNotEmptyIndexLastElement){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    ASSERT_NO_THROW(list.set(4,100));
    ASSERT_EQ(list.at(4),100);
    for(int i = 0; i < 4; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),5);
}

TEST(set, listNotEmptyIndexGreater0AndLessSizeOfList){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    ASSERT_NO_THROW(list.set(2,100));

    ASSERT_EQ(list.at(0),0);
    ASSERT_EQ(list.at(1),1);
    ASSERT_EQ(list.at(2),100);
    ASSERT_EQ(list.at(3),3);
    ASSERT_EQ(list.at(4),4);

    ASSERT_EQ(list.get_size(),5);
}

TEST(set,listNotEmptyIndexMoreThanSizeList){
    listOfInts list;

    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_ANY_THROW(list.set(100,10));

    for (int i = 0; i < 5; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),5);
}

TEST(remove, listEmptyIndex0){
    listOfInts list;
    ASSERT_ANY_THROW(list.remove(0));
}

TEST(remove,listEmptyIndex10){
    listOfInts list;
    ASSERT_ANY_THROW(list.remove(10));
}

TEST(remove, listNotEmptyIndex0){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_NO_THROW(list.remove(0));

    for(int i = 0; i < 4; i++){
        ASSERT_EQ(list.at(i),i+1);
    }
    ASSERT_EQ(list.get_size(),4);
}

TEST(remove, listNotEmptyIndexLastElement){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    ASSERT_NO_THROW(list.remove(4));

    for(int i = 0; i < 4; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),4);
}

TEST(remove, listNotEmptyIndexGreater0AndLessSizeOfList){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    ASSERT_NO_THROW(list.remove(2));

    ASSERT_EQ(list.at(0),0);
    ASSERT_EQ(list.at(1),1);
    ASSERT_EQ(list.at(2),3);
    ASSERT_EQ(list.at(3),4);

    ASSERT_EQ(list.get_size(),4);
}

TEST(remove,listNotEmptyIndexMoreThanSizeList){
    listOfInts list;

    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_ANY_THROW(list.remove(10));

    for (int i = 0; i < 5; i++){
        ASSERT_EQ(list.at(i),i);
    }
    ASSERT_EQ(list.get_size(),5);
}

TEST(clear, listEmpty){
    listOfInts list;
    list.clear();
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(clear, listNotEmpty){
    listOfInts list;
    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    list.clear();
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(reverse,listEmpty){
    listOfInts list;
    list.reverse();
    ASSERT_EQ(list.get_size(),0);
}

TEST(reverse,listNotEmpty2NElements){
    listOfInts list;
    for (int i = 0; i < 6; i++){
        list.push_back(i);
    }
    list.reverse();
    ASSERT_EQ(list.at(0),5);
    ASSERT_EQ(list.at(1),4);
    ASSERT_EQ(list.at(2),3);
    ASSERT_EQ(list.at(3),2);
    ASSERT_EQ(list.at(4),1);
    ASSERT_EQ(list.at(5),0);
}

TEST(reverse,listNotEmpty2NPlus1Elements){
    listOfInts list;
    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }
    list.reverse();
    ASSERT_EQ(list.at(0),4);
    ASSERT_EQ(list.at(1),3);
    ASSERT_EQ(list.at(2),2);
    ASSERT_EQ(list.at(3),1);
    ASSERT_EQ(list.at(4),0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}