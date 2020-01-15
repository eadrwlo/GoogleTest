//
// Created by me on 13.01.2020.
//

#ifndef GOOGLETESTREPO_MOCKCONTROLLER_H
#define GOOGLETESTREPO_MOCKCONTROLLER_H
#include <gmock/gmock.h>
#include "ControllerIfU.h"
#include "Controller.h"

class MockController : public ControllerIfU {
    public:
    MOCK_CONST_METHOD1(isAllowedAscending, bool(int i));
    MOCK_CONST_METHOD1(printA, void(int i));
    MOCK_CONST_METHOD1(isAllowedToPrint, bool(int i));
    //MOCK_METHOD1(printA, void(int i));

    void delegatePrintA()
    {
        EXPECT_CALL(*this, printA(testing::_))
        .WillOnce(testing::Invoke(&controller, &ControllerIfU::printA));
    }
    void realPrintA(int i)
    {
            controller.printA(i);
    }
private:
    Controller controller;
};

class MockControllerSecond : public Controller {
public:
    MOCK_CONST_METHOD1(isAllowedAscending, bool(int i));
    MOCK_METHOD1(printA, void(int i));
    MOCK_CONST_METHOD1(isAllowedToPrint, bool(int i));


    void realPrintA(int i)
    {
        Controller::printA(i);
    }


//    void delegateToParent(Enum toDelegateName) {
//        switch:
//        {
//            case isAllowedAscending:
//                isAllowedAscending
//            case:isAllowedToPrint
//                    isAllowedToPrint;
//
//
//        }
//    }



        void delegatePrintA() {
        ON_CALL(*this, printA(testing::_))
                .WillByDefault(testing::Invoke([&](int i) {
                    Controller::printA(i);
                }));

        EXPECT_CALL(*this, printA(testing::_))
                .Times(1);
        }

};
#endif //GOOGLETESTREPO_MOCKCONTROLLER_H