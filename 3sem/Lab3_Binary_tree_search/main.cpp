#include <iostream>
#include "headers/binaryTreeSearch/binaryTreeSearch.h"

int main() {

    binaryTreeSearch<int> tree;

    tree.insert(4);
    tree.insert(8);
    tree.insert(7);
    tree.insert(10);
    tree.insert(8);
    tree.insert(2);
    tree.insert(6);
    tree.insert(11);
    tree.insert(1);
    tree.insert(3);
    tree.insert(0);
    tree.insert(9);

    std::cout << "Depth-first iterator:" << std::endl;
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorDepth = tree.create_dft_iterator();
    while (treeIteratorDepth->hasNext()) {
        std::cout << treeIteratorDepth->next().getData() << ' ';
    }
    std::cout << std::endl;


    std::cout << "Breadth-first iterator:" << std::endl;
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = tree.create_bft_iterator();
    while (treeIteratorBreadth->hasNext()) {
        std::cout << treeIteratorBreadth->next().getData() << ' ';
    }
    std::cout << std::endl;


    std::cout << "Find item with value 4 = " << tree.contains(4) << std::endl;

    std::cout << "Remove item with value 4" << std::endl;
    tree.remove(4);

    std::cout << "Find item with value 4 = " << tree.contains(4) << std::endl;

    return 0;
}