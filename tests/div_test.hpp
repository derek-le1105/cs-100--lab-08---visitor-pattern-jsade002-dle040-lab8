#ifndef DIV_TEST
#define DIV_TEST

#include "gtest/gtest.h"

#include "../operations/div.hpp"

Op* nTwo = new Op(-2);
Op* ten = new Op(10);

TEST(DivTest, DivideByPositive){
	Base* test = new Div(ten, ten);
	EXPECT_EQ(test->evaluate(), 1);
}

TEST(DivTest, DivideByPositiveStringify){
	Base* test = new Div(ten, ten);
	EXPECT_EQ(test->stringify(), "(10.000000 / 10.000000)");
}

TEST(DivTest, DivideByNegative){
	Base* test = new Div(ten, nTwo);
	EXPECT_EQ(test->evaluate(), -5);
}

TEST(DivTest, DivideByNegativeStringify){
	Base* test = new Div(ten, nTwo);
	EXPECT_EQ(test->stringify(), "(10.000000 / -2.000000)");
}

#endif
