//
// Created by me on 09.01.2020.
//
#include <iostream>
#include "Controller.h"

bool Controller::isAllowedAscending(int i) const
{
    return i != 0;
}
void Controller::printA(int i) const {
    if(isAllowedToPrint())
        std::cout << "printA(). Printing A" << std::endl;
}

bool Controller::isAllowedToPrint() const {
    std::cout << "Real isAllowedToPrint()" << std::endl;
    return isPrintingAllowed;
}

void Controller::setIsPrintingAllowed(bool isPrintingAllowed) {
    this->isPrintingAllowed = isPrintingAllowed;
}

