#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Controller/ControllerIfU.h"
#include "sqrt.cpp"
#include "Controller/MockController.h"

using namespace std;
using ::testing::NiceMock;


/****************************************************************************/
/********************************** Set up **********************************?
/****************************************************************************/
class TestData : public testing::Test
{
public:
    MockController *mockControllerPtr;
    void SetUp() { mockControllerPtr = new NiceMock<MockController>(); init(); }
    void init() { ON_CALL(*mockControllerPtr, isAllowedAscending(testing::_)).WillByDefault(testing::Return(false)); }
    void TearDown() { delete mockControllerPtr; }
};


/****************************************************************************/


TEST(SquareRootTest, PositiveNos)
{
    std::cout << "Starting Controller, Mock" << std::endl;
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}

TEST_F(TestData, Mock)
{
    std::cout << "Starting Controller, Mock" << std::endl;

    std::vector<double> vect;
    vect.push_back(13.0);
    vect.push_back(15.0);

    EXPECT_CALL(*mockControllerPtr, isAllowedAscending(testing::_))
            .WillOnce(testing::Return(true));

    ASSERT_TRUE(isProperOrder(vect, mockControllerPtr, 1));
}

TEST(Div, Pos)
{
    double expectedResult = 2.5;
    double result = div(5.0, 2.0);
    cout << result << endl;
    ASSERT_FLOAT_EQ(result, expectedResult);
};

TEST(Div, Exception)
{
    EXPECT_THROW(div(1.0, 0.0), std::invalid_argument);
    EXPECT_THROW(div(0.0, 1.0), std::invalid_argument);
};

//TEST(Mock, Real)
//{
//    MockController mockController;
//    mockController.delegatePrintA();
//
//    mockController.realPrintA(1);
//};

TEST(Mock, Nice)
{
    testing::NiceMock<MockControllerSecond> mockControllerSecond;
    mockControllerSecond.realPrintA(0);
}

TEST(Mock, Naggy)
{
    testing::NaggyMock<MockControllerSecond> mockControllerSecond;
    mockControllerSecond.realPrintA(0);
}


TEST(Mock, Real2)
{
    testing::StrictMock<MockControllerSecond> mockControllerSecond;

    EXPECT_CALL(mockControllerSecond, isAllowedToPrint(0))
            .WillOnce(testing::Return(true));

    mockControllerSecond.realPrintA(0);
}
TEST(Mock, Real3)
{
    MockControllerSecond mockController;

    
    EXPECT_CALL(mockController, isAllowedToPrint(testing::_))
            .WillOnce(testing::Return(true));

    ON_CALL(mockController, printA(testing::_))
            .WillByDefault(testing::Invoke(&mockController, &MockControllerSecond::realPrintA));

    mockController.printA(1);
};


TEST(Mock, Real4)
{
    ControllerIfU* mockController = new NiceMock<MockController>();
    Controller controller;

//    EXPECT_CALL(*(static_cast<MockController*>(mockController)), isAllowedToPrint())
//            .WillOnce(testing::Return(true));

    dynamic_cast<MockController*>(mockController)->printA(1);

    delete mockController;
};

TEST(Mock, Real5)
{
    MockControllerSecond mockController;

    EXPECT_CALL(mockController, isAllowedToPrint(testing::_))
            .WillOnce(testing::Return(true));

    mockController.delegatePrintA();

    mockController.printA(1);
};

int main(int argc, char **argv)  {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
