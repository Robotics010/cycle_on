#ifndef NETWORK_TCP_SERVER_H_
#define NETWORK_TCP_SERVER_H_

#include <atomic>
#include <boost/asio.hpp>

#include "network/interface/tcp/common.hpp"

namespace cycleon {
namespace network {

class TcpServer final : public TcpBase {
 public:
  TcpServer();
  TcpServer(const std::string& address, unsigned short port);
  virtual ~TcpServer();
  void Start();
  void Stop();
 private:
  void BlockingRun();

  std::atomic_bool is_running_;
  ba::io_context io_context_;
};

}  // namespace network
}  // namespace cycleon

#endif  // NETWORK_TCP_SERVER_H_