#ifndef RAND_TEST
#define RAND_TEST

#include "../operations/rand.hpp"

TEST(RandTest, RandLessThan100){
	Base* test = new Rand();
	EXPECT_LT(test->evaluate(), 100);
}

TEST(RandTest, RandStringify){
	Base* test = new Rand();
	EXPECT_EQ(test->stringify(), std::to_string(test->evaluate()));
}

TEST(RandTest, RandGreaterThan0){
	Base* test = new Rand();
	EXPECT_GT(test->evaluate(), 0);
}

#endif
