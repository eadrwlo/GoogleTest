//
// Created by me on 09.01.2020.
//

#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H

#include <gmock/gmock.h>

class ControllerIfU {
public:
    virtual ~ControllerIfU() {};
    virtual bool isAllowedAscending(int i) = 0;
};

class Controller : public ControllerIfU {
public:
    bool isAllowedAscending(int i) ;
};

class MockController : public Controller {
public:
    MOCK_METHOD1(isAllowedAscending, bool(int i));
};

#endif //UNTITLED_CONTROLLER_H
