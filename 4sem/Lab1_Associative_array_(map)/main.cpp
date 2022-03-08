#include <iostream>

#include "headers/associativeArray/associativeArray.h"

#include <map>

int main() {
    auto elem = std::make_shared<elemOfRedBlackTree<int, int>>(7, 7, COLOR::BLACK);
    auto parent = std::make_shared<elemOfRedBlackTree<int, int>>(10, 10, COLOR::BLACK);
    auto childLeft = std::make_shared<elemOfRedBlackTree<int, int>>(5, 5, COLOR::BLACK);
    auto childRight = std::make_shared<elemOfRedBlackTree<int, int>>(8, 8, COLOR::BLACK);

    elem->setParent(std::move(parent));
    elem->setNextLeft(childLeft);
    elem->setNextRight(childRight);


    std::shared_ptr<elemOfRedBlackTree<int, int>> elemParent = elem->getParent();
    std::shared_ptr<elemOfRedBlackTree<int, int>> elemRight = elem->getNextRight();

    std::cout << "Const return" << std::endl;
    std::cout << elem->getParent()->getValue() << ' ' << elemParent->getValue() << std::endl;
    elemParent = std::make_shared<elemOfRedBlackTree<int, int>>(54, 54, COLOR::BLACK);
    std::cout << elem->getParent()->getValue() << ' ' << elemParent->getValue() << std::endl;

    std::cout << "Non-const return" << std::endl;
    std::cout << elem->getNextRight()->getValue() << ' ' << elemRight->getValue() << std::endl;
    elemRight = std::make_shared<elemOfRedBlackTree<int, int>>(61, 61, COLOR::BLACK);
    std::cout << elem->getNextRight()->getValue() << ' ' << elemRight->getValue() << std::endl;



//    std::cout << "parent value = " << elem->getParent()->getValue() << std::endl;
//    std::cout << "nextLeft value = " << elem->getNextLeft()->getValue() << std::endl;
//    std::cout << "nextRight value = " << elem->getNextRight()->getValue() << std::endl;
//
//    auto test = elem->getParent();
//    auto newElem = std::make_shared<elemOfRedBlackTree<int, int>>(11, 11, COLOR::BLACK);
//
//    test = newElem;
//    std::cout << test->getValue() << std::endl;
//    std::cout << elem->getParent()->getValue() << std::endl;
//
//    elem->getParent()->setNextRight(newElem);

//    try {
//        elemParent->getParent()->getValue();
//    }
//    catch (const std::logic_error &e) {
//        std::cout << e.what() << std::endl;
//    }

//    std::cout << parent->getValue() << ":" << childLeft->getValue() << ":" << childRight->getValue() << std::endl;


    return 0;
}
