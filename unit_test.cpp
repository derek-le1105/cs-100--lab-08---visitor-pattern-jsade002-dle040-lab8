#include "gtest/gtest.h"

#include "tests/op_test.hpp"
#include "tests/mult_test.hpp"
#include "tests/add_test.hpp"
#include "tests/pow_test.hpp"
#include "tests/div_test.hpp"
#include "tests/rand_test.hpp"
#include "tests/sub_test.hpp"
#include "tests/List_tests.hpp"
#include "tests/Sort_Tests.hpp"
#include "tests/Vector_Tests.hpp"
#include "tests/factory_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

