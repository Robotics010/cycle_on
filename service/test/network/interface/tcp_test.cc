#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "network/interface/tcp/client.hpp"
#include "network/interface/tcp/server.hpp"

using namespace cycleon;

TEST(TcpServerTest, IsConstructed) {
  ::network::TcpServer tcp_server;
}

TEST(TcpClientTest, IsConstructed) {
  ::network::TcpClient tcp_client;
}

TEST(TcpClientServerTest, Echo) {
  std::string address = "localhost";
  unsigned short port = 8181;
  ::network::TcpServer tcp_server(address, port);
  ::network::TcpClient tcp_client(address, port);

}

TEST(TcpCommonTest, CheckIntToCharConversionWithLittleEndianess) {
  // 175 in Little-endian
  // 1: 175, 2: 0, 3: 0, 4: 0
  unsigned int n = 175;

  std::vector<unsigned char> bytes(4);
  bytes[0] = n & 0xFF;
  bytes[1] = (n >> 8) & 0xFF;
  bytes[2] = (n >> 16) & 0xFF;
  bytes[3] = (n >> 24) & 0xFF;

  EXPECT_EQ(bytes[0], 175);
  EXPECT_EQ(bytes[1], 0);
  EXPECT_EQ(bytes[2], 0);
  EXPECT_EQ(bytes[3], 0);
}

TEST(TcpCommonTest, CheckCharToIntConversionWithLittleEndianess) {
  std::vector<unsigned char> bytes = {175, 0, 0, 0};
  unsigned int n;
  n = bytes[0] + (bytes[1] << 8) + (bytes[2] << 16) + (bytes[3] << 24);
  EXPECT_EQ(n, 175);
}
