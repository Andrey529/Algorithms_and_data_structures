#include <iostream>
#include "headers/AssociativeArray/AssociativeArray.h"
#include <string>
#include "headers/HuffmanCode/HuffmanCode.h"

#include <forward_list>

#include "headers/List/List.h"

int main() {

    std::string string;
    std::cin >> string;

    HuffmanCode code(string);
//    code.getSymbolsFrequency().print();

//    std::cout << code.getCountBytesByTheSourceString() << std::endl;



    return 0;
}