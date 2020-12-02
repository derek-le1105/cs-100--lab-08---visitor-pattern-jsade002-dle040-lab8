#ifndef __FACTORY_TESTS_HPP__
#define __FACTORY_TESTS_HPP__

#include "../Factory.hpp"
#include "../base.hpp"
#include <iostream>
#include "gtest/gtest.h"

TEST(FactoryTest, Addition){
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "6";
    test_val[2] = "+";
    test_val[3] = "4";
    Factory* factoryTest = new Factory();

    Base* conversion = factoryTest->parse(test_val, 4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "(6.000000 + 4.000000)");
    EXPECT_EQ(conversion->evaluate(), 10.000000);
}

TEST(FactoryTest, Multiplication){
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "4";
    test_val[2] = "\*";
    test_val[3] = "6";
    Factory* factoryTest = new Factory();

    Base* conversion = factoryTest->parse(test_val, 4);
	
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "(4.000000 * 6.000000)");
    EXPECT_EQ(conversion->evaluate(), 24.000000);
}

TEST(FactoryTest, Subtraction){
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "10";
    test_val[2] = "-";
    test_val[3] = "5";
    Factory* factoryTest = new Factory();

    Base* conversion = factoryTest->parse(test_val, 4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "(10.000000 - 5.000000)");
    EXPECT_EQ(conversion->evaluate(), 5.000000);
}

TEST(FactoryTest, Division){
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "8";
    test_val[2] = "/";
    test_val[3] = "4";
    Factory* factoryTest = new Factory();

    Base* conversion = factoryTest->parse(test_val, 4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "(8.000000 / 4.000000)");
    EXPECT_EQ(conversion->evaluate(), 2.000000);
}

TEST(FactoryTest, Power){
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "2";
    test_val[2] = "**";
    test_val[3] = "3";
    Factory* factoryTest = new Factory();

    Base* conversion = factoryTest->parse(test_val, 4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "(2.000000 ** 3.000000)");
    EXPECT_EQ(conversion->evaluate(), 8.000000);
}

TEST(FactoryTest, MixedEquation){
    char* test_val[10];
    test_val[0] = "./calculator";
    test_val[1] = "2";
    test_val[2] = "**";
    test_val[3] = "3";
    test_val[4] = "*";
    test_val[5] = "5";
    test_val[6] = "-";
    test_val[7] = "4";
    test_val[8] = "+";
    test_val[9] = "2";
    Factory* factoryTest = new Factory();

    Base* conversion = factoryTest->parse(test_val, 10);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "((((2.000000 ** 3.000000) * 5.000000) - 4.000000) + 2.000000)");
    EXPECT_EQ(conversion->evaluate(), 38.000000);
}
#endif
