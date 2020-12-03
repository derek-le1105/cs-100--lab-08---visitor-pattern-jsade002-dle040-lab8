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

    
}



#endif
