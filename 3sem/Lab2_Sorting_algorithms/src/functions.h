#ifndef LAB2_SORTING_ALGORITHMS_FUNCTIONS_H
#define LAB2_SORTING_ALGORITHMS_FUNCTIONS_H

#include <random>
#include <iostream>
#include <chrono>
#include <string>

int BinarySearch(const int* array, int arraySize, int searchValue);
void QuickSort(int* array, int low, int high);
void InsertionSort(int* array, int arraySize);
void BogoSort(int* array, int arraySize);
void comprasionQuickSortAndInsertionSort();
void CountingSort(std::string &arr);

#endif //LAB2_SORTING_ALGORITHMS_FUNCTIONS_H
