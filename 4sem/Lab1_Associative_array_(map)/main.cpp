#include <iostream>

#include "headers/associativeArray/associativeArray.h"

#include <map>

int main() {
    redBlackTree<int, int> tree(10, 10);

    tree.insert(13, 13);
    tree.insert(8, 8);
    tree.insert(5, 5);
    tree.insert(17, 17);
    tree.insert(12, 12);
    tree.insert(9, 9);

    /*

                 10
            8            13
        5      9     12      17

    */
    std::cout << "Breadth-first iterator:" << std::endl;
    auto it = tree.createDftIterator();
    while (it->hasNext()) {
        std::cout << it->next()->getKey() << ' ';
    }
    std::cout << std::endl;

    auto listKeys = tree.getKeys();
    std::cout << listKeys << std::endl;

    auto listValues = tree.getValues();
    std::cout << listValues << std::endl;

    tree.print();




    std::map<int, int> map;
    for (int i = 0; i < 5; ++i) {
        map.insert(std::pair<int, int>(i, i));
    }

    map.find(6);

//    map.insert(std::pair<int, int>(1, 2));
//
//    for (auto const &pair: map) {
//        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
//    }

//    std::unique_ptr<Queue<int>> queueInt;
//    queueInt = std::make_unique<Queue<int>>();
//    queueInt->push(1);

//    std::unique_ptr<Queue<std::shared_ptr<elemOfRedBlackTree<int, int>>>> queue;
//    queue = std::make_unique<Queue<std::shared_ptr<elemOfRedBlackTree<int, int>>>>();
//    queue->push(std::make_shared<elemOfRedBlackTree<int, int>>(1,1,COLOR::RED));


    return 0;
}
