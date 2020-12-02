#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "../operations/Add.hpp"

TEST(AddTest, AddEvaluate2Num) {
    Op* leftTest = new Op(7);
    Op* rightTest = new Op(8);
    Add* test = new Add(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), 15);   
}

TEST(AddTest, AddEvaluateNumWithZero) {
    Op* leftTest = new Op(0);
    Op* rightTest = new Op(5);
    Add* test = new Add(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), 5);
}

TEST(AddTest, AddEvaluateNegativeNums) {
    Op* leftTest = new Op(-1);
    Op* rightTest = new Op(9);
    Add* test = new Add(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(AddTest, AddEvaluateWithMult) {
    Op* leftTest = new Op(5);
    Op* LHS = new Op(2);
    Op* RHS = new Op(3);
    Mult* rightTest = new Mult(LHS, RHS);
    Add* test = new Add(leftTest, rightTest);
    EXPECT_EQ(test->evaluate(), 11);
}

TEST(AddTest, AddStringifyTest) {
    Op* leftTest = new Op(2);
    Op* rightTest = new Op(3);
    Add* test = new Add(leftTest, rightTest);
    EXPECT_EQ(test->stringify(), "(2.000000 + 3.000000)");
}

#endif //__ADD_TEST_HPP__
