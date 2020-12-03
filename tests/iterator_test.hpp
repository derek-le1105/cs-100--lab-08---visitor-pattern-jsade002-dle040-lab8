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

    Iterator* it = new Add(temp, num3);
    it->first();

    //while(!it->is_done()){
        Base* phase = it->current();

    //}
    EXPECT_EQ(phase->stringify, "8.000000");
}



#endif