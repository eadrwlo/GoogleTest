//
// Created by me on 09.01.2020.
//

#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H
//#include <gtest/gtest.h>
#include "ControllerIfU.h"

class Controller : public ControllerIfU {
public:
    bool isAllowedAscending(int i) const;
    void printA(int i) const;
    bool isAllowedToPrint(int i) const;


private:
    bool isPrintingAllowed;
public:
    void setIsPrintingAllowed(bool isPrintingAllowed);
};
#endif //UNTITLED_CONTROLLER_H
