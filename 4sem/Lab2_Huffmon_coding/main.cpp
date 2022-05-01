#include <iostream>
#include "headers/AssociativeArray/AssociativeArray.h"
#include <string>
#include "headers/HuffmanCode/HuffmanCode.h"
int main() {

    std::string string;
    std::cin >> string;

    HuffmanCode code(string);
    code.calculateSymbolsFrequency();
    code.getSymbolsFrequency().print();

    return 0;
}