#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "../operations/Sub.hpp"

TEST(SubTest, SubEvaluate2Num) {
    Op* leftTest = new Op(7);
    Op* rightTest = new Op(8);
    Sub* test = new Sub(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(SubTest, SubEvaluateNumWithZero) {
    Op* leftTest = new Op(0);
    Op* rightTest = new Op(5);
    Sub* test = new Sub(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), -5);
}

TEST(SubTest, SubEvaluateNegativeNums) {
    Op* leftTest = new Op(-1);
    Op* rightTest = new Op(9);
    Sub* test = new Sub(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), -10);
}

TEST(SubTest, SubEvaluateWithMult) {
    Op* leftTest = new Op(5);
    Op* LHS = new Op(2);
    Op* RHS = new Op(3);
    Mult* rightTest = new Mult(LHS, RHS);
    Sub* test = new Sub(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(SubTest, SubStringifyTest) {
    Op* LHS = new Op(2);
    Op* RHS = new Op(3);
    Sub* test = new Sub(LHS, RHS);
    EXPECT_EQ(test->stringify(), "(2.000000 - 3.000000)");
}

#endif  //__SUB_TEST_HPP__

