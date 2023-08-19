#include <gtest/gtest.h>

#include "runner/child.hpp"

using namespace cycleon;

class ChildModule : public ::testing::Test {
 protected:
  runner::Child child_runner;
};

TEST_F(ChildModule, IsConstructed) {
}
