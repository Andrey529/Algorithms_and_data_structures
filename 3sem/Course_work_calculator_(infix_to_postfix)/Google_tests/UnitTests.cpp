#include "gtest/gtest.h"

#include <string>
#include "../src/functions/functions.cpp"

class TestCourseWork : public ::testing::Test {
protected:
    std::string *str;
public:
    TestCourseWork() {
        this->str = new std::string();
    }
    ~TestCourseWork() {
        delete this->str;
    }
};

TEST_F(TestCourseWork, calculationPostfixPlus1){
    *(this->str) = "7 8 + ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 15);
}

TEST_F(TestCourseWork, calculationPostfixPlus2){
    *(this->str) = "17 83 + ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 100);
}

TEST_F(TestCourseWork, calculationPostfixPlus3){
    *(this->str) = "-17 -83 + ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), -100);
}

TEST_F(TestCourseWork, calculationPostfixPlus4){
    *(this->str) = "-17 83 + ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 66);
}

TEST_F(TestCourseWork, calculationPostfixPlus5){
    *(this->str) = "17.5 83.3 + ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 100.8);
}

TEST_F(TestCourseWork, calculationPostfixMinus1){
    *(this->str) = "9 8 - ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 1);
}

TEST_F(TestCourseWork, calculationPostfixMinus2){
    *(this->str) = "83 17 - ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 66);
}

TEST_F(TestCourseWork, calculationPostfixMinus3){
    *(this->str) = "-17 -83 - ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 66);
}

TEST_F(TestCourseWork, calculationPostfixMinus4){
    *(this->str) = "-17 83 - ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), -100);
}

TEST_F(TestCourseWork, calculationPostfixMinus5){
    *(this->str) = "17.2 83.5 - ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), -66.3);
}

TEST_F(TestCourseWork, calculationPostfixMultiplication1){
    *(this->str) = "9 8 * ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 72);
}

TEST_F(TestCourseWork, calculationPostfixMultiplication2){
    *(this->str) = "5 -3 * ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), -15);
}

TEST_F(TestCourseWork, calculationPostfixMultiplication3){
    *(this->str) = "-5 -3 * ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 15);
}

TEST_F(TestCourseWork, calculationPostfixMultiplication4){
    *(this->str) = "3.0 5.0 * ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 15);
}

TEST_F(TestCourseWork, calculationPostfixDivision1){
    *(this->str) = "9 3 / ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 3);
}

TEST_F(TestCourseWork, calculationPostfixDivision2){
    *(this->str) = "9 -3 / ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), -3);
}

TEST_F(TestCourseWork, calculationPostfixDivision3){
    *(this->str) = "-9 -3 / ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 3);
}

TEST_F(TestCourseWork, calculationPostfixDivision4){
    *(this->str) = "9.0 3.0 / ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 3.0);
}

TEST_F(TestCourseWork, calculationPostfixPow1){
    *(this->str) = "9 2 ^ ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 81);
}

TEST_F(TestCourseWork, calculationPostfixPow2){
    *(this->str) = "9 -2 ^ ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 1.0/81);
}

TEST_F(TestCourseWork, calculationPostfixPow3){
    *(this->str) = "9 0 ^ ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 1);
}

TEST_F(TestCourseWork, calculationPostfixPow4){
    *(this->str) = "2 5 ^ ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 32);
}

TEST_F(TestCourseWork, calculationPostfixPow5){
    *(this->str) = "2 -5 ^ ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 1.0/32);
}

TEST_F(TestCourseWork, calculationPostfixLog1){
    *(this->str) = "10 log ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 1);
}

TEST_F(TestCourseWork, calculationPostfixLog2){
    *(this->str) = "100 log ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 2);
}

TEST_F(TestCourseWork, calculationPostfixLog3){
    *(this->str) = "10000 log ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 4);
}

TEST_F(TestCourseWork, calculationPostfixLog4){
    *(this->str) = "0.0001 log ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), -4);
}

TEST_F(TestCourseWork, calculationPostfixLog5){
    *(this->str) = "100.0 log ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 2);
}

TEST_F(TestCourseWork, calculationPostfixLogInvalid0){
    *(this->str) = "0 log ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixLogInvalidLess0){
    *(this->str) = "-10 log ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixLn1){
    *(this->str) = "e ln ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 1);
}

TEST_F(TestCourseWork, calculationPostfixLn2){
    *(this->str) = "e 2 ^ ln ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 2);
}

TEST_F(TestCourseWork, calculationPostfixLn3){
    *(this->str) = "e 4 ^ ln ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 4);
}

TEST_F(TestCourseWork, calculationPostfixLn4){
    *(this->str) = "1 e / ln ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), -1);
}

TEST_F(TestCourseWork, calculationPostfixLnInvalid0){
    *(this->str) = "0 ln ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixLnInvalidLess0){
    *(this->str) = "-10 ln ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixSqrt1){
    *(this->str) = "36 sqrt ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 6);
}

TEST_F(TestCourseWork, calculationPostfixSqrt2){
    *(this->str) = "0.25 sqrt ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 0.5);
}

TEST_F(TestCourseWork, calculationPostfixSqrt3){
    *(this->str) = "36.0 sqrt ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 6);
}

TEST_F(TestCourseWork, calculationPostfixSqrt4){
    *(this->str) = "0.0001 sqrt ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 0.01);
}

TEST_F(TestCourseWork, calculationPostfixSqrtInvalid){
    *(this->str) = "-10 sqrt ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixAbs1){
    *(this->str) = "36 abs ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 36);
}

TEST_F(TestCourseWork, calculationPostfixAbs2){
    *(this->str) = "-36 abs ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 36);
}

TEST_F(TestCourseWork, calculationPostfixAbs3){
    *(this->str) = "-36.7 abs ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 36.7);
}

TEST_F(TestCourseWork, calculationPostfixAbs4){
    *(this->str) = "0.0001 abs ";
    GTEST_ASSERT_EQ(calculationPostfix(this->str), 0.0001);
}






TEST_F(TestCourseWork, calculationPostfixSin0){
    *(this->str) = "0 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin30){
    *(this->str) = "30 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin45){
    *(this->str) = "45 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin60){
    *(this->str) = "60 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin90){
    *(this->str) = "90 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin120){
    *(this->str) = "120 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin135){
    *(this->str) = "135 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin150){
    *(this->str) = "150 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin180){
    *(this->str) = "180 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin210){
    *(this->str) = "210 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin225){
    *(this->str) = "225 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin240) {
    *(this->str) = "240 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3) / 2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin270){
    *(this->str) = "270 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin300){
    *(this->str) = "300 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin315){
    *(this->str) = "315 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin330){
    *(this->str) = "330 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin360){
    *(this->str) = "360 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}



TEST_F(TestCourseWork, calculationPostfixSin390){
    *(this->str) = "390 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin405){
    *(this->str) = "405 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin420){
    *(this->str) = "420 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin450){
    *(this->str) = "450 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin480){
    *(this->str) = "480 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin495){
    *(this->str) = "495 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin510){
    *(this->str) = "510 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin540){
    *(this->str) = "540 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin570){
    *(this->str) = "570 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin585){
    *(this->str) = "585 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin600){
    *(this->str) = "600 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin630){
    *(this->str) = "630 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin660){
    *(this->str) = "660 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin675){
    *(this->str) = "675 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin690){
    *(this->str) = "690 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixSin720){
    *(this->str) = "720 sin ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}





TEST_F(TestCourseWork, calculationPostfixCos0){
    *(this->str) = "0 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos30){
    *(this->str) = "30 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos45){
    *(this->str) = "45 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos60){
    *(this->str) = "60 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos90){
    *(this->str) = "90 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos120){
    *(this->str) = "120 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos135){
    *(this->str) = "135 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos150){
    *(this->str) = "150 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos180){
    *(this->str) = "180 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos210){
    *(this->str) = "210 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos225){
    *(this->str) = "225 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos240) {
    *(this->str) = "240 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos270){
    *(this->str) = "270 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos300){
    *(this->str) = "300 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos315){
    *(this->str) = "315 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos330){
    *(this->str) = "330 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos360){
    *(this->str) = "360 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}



TEST_F(TestCourseWork, calculationPostfixCos390){
    *(this->str) = "390 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos405){
    *(this->str) = "405 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos420){
    *(this->str) = "420 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos450){
    *(this->str) = "450 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos480){
    *(this->str) = "480 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos495){
    *(this->str) = "495 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos510){
    *(this->str) = "510 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos540){
    *(this->str) = "540 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos570){
    *(this->str) = "570 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos585){
    *(this->str) = "585 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos600){
    *(this->str) = "600 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos630){
    *(this->str) = "630 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos660){
    *(this->str) = "660 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos675){
    *(this->str) = "675 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(2)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos690){
    *(this->str) = "690 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3)/2, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCos720){
    *(this->str) = "720 cos ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}





TEST_F(TestCourseWork, calculationPostfixTg0){
    *(this->str) = "0 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg30){
    *(this->str) = "30 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg45){
    *(this->str) = "45 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg60){
    *(this->str) = "60 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg90){
    *(this->str) = "90 tg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixTg120){
    *(this->str) = "120 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg135){
    *(this->str) = "135 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg150){
    *(this->str) = "150 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg180){
    *(this->str) = "180 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg210){
    *(this->str) = "210 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg225){
    *(this->str) = "225 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg240) {
    *(this->str) = "240 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3) , 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg270){
    *(this->str) = "270 tg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixTg300){
    *(this->str) = "300 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg315){
    *(this->str) = "315 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg330){
    *(this->str) = "330 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg360){
    *(this->str) = "360 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}



TEST_F(TestCourseWork, calculationPostfixTg390){
    *(this->str) = "390 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg405){
    *(this->str) = "405 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg420){
    *(this->str) = "420 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg450){
    *(this->str) = "450 tg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixTg480){
    *(this->str) = "480 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg495){
    *(this->str) = "495 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg510){
    *(this->str) = "510 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg540){
    *(this->str) = "540 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg570){
    *(this->str) = "570 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg585){
    *(this->str) = "585 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg600){
    *(this->str) = "600 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg630){
    *(this->str) = "630 tg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixTg660){
    *(this->str) = "660 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg675){
    *(this->str) = "675 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg690){
    *(this->str) = "690 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixTg720){
    *(this->str) = "720 tg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}





TEST_F(TestCourseWork, calculationPostfixCtg0){
    *(this->str) = "0 ctg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixCtg30){
    *(this->str) = "30 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg45){
    *(this->str) = "45 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg60){
    *(this->str) = "60 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg90){
    *(this->str) = "90 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg120){
    *(this->str) = "120 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg135){
    *(this->str) = "135 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg150){
    *(this->str) = "150 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg180){
    *(this->str) = "180 ctg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixCtg210){
    *(this->str) = "210 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg225){
    *(this->str) = "225 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg240) {
    *(this->str) = "240 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg270){
    *(this->str) = "270 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg300){
    *(this->str) = "300 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg315){
    *(this->str) = "315 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg330){
    *(this->str) = "330 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg360){
    *(this->str) = "360 ctg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}



TEST_F(TestCourseWork, calculationPostfixCtg390){
    *(this->str) = "390 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg405){
    *(this->str) = "405 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg420){
    *(this->str) = "420 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg450){
    *(this->str) = "450 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg480){
    *(this->str) = "480 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg495){
    *(this->str) = "495 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg510){
    *(this->str) = "510 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg540){
    *(this->str) = "540 ctg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}

TEST_F(TestCourseWork, calculationPostfixCtg570){
    *(this->str) = "570 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg585){
    *(this->str) = "585 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg600){
    *(this->str) = "600 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg630){
    *(this->str) = "630 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg660){
    *(this->str) = "660 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1/sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg675){
    *(this->str) = "675 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg690){
    *(this->str) = "690 ctg ";
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -sqrt(3), 0.0000001), true);
}

TEST_F(TestCourseWork, calculationPostfixCtg720){
    *(this->str) = "720 ctg ";
    ASSERT_ANY_THROW(calculationPostfix(this->str));
}





TEST_F(TestCourseWork, convertInfixToPostfix1){
    *(this->str) = "((sin(123 - 56) + e) - 2)";
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str), "123 56 - sin e + 2 - ");
}

TEST_F(TestCourseWork, convertInfixToPostfix2){
    *(this->str) = "((sin(123 - 56) + pi) - 2)";
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str), "123 56 - sin pi + 2 - ");
}

TEST_F(TestCourseWork, convertInfixToPostfi3){
    *(this->str) = "((sin(123 - 56) + cos(5 ^ 4)) / 2)";
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str), "123 56 - sin 5 4 ^ cos + 2 / ");
}





TEST_F(TestCourseWork, setParentHesis1){
    *(this->str) = "1 + 2 ^ 3";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(1 + (2 ^ 3))");
}

TEST_F(TestCourseWork, setParentHesis2){
    *(this->str) = "2 ^ 3";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(2 ^ 3)");
}

TEST_F(TestCourseWork, setParentHesis3){
    *(this->str) = "1 + (1 + 2) ^ 3";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(1 + (((1 + 2)) ^ 3))");
}

TEST_F(TestCourseWork, setParentHesis4){
    *(this->str) = "(1 + 2) ^ 3";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(((1 + 2)) ^ 3)");
}

TEST_F(TestCourseWork, setParentHesis5){
    *(this->str) = "1 + sin(1 + 2) ^ 3";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(1 + (sin((1 + 2)) ^ 3))");
}

TEST_F(TestCourseWork, setParentHesis6){
    *(this->str) = "sin(1 + 2) ^ 3";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(sin((1 + 2)) ^ 3)");
}

TEST_F(TestCourseWork, setParentHesis7){
    *(this->str) = "sin(1 + 2) ^ 3 + 4";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((sin((1 + 2)) ^ 3) + 4)");
}

TEST_F(TestCourseWork, setParentHesis8){
    *(this->str) = "sin(1 + 2) ^ (3 + 4)";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(sin((1 + 2)) ^ ((3 + 4)))");
}

TEST_F(TestCourseWork, setParentHesis9){
    *(this->str) = "sin(1 + 2) ^ (3 + 4) + 5";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((sin((1 + 2)) ^ ((3 + 4))) + 5)");
}

TEST_F(TestCourseWork, setParentHesis10){
    *(this->str) = "sin(1 + 2) ^ sin(3 + 4)";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(sin((1 + 2)) ^ sin((3 + 4)))");
}

TEST_F(TestCourseWork, setParentHesis11){
    *(this->str) = "sin(1 + 2) ^ sin(3 + 4) + 5";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((sin((1 + 2)) ^ sin((3 + 4))) + 5)");
}

TEST_F(TestCourseWork, setParentHesis12){
    *(this->str) = "sin(1 + 2) ^ (3 + 4) + 5";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((sin((1 + 2)) ^ ((3 + 4))) + 5)");
}

TEST_F(TestCourseWork, setParentHesis13){
    *(this->str) = "1 + 2 + 3 + 4";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(((1 + 2) + 3) + 4)");
}

TEST_F(TestCourseWork, setParentHesis14){
    *(this->str) = "1 + 2 * 3 + 4";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((1 + (2 * 3)) + 4)");
}


TEST_F(TestCourseWork, setParentHesis15){
    *(this->str) = "1 + 2 * 3 / 4";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(1 + ((2 * 3) / 4))");
}

TEST_F(TestCourseWork, setParentHesis16){
    *(this->str) = "2 ^ 3 + 3 * 6 * 7 - 2";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(((2 ^ 3) + ((3 * 6) * 7)) - 2)");
}

TEST_F(TestCourseWork, setParentHesis17){
    *(this->str) = "2 ^ 3 + 3 * 6 - 2";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(((2 ^ 3) + (3 * 6)) - 2)");
}

TEST_F(TestCourseWork, setParentHesis18){
    *(this->str) = "2 ^ (3 + 4) * sin((7 - 8) * (9 * 10)) - (11 * 12)";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(((2 ^ ((3 + 4))) * sin((((7 - 8)) * ((9 * 10))))) - ((11 * 12)))");
}

TEST_F(TestCourseWork, setParentHesis19){
    *(this->str) = "sin((7 - 8) * (9 * 10))";
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "sin((((7 - 8)) * ((9 * 10))))");
}


