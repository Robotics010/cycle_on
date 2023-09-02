#include "network/interface/tcp/client.hpp"

using namespace cycleon::network;

TcpClient::TcpClient() : io_context_() {}

TcpClient::TcpClient(const std::string& address, unsigned short port)
    : TcpBase(address, port) {}

TcpClient::~TcpClient() {}

std::vector<unsigned char> TcpClient::SendAndRecieve(
    const std::vector<unsigned char>& request) {
  auto socket = Connect();
  Write(socket, request);
  auto response = Read(socket);
  //   std::vector<unsigned char> response;
  Disconnect(socket);
  return response;
}

TcpSocket TcpClient::Connect() {
  auto socket = TcpSocket(io_context_);
  ba::ip::address ip_address = ba::ip::address::from_string(address_);
  socket.connect(ba::ip::tcp::endpoint(ip_address, port_));
  return socket;
}

void TcpClient::Disconnect(TcpSocket& socket) {
  socket.shutdown(ba::ip::tcp::socket::shutdown_both);
  socket.close();
}
