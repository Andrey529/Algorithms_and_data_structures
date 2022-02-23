#include "functions.h"

int BinarySearch(const int* array, int arraySize, int searchValue) {
    if (arraySize <= 0) throw std::invalid_argument("array size <= 0");
    if (array == nullptr) throw std::invalid_argument("pointer to array == nullptr");
    for (int i = 1; i < arraySize; i++) {
        if(array[i] < array[i-1]) throw std::runtime_error("array is not sorted in greater order");
    }
    bool flag = false;
    int high = arraySize - 1;
    int low = 0;
    int middle = (high + low) / 2;
    while ((!flag) and (high >= low)) {
        if (searchValue == array[middle])
            flag = true;
        else{
            if (searchValue < array[middle])
                high = middle - 1;
            else
                low = middle + 1;
        }
        middle = (high + low) / 2;
    }
    return (flag) ? middle : -1;
}

void QuickSort(int* array, int low, int high) {
    if (array == nullptr) throw std::invalid_argument("pointer to array == nullptr");
    if (low < 0) throw std::invalid_argument("low index of array < 0");
    if (high < 0) throw std::invalid_argument("high index of array < 0");
    int left = low;
    int right = high;
    int middle = array[(left + right) / 2];
    int temp;

    while (left <= right){
        while (array[left] < middle)
            left++;
        while (array[right] > middle)
            right--;
        if (left <= right){
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    if (right > low)
        QuickSort(array, low, right);
    if (left < high)
        QuickSort(array, left, high);
}

void InsertionSort(int* array, int arraySize) {
    if (array == nullptr) throw std::invalid_argument("pointer to array == nullptr");
    if (arraySize <= 0) throw std::invalid_argument("array size <= 0");
    int temp, i, j;
    for (i = 1; i < arraySize; i++){
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}



void swapElements(int* elem1, int* elem2) {
    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

bool isArraySorted(const int* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

void BogoSort(int* array, int arraySize) {
    if (array == nullptr) throw std::invalid_argument("pointer to array == nullptr");
    if (arraySize <= 0) throw std::invalid_argument("array size <= 0");
    int temp = arraySize;
    while (!isArraySorted(array, arraySize)) {
        std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count()); //generator random values
        std::uniform_int_distribution<> range(0, arraySize-1);
        while (arraySize > 1) {
            int randomIndex = range(generator);
            arraySize -= 1;
            swapElements(&array[randomIndex], &array[arraySize]);
        }
        arraySize = temp;
    }
}


void CountingSort(std::string &arr){
    char output[arr.size()];

    int count[256], i;
    for (int i = 0; i < 256; i++)
        count[i] = 0;

    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    for (i = 1; i <= 256; ++i)
        count[i] += count[i - 1];

    for (i = 0; arr[i]; ++i){
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

void comprasionQuickSortAndInsertionSort(){
    int dataSize = 10;
    int arraySize = 100000;
    while (dataSize != 1000000) { // datasize = 10 -> 100 -> 1 000 -> 10 000 -> 100 000
        double meanValueForQuickSort = 0; // mean values of the sorting algorithms for 10 runs for different dataSize
        double meanValueForInsertionSort = 0;
        for (int runNumber = 0; runNumber < 10; runNumber++) { // 10 differnt runs for one dataSize
            std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count()); //generator random values
            std::uniform_int_distribution<> range(-dataSize, dataSize);

            auto *arrayForQuickSort = new int[arraySize]; // 2 int arrays for random elements, arrays lenght = 100 000
            auto *arrayForInsertionSort = new int[arraySize];

            for (int i = 0; i < dataSize; i++){ // generate 2 array of random values
                arrayForQuickSort[i] = range(generator);
                arrayForInsertionSort[i] = arrayForQuickSort[i];
            }

            auto start = std::chrono::high_resolution_clock::now();  // start point for QuickSort

            QuickSort(arrayForQuickSort,0,arraySize-1);

            // finish point for QuickSort
            auto finish = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
            meanValueForQuickSort += finish.count();


            start = std::chrono::high_resolution_clock::now();  // start point for InsertionSort

            InsertionSort(arrayForInsertionSort,arraySize);

            // finish point for InsertionSort
            finish = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
            meanValueForInsertionSort += finish.count();

            delete[] arrayForQuickSort;
            delete[] arrayForInsertionSort;
        }

        std::cout << "dataSize = [" << -dataSize << ';' << dataSize << ']' << " and array size = " << 100000 << std::endl;
        std::cout << "\tmeanValueForQuickSort = " << meanValueForQuickSort/10 << " ns = " << meanValueForQuickSort/10000000000 << " sec." << std::endl;
        std::cout << "\tmeanValueForInsertionSort = " << meanValueForInsertionSort/10 << " ns = " << meanValueForInsertionSort/10000000000 << " sec." << std::endl;
        dataSize *= 10;
    }
}