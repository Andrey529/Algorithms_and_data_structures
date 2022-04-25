#include <iostream>

#include "headers/associativeArray/associativeArray.h"

#include <map>

/**
 * -------- 1) function repair tree after insert
 * -------- 2) function remove
 * -------- 3) function repair tree after remove
 * -------- 4) check in function insert when new key is already been in tree
 *
 * 5) unit-tests
 *
 * 6) fix memory liks in iterators
 * 7) do good iteartor for the tree
 *      legacy random access iterator
 * 8) function find be able to return iterator on find element
 */


int main() {
    associativeArray<int, int> map(10, 10);

    map.insert(13, 13);
    map.insert(8, 8);
    map.insert(5, 5);
    map.insert(17, 17);
    map.insert(12, 12);
    map.insert(9, 9);
    map.insert(11, 11);
    map.insert(4, 4);
    map.insert(3, 3);

    /*

                 10
            8            13
        4      9     12      17

      3    5       11
    */

    std::cout << "Breadth-first iterator:" << std::endl;
    auto it = map.createDftIterator();
    while (it->hasNext()) {
        std::cout << it->next()->getKey() << ' ';
    }
    std::cout << std::endl << std::endl;

    auto listKeys = map.getKeys();
    std::cout << listKeys << std::endl;

    auto listValues = map.getValues();
    std::cout << listValues << std::endl;

    map.print();
    std::cout << std::endl;

    std::cout << map.contains(10) << ' ' << map.contains(8) << ' ' << map.contains(17) << ' ' << map.contains(12) << "\n";
    std::cout << map.contains(100) << ' ' << map.contains(-1) << ' ' << map.contains(15) << '\n';

    map.remove(17);
    map.remove(8);
    map.remove(12);
    map.remove(4);

    std::cout << map.contains(17) << ' ' << map.contains(8) << ' ' << map.contains(12) << ' ' << map.contains(4) << '\n';

    return 0;
}
