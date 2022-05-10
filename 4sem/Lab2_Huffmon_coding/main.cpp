#include <iostream>
#include <string>
#include "headers/HuffmanCode/HuffmanCode.h"

int main() {

    std::string string;
    std::cin >> string;

    HuffmanCode code(string);
    std::cout << code.getEncodedString() << std::endl;

    std::string newString;
    std::cin >> newString;
    code.encode(newString);
    std::cout << code.getEncodedString() << std::endl;

    auto encodedStr = code.getEncodedString();
    auto table(code.getTable());

    code.decode(encodedStr, table);
    std::cout << code.getSourceString() << std::endl;

    return 0;
}