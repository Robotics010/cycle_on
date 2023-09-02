#ifndef NETWORK_TCP_CLIENT_H_
#define NETWORK_TCP_CLIENT_H_

#include <boost/asio.hpp>
#include <vector>

#include "network/interface/tcp/common.hpp"

namespace ba = boost::asio;

namespace cycleon {
namespace network {

class TcpClient final : public TcpBase {
 public:
  TcpClient();
  TcpClient(const std::string& address, unsigned short port);
  virtual ~TcpClient();
  std::vector<unsigned char> SendAndRecieve(
      const std::vector<unsigned char>& request);
 private:
  TcpSocket Connect();
  void Disconnect(TcpSocket& socket);

  ba::io_context io_context_;
};

}  // namespace network
}  // namespace cycleon

#endif  // NETWORK_TCP_CLIENT_H_