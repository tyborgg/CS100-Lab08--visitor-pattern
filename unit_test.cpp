#include "factory.hpp"
#include "parse_test.hpp"
#include "parseTestv2.hpp"
#include "gtest/gtest.h"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
