#ifndef __VECTOR_TESTS_HPP__
#define __VECTOR_TESTS_HPP__

#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "../VectorContainer.hpp"

TEST(VectorContainerTestSet, AddElementTest) {
    Op* seven = new Op(7);
	Op* eight = new Op(8);
	
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
	test_container->add_element(eight);
	
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
	EXPECT_EQ(test_container->at(1)->evaluate(), 8);
}

TEST(VectorContainerTestSet, SwapTest) {
    Op* seven = new Op(7);
	Op* eight = new Op(8);
	
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
	test_container->add_element(eight);

    ASSERT_EQ(test_container->size(), 2);
	test_container->swap(0, 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 8);
	EXPECT_EQ(test_container->at(1)->evaluate(), 7);
}

TEST(VectorContainerTestSet, SizeTest) {
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    Op* nine = new Op(9);
	
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);
    test_container->add_element(nine);
	
    EXPECT_EQ(test_container->size(), 3);
}

TEST(VectorContainerTestSet, PrintTest) {
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    Mult* TreeA = new Mult(seven, eight);
	
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(TreeA);
	
    testing::internal::CaptureStdout();
    test_container->print();
    std::string output = testing::internal::GetCapturedStdout();  
    EXPECT_EQ(output, "(7.000000 * 8.000000)");
}

#endif
