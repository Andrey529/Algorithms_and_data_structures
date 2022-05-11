#include <iostream>

#include "headers/Exceptions/Exceptions.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    throw(Except("da", 1, 2));
    return 0;
}
