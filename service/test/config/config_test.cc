#include "config/config.hpp"

#include <gtest/gtest.h>

#include <boost/filesystem.hpp>

#include "config/json.hpp"

using namespace cycleon;
namespace bf = boost::filesystem;
typedef std::shared_ptr<cycleon::config::Json> JsonPtr;

class ConfigTest : public ::testing::Test {
 protected:
  Config config;
};

TEST_F(ConfigTest, IsConstructed) {}

// TEST_F(ConfigTest, ConstructedWithNoPath) {
//   JsonPtr json_impl = std::make_shared<config::Json>();
//   config.setImplementation(json_impl);
// }

TEST_F(ConfigTest, ThrowIfJsonNotExists) {
  std::string config_path = "non_existed.json";
  ASSERT_FALSE(bf::exists(config_path));
  JsonPtr json_impl = std::make_shared<config::Json>(config_path);
  config.setImplementation(json_impl);
  EXPECT_ANY_THROW({ config.Open(); });
}

TEST_F(ConfigTest, OpenJson) {
  std::string config_path = "config_test.json";
  ASSERT_TRUE(bf::exists(config_path));

  JsonPtr json_impl = std::make_shared<config::Json>(config_path);
  config.setImplementation(json_impl);
  config.Open();

  EXPECT_STREQ(config.getString("hello").c_str(), "World");
  EXPECT_EQ(config.getInt("index"), 12);
  EXPECT_DOUBLE_EQ(config.getDouble("pi"), 3.141);
  EXPECT_TRUE(config.getBool("happy"));
}
