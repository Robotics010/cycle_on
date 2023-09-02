#include <gtest/gtest.h>

#include <iostream>

#include "network/interface/tcp/client.hpp"

using namespace cycleon;

TEST(TcpClientTest, IsConstructed) {
  ::network::TcpClient tcp_client();
}
