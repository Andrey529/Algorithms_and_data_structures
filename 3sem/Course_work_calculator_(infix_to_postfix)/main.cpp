#include <iostream>
#include <string>
#include "headers/functions/functions.h"

int main() {
    auto *expression = new std::string();

    std::cout << "Please input an expression: " << std::endl;
    inputExpression(expression);
    std::cout << "You inputed: \n" << *expression << std::endl;

    setParanthesis(expression);

    convertInfixToPostfix(expression);
    std::cout << "The expression after tranlation from infix to postfix form: \n" << *expression << std::endl;

    std::cout << "The result = " << calculationPostfix(expression) << std::endl;
    return 0;
}