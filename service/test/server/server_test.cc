#include <memory>
#include <gtest/gtest.h>

#include "runner/fake.hpp"

#include "server.hpp"

using namespace cycleon;

class CycleOnServer : public ::testing::Test {
 protected:
  Server server;
};

TEST_F(CycleOnServer, Constructed) {
}

TEST_F(CycleOnServer, BuildWithFakeModule) {
  std::shared_ptr<runner::Fake> fake_runner;
  fake_runner.reset(new runner::Fake());
  server.addRunner(fake_runner);
}

TEST_F(CycleOnServer, StartFakeModule) {
  std::shared_ptr<runner::Fake> fake_runner;
  fake_runner.reset(new runner::Fake());
  server.addRunner(fake_runner);
  EXPECT_FALSE(fake_runner->was_Open_called());
  server.startAllRunners();
  EXPECT_TRUE(fake_runner->was_Open_called());
}

TEST_F(CycleOnServer, StopFakeModule) {
  std::shared_ptr<runner::Fake> fake_runner;
  fake_runner.reset(new runner::Fake());
  server.addRunner(fake_runner);
  server.startAllRunners();
  EXPECT_FALSE(fake_runner->was_Close_called());
  server.stopAllRunners();
  EXPECT_TRUE(fake_runner->was_Close_called());
}
