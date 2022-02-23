#include "gtest/gtest.h"
#include "../src/functions.cpp"

class TestSortingFunctionsOfArrayInts : public ::testing::Test {
protected:
    int *randomArrayOfInts;
    int *notRandomArrayOfInts;
    int dataSize;
    int arraySize;
public:
    TestSortingFunctionsOfArrayInts() {
        this->randomArrayOfInts = nullptr;
        this->notRandomArrayOfInts = nullptr;
        this->arraySize = 0;
        this->dataSize = 0;
    }
    ~TestSortingFunctionsOfArrayInts() {
        delete[] this->randomArrayOfInts;
        delete[] this->notRandomArrayOfInts;
    }
    int *SetUpRandomArrayOfInts() const {
        auto *array = new int[this->arraySize];
        std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count()); //generator random values
        std::uniform_int_distribution<> range(-this->dataSize, this->dataSize);
        for (int i = 0; i < this->arraySize; i++){
            array[i] = char (range(generator));
        }
        return array;
    }
    int *SetUpNotRandomArrayOfInts() const {
        auto *array = new int[this->arraySize];
        for(int i = this->dataSize-1; i >= 0; i--){
            array[i] = i;
        }
        return array;
    }
};

TEST_F(TestSortingFunctionsOfArrayInts, InsertionSort){
    this->arraySize = 1000;
    this->dataSize = 1000;
    this->randomArrayOfInts = SetUpRandomArrayOfInts();
    ASSERT_NO_THROW(InsertionSort(this->randomArrayOfInts,this->arraySize));
    for (int i = 1; i < this->arraySize; i++)
        GTEST_ASSERT_GE(this->randomArrayOfInts[i],this->randomArrayOfInts[i-1]);
}

TEST_F(TestSortingFunctionsOfArrayInts, QuickSort){
    this->arraySize = 1000;
    this->dataSize = 1000;
    this->randomArrayOfInts = SetUpRandomArrayOfInts();
    ASSERT_NO_THROW(QuickSort(this->randomArrayOfInts,0,this->arraySize-1));
    for (int i = 1; i < this->arraySize; i++)
        GTEST_ASSERT_GE(this->randomArrayOfInts[i],this->randomArrayOfInts[i-1]);
}

TEST_F(TestSortingFunctionsOfArrayInts, BogoSort){
    this->arraySize = 10;
    this->dataSize = 5;
    this->randomArrayOfInts = SetUpRandomArrayOfInts();
    ASSERT_NO_THROW(BogoSort(this->randomArrayOfInts,this->arraySize));
    for (int i = 1; i < this->arraySize; i++)
        GTEST_ASSERT_GE(this->randomArrayOfInts[i],this->randomArrayOfInts[i-1]);
}

TEST_F(TestSortingFunctionsOfArrayInts, BinarySearch){
    this->dataSize = 100;
    this->arraySize = 100;
    this->notRandomArrayOfInts = SetUpNotRandomArrayOfInts();
    int index = BinarySearch(this->notRandomArrayOfInts, this->arraySize,50);
    GTEST_ASSERT_EQ(this->notRandomArrayOfInts[index],this->notRandomArrayOfInts[50]);
    ASSERT_NO_THROW(BinarySearch(this->notRandomArrayOfInts, this->arraySize,50));
}

TEST(CountingSort, CountingSort){
    std::string str = "hgfedcba";
    CountingSort(str);
    for (int i = 1; i < str.size(); i++)
        GTEST_ASSERT_GE(str[i],str[i-1]);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}