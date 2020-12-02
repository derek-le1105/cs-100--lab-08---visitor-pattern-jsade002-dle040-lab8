#ifndef __LIST_TESTS_HPP__
#define __LIST_TESTS_HPP__

#include "gtest/gtest.h"
#include "../list_container.hpp"
#include "../operations/op.hpp"
#include "../operations/Add.hpp"
#include <iostream>

TEST(ListContainerTestSet, AddElementTest){
    Base* nine = new Op(9);

    listContainer* test_container = new listContainer();
    test_container->add_element(nine);
    EXPECT_EQ(test_container->at(0)->evaluate(), 9);
}

TEST(ListContainerTestSet, SwapTest){
    Base* seven = new Op(7);
    Base* eight = new Op(8);

    listContainer* test_container = new listContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);
	
    ASSERT_EQ(test_container->size(), 2);
    test_container->swap(0, 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 8);
    EXPECT_EQ(test_container->at(1)->evaluate(), 7);
}

TEST(ListContainerTestSet, SizeTest){
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    Op* nine = new Op(9);

    listContainer* test_container = new listContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);
    test_container->add_element(nine);

    EXPECT_EQ(test_container->size(), 3);
}

TEST(ListContainerTestSet, PrintTest){
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    Add* test = new Add(seven, eight);
    listContainer* test_container = new listContainer();

    test_container->add_element(test);

    testing::internal::CaptureStdout();
    test_container->print();
    std::string testExpression = testing::internal::GetCapturedStdout();
    EXPECT_EQ(testExpression, "(7.000000 + 8.000000)");
}

#endif
