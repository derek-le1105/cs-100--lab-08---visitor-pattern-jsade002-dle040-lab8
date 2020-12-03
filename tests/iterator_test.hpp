#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../base.hpp"
#include "../operations/Add.hpp"
#include "../operations/pow.hpp"
#include "../iterator.hpp"

TEST(IteratorTest, BinaryPowTest){
    Base* num1 = new Op(2);
    Base* num2 = new Op(3);
    Base* num3 = new Op(4);

    Pow* temp = new Pow(num1, num2);

    Base* dummy  = new Add(temp, num3);
    Iterator* it = dummy->create_iterator();
    it->first();

    Base* phase = it->current();
    ASSERT_NE(phase, nullptr);
    EXPECT_EQ(phase->stringify(), "(2.000000 ** 3.000000)");
    it->next();
    
    phase = it->current();
    ASSERT_NE(phase, nullptr);
    EXPECT_EQ(phase->stringify(), "4.000000");
}

TEST(IteratorTest, BinaryMultTest){
    Base* num1 = new Op(2);
    Base* num2 = new Op(3);
    Base* num3 = new Op(4);
    Base* num4 = new Op(9);

    Mult* temp = new Mult(num1, num2);

    Add* temp2  = new Add(temp, num3);
 
    Base* dummy = new Sub(temp2, num4);
    Iterator* it = dummy->create_iterator();
    it->first();

    Base* phase = it->current();
    ASSERT_NE(phase, nullptr);
    EXPECT_EQ(phase->evaluate(), 10);
    it->next();

    phase = it->current();
    ASSERT_NE(phase, nullptr);
    EXPECT_EQ(phase->evaluate(), 9);
}




#endif
