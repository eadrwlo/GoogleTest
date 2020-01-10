#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
//#include "Controller.h"
#include "sqrt.cpp"
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

    isProperOrder(vect, mockControllerPtr, 1);
}

TEST(Div, Pos)
{
    double expectedResult = 2.5;
    double result = div(5.0, 2.0);
    cout << result << endl;
    ASSERT_FLOAT_EQ(result, expectedResult);

    ASSERT_FLOAT_EQ(div(0.0, 2.0), 0.0);
};

TEST(Div, Exception)
{
    EXPECT_THROW(div(1.0, 0.0), std::invalid_argument);
};



int main(int argc, char **argv)  {
    std::cout << "Hello, World!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
