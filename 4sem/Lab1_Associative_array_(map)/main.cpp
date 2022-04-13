#include <iostream>

#include "headers/associativeArray/associativeArray.h"

int main() {
    redBlackTree<int, int> tree(10, 10);

    tree.insert(13, 13);
    tree.insert(8, 8);
    tree.insert(5, 5);
    tree.insert(17, 17);
    tree.insert(12, 12);

    std::cout << "Breadth-first iterator:" << std::endl;
    auto it = tree.create_dft_iterator();
//    while (it->hasNext()) {
//        std::cout << it->next().getValue() << ' ';
//    }
//    std::cout << std::endl;

//    tree.clear();

//    tree.insert(1,1);

    Queue<std::shared_ptr<elemOfRedBlackTree<int, int>>> queue;
    queue.push(std::make_shared<elemOfRedBlackTree<int, int>>(5, 5, COLOR::RED));


    return 0;
}
