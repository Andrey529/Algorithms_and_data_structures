#include <iostream>
#include <string>
#include "headers/HuffmanCode/HuffmanCode.h"

#include "headers/Stack/Stack.h"

int main() {

    Stack<int> stack1;
    for (int i = 0; i < 5; ++i) {
        stack1.push(i);
    }

    Stack<int> stack2 = std::move(stack1);

    stack2.pop();
    stack2.pop();
    stack2.pop();

    std::cout << stack2.getSize() << std::endl;
    std::cout << stack2.getFront().lock()->data_ << std::endl;
    std::cout << stack2.getBack().lock()->data_ << std::endl;

//    std::string string;
//    std::cin >> string;
//
//    HuffmanCode code(string);
//
//    std::cout << code.getSourceString() << std::endl;
//
//    std::cout << code.getCountBytesByTheSourceString() << std::endl;

//    code.clear();

//    code.setSourceString("6666667777777");

//    code.getSymbolsFrequency().print();

//    std::cout << code.getCountBytesByTheSourceString() << std::endl;



    return 0;
}