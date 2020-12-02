#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "../operations/Mult.hpp"

TEST(MultTest, MultEvaluate2Num) {
    Op* leftTest = new Op(7);
    Op* rightTest = new Op(8);
    Mult* test = new Mult(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), 56);   
}

TEST(MultTest, MultEvaluateNumWithZero) {
    Op* leftTest = new Op(0);
    Op* rightTest = new Op(5);
    Mult* test = new Mult(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNegativeNums) {
    Op* leftTest = new Op(-1);
    Op* rightTest = new Op(9);
    Mult* test = new Mult(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), -9);
}

TEST(MultTest, MultStringifyTest) {
    Op* leftTest = new Op(2);
    Op* rightTest = new Op(3);
    Mult* test = new Mult(leftTest, rightTest);
    EXPECT_EQ(test->stringify(), "(2.000000 * 3.000000)");
}

#endif //__MULT_TEST_HPP__
