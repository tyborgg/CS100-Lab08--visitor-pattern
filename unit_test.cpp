#include "iterator_test.hpp"
#include "add.hpp"
#include "base.hpp"
#include "gtest/gtest.h"
#include "visitor_test.hpp"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
