#include "runner/child.hpp"

#include <gtest/gtest.h>

using namespace cycleon;

class ChildModule : public ::testing::Test {
 protected:
  runner::Child child_runner;
};

TEST_F(ChildModule, IsConstructed) {}
