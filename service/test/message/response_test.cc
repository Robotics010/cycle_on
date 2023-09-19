#include <gtest/gtest.h>

#include "message/response.hpp"

using namespace cycleon;

TEST(ResponseTest, AddAction) {
  ::message::Response response;
  response.type = message::RESPONSE_ADD_ACTION;
  response.result.type = message::PASS;
}