TEST_F(TestCourseWork, inputExpressionGOOD1){
    *(this->str) = "1 + 2";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD2){
    *(this->str) = "1 +2";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD3){
    *(this->str) = "1 + 2.22222";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD4){
    *(this->str) = "1 +                  2";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD5){
    *(this->str) = "1 + (2.13256 - 3)";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD6){
    *(this->str) = "sin(45)";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD7){
    *(this->str) = "sin(45 + 45)";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD8){
    *(this->str) = "sin(45        + 45.1564)";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD9){
    *(this->str) = "sin((23 - 8) * (0.2 * 10))";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionGOOD10){
    *(this->str) = "e + pi * sin((23 - 8) * (0.2 * 10))";
    ASSERT_NO_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR1){
    *(this->str) = "1 2";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR2){
    *(this->str) = "1 + 2 +";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR3){
    *(this->str) = "1 + +++ 2.2";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR4){
    *(this->str) = "1 + 2....2";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR5){
    *(this->str) = "((()))";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR6){
    *(this->str) = "((())";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR7){
    *(this->str) = "(((+)))";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR8){
    *(this->str) = "";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR9){
    *(this->str) = "1 + 2)";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR10){
    *(this->str) = "sin";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR11){
    *(this->str) = "sin(23 ";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR12){
    *(this->str) = "sinjdad(45)";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR13){
    *(this->str) = "asfmlk + 2";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR14){
    *(this->str) = "sin ( +  23";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR15){
    *(this->str) = "sin  +  23";
    ASSERT_ANY_THROW(inputExpression(this->str));
}

TEST_F(TestCourseWork, inputExpressionERROR16){
    *(this->str) = "sin(12) - ()  +  23";
    ASSERT_ANY_THROW(inputExpression(this->str));
}


TEST_F(TestCourseWork, fullTest1){
    *(this->str) = "1 + 2 ^ 3";

    ASSERT_NO_THROW(inputExpression(this->str));
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(1 + (2 ^ 3))");
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str),"1 2 3 ^ + ");
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 9, 0.0000001), true);
}

TEST_F(TestCourseWork, fullTest2){
    *(this->str) = "1 + 2 ^ 3 - (5 * 2)";

    ASSERT_NO_THROW(inputExpression(this->str));
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((1 + (2 ^ 3)) - ((5 * 2)))");
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str),"1 2 3 ^ + 5 2 * - ");
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, -1, 0.0000001), true);
}

TEST_F(TestCourseWork, fullTest3){
    *(this->str) = "(1 + 2) ^ 3 - (5 * 2)";

    ASSERT_NO_THROW(inputExpression(this->str));
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((((1 + 2)) ^ 3) - ((5 * 2)))");
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str),"1 2 + 3 ^ 5 2 * - ");
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 17, 0.0000001), true);
}

TEST_F(TestCourseWork, fullTest4){
    *(this->str) = "(1 + 2) ^ 3 - sin(45 / 1.5)";

    ASSERT_NO_THROW(inputExpression(this->str));
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((((1 + 2)) ^ 3) - sin((45 / 1.5)))");
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str),"1 2 + 3 ^ 45 1.5 / sin - ");
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 26.5, 0.0000001), true);
}

TEST_F(TestCourseWork, fullTest5){
    *(this->str) = "sin((23 - 8) * (0.2 * 10))";

    ASSERT_NO_THROW(inputExpression(this->str));
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "sin((((23 - 8)) * ((0.2 * 10))))");
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str),"23 8 - 0.2 10 * * sin ");
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 0.5, 0.0000001), true);
}

TEST_F(TestCourseWork, fullTest6){
    *(this->str) = "2 - (3 + 1) ^ 2 + sin((23 - 8) * (0.2 * 10)) + 34 / 2";

    ASSERT_NO_THROW(inputExpression(this->str));
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "(((2 - (((3 + 1)) ^ 2)) + sin((((23 - 8)) * ((0.2 * 10))))) + (34 / 2))");
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str),"2 3 1 + 2 ^ - 23 8 - 0.2 10 * * sin + 34 2 / + ");
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, 3.5, 0.0000001), true);
}


TEST_F(TestCourseWork, fullTest7){
    *(this->str) = "e + 3 * 4 - pi";

    ASSERT_NO_THROW(inputExpression(this->str));
    setParanthesis(this->str);
    GTEST_ASSERT_EQ(*(this->str), "((e + (3 * 4)) - pi)");
    convertInfixToPostfix(this->str);
    GTEST_ASSERT_EQ(*(this->str),"e 3 4 * + pi - ");
    double result = calculationPostfix(this->str);
    GTEST_ASSERT_EQ(approximatelyEqual(result, (M_E + 12 - M_PI), 0.0000001), true);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}