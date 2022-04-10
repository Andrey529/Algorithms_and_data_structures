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

    tree.clear();

    tree.insert(1,1);

    return 0;
}
