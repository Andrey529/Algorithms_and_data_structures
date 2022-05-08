#include <iostream>
#include <string>
#include "headers/HuffmanCode/HuffmanCode.h"


int main() {

    std::string string;
    std::cin >> string;

    HuffmanCode code(string);
    std::cout << code.getEncodedString() << std::endl;

//    code.getTable();
//    std::cout << code.getSourceString() << std::endl;
//
//    std::cout << code.getCountBytesByTheSourceString() << std::endl;

//    code.clear();

//    code.setSourceString("6666667777777");

//    code.getSymbolsFrequency().print();

//    std::cout << code.getCountBytesByTheSourceString() << std::endl;

    return 0;
}