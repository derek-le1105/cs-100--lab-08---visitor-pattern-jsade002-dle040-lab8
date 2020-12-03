#ifndef __VISITOR_TESTS_HPP__
#define __VISITOR_TESTS_HPP__

#include "gtest/gtest.h"
#include "../base.hpp"
#include "../operations/Add.hpp"
#include "../operations/Mult.hpp"
#include "../operations/Sub.hpp"
#include "../operations/div.hpp"
#include "../operations/op.hpp"
#include "../operations/pow.hpp"
#include "../operations/rand.hpp"
#include "../iterator.hpp"
#include "../visitor.hpp"
#include "../preorder_iterator.cpp"

TEST(VisitorTest, VisitorWithIterator)
{
	CountVisitor* visitor = new CountVisitor();
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	Pow* temp = new Pow(num1, num2);
	Base* dummy = new Add(temp, num2);
	
	Iterator *it = dummy->create_iterator();

	CountVisitor* visit = new CountVisitor();
	it->first();
	while(!it->is_done()){
		Base* phase = it->current();
		phase->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->pow_count(), 1);
	EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, CountWithNoIterator)
{
	CountVisitor* v = new CountVisitor();
	Base* num1 = new Op(8);
	Base* num2 = new Op(4);

	num1->accept(v);
	EXPECT_EQ(v->op_count(), 1);
	num2->accept(v);
	EXPECT_EQ(v->op_count(), 2);

	Base* tmp1 = new Sub(num1, num2);
	Base* tmp2 = new Div(num1, num2);

	tmp1->accept(v);
	tmp2->accept(v);

	EXPECT_EQ(v->op_count(), 2);
	EXPECT_EQ(v->sub_count(), 1);
}

TEST(VisitorTest, VisitorWithPreorderIterator)
{
	CountVisitor* visitor = new CountVisitor();
	Base* num1 = new Op(5);
	Base* num2 = new Op(3);
	Base* num3 = new Op(6);
	Base* num4 = new Op(2);
	Pow* pow1 = new Pow(num1, num2);
	Add* add1 = new Add(num3, num4);
	
	Base* dummy = new Mult(pow1, add1);

	PreorderIterator *it = new PreorderIterator(dummy);

	CountVisitor* visit = new CountVisitor();
	it->first();
	while(!it->is_done()){
		Base* phase = it->current();
		phase->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 4);
	EXPECT_EQ(visit->pow_count(), 1);
	EXPECT_EQ(visit->add_count(), 1);
	EXPECT_EQ(visit->mult_count(), 0);
}

#endif
