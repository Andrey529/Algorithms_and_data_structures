#include "headers/listOfInts.h"

int main() {
    std::cout << "Create new empty list" << std::endl << std::endl;
    listOfInts list;

    std::cout << "Check if the list is empty" << std::endl;
    std::cout << "List is empty:" << list.isEmpty() << std::endl;
    std::cout << "List size = " << list.get_size() << std::endl << std::endl;

    std::cout << "Fill the list with five elements" << std::endl;
    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }
    std::cout << "List size = " << list.get_size() << std::endl;
    std::cout << list << std::endl << std::endl;

    std::cout << "Insert new element by index 3 and number = 100" << std::endl;
    list.insert(100,3);
    std::cout << list << std::endl << std::endl;

    std::cout << "Clear list" << std::endl;
    list.clear();
    std::cout << "List size = " << list.get_size() << std::endl << std::endl << std::endl;

    std::cout << "Fill the list with new five elements" << std::endl;
    for(int i = 0; i < 5; i++){
        list.push_front(i);
    }
    std::cout << list << std::endl << std::endl;

    std::cout << "Remove element by index 2" << std::endl;
    list.remove(2);
    std::cout << list << std::endl << std::endl;

    return 0;
}