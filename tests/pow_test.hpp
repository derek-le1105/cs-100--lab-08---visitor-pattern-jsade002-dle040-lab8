#ifndef POW_TEST
#define POW_TEST

#include "gtest/gtest.h"

#include "../operations/pow.hpp"

Op* zero = new Op(0);
Op* nFive = new Op(-5);
Op* three = new Op(3);
Op* two = new Op(2);

TEST(PowTest, PowEvaluateZero){
	Base* test = new Pow(zero, zero);
	EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowEvaluateZeroStringify){
	Base* test = new Pow(zero, zero);
	EXPECT_EQ(test->stringify(), "(0.000000 ** 0.000000)");
}


TEST(PowTest, PowEvaluateNegativeToThird){
	Base* test = new Pow(nFive, three);
	EXPECT_EQ(test->evaluate(), -125);
}

TEST(PowTest, PowEvaluateNegativeToThirdStringify){
	Base* test = new Pow(nFive, three);
	EXPECT_EQ(test->stringify(), "(-5.000000 ** 3.000000)");
}

TEST(PowTest, PowEvaluateNegativeToTwo){
	Base* test = new Pow(nFive, two);
	EXPECT_EQ(test->evaluate(), 25);
}

TEST(PowTest, PowEvaluateNegativeToTwoStringify){
	Base* test = new Pow(nFive, two);
	EXPECT_EQ(test->stringify(), "(-5.000000 ** 2.000000)");
}


#endif
