#include <iostream>
#include "src/functions.h"

int main() {

    std::cout << "---------Example of BinarySearch()---------" << std::endl;
    auto *arrayBinary = new int[5] {1,2,3,5,7};
    std::cout << "Array = ";
    for (int i = 0; i < 5; i++)    std::cout << arrayBinary[i] << ' ';
    std::cout << std::endl;
    std::cout << "Index of element wih 5 = " << BinarySearch(arrayBinary,5,5) << std::endl << std::endl;
    delete[] arrayBinary;


    std::cout << "---------Example of QuickSort()---------" << std::endl;
    auto *arrayQuick = new int[5] {7,3,5,1,2};
    std::cout << "Array before sorting = ";
    for (int i = 0; i < 5; i++)    std::cout << arrayQuick[i] << ' ';
    std::cout << std::endl;
    QuickSort(arrayQuick,0,4);
    std::cout << "Array after sorting = ";
    for (int i = 0; i < 5; i++)    std::cout << arrayQuick[i] << ' ';
    std::cout << std::endl << std::endl;
    delete[] arrayQuick;

    std::cout << "---------Example of InsertionSort()---------" << std::endl;
    auto *arrayInsertion = new int[5] {7,3,5,1,2};
    std::cout << "Array before sorting = ";
    for (int i = 0; i < 5; i++)    std::cout << arrayInsertion[i] << ' ';
    std::cout << std::endl;
    InsertionSort(arrayInsertion,5);
    std::cout << "Array after sorting = ";
    for (int i = 0; i < 5; i++)    std::cout << arrayInsertion[i] << ' ';
    std::cout << std::endl << std::endl;
    delete[] arrayInsertion;


    std::cout << "---------Example of BogoSort()---------" << std::endl;
    auto *arrayBogo = new int[5] {7,3,5,1,2};
    std::cout << "Array before sorting = ";
    for (int i = 0; i < 5; i++)    std::cout << arrayBogo[i] << ' ';
    std::cout << std::endl;
    BogoSort(arrayBogo,5);
    std::cout << "Array after sorting = ";
    for (int i = 0; i < 5; i++)    std::cout << arrayBogo[i] << ' ';
    std::cout << std::endl << std::endl;
    delete[] arrayBogo;

    std::cout << "---------Example of CountingSort()---------" << std::endl;
    std::string str = "hgfedbca";
    std::cout << "Array before sorting = " << str << std::endl;
    CountingSort(str);
    std::cout << "Array after sorting = ";
    std::cout << str << std::endl << std::endl;


    comprasionQuickSortAndInsertionSort();

    return 0;
}