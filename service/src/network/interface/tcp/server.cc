#include "network/interface/tcp/server.hpp"

#include "network/interface/tcp/common.hpp"

using namespace cycleon::network;

TcpServer::TcpServer(): is_running_(false) {}
TcpServer::TcpServer(const std::string& address, unsigned short port)
    : TcpBase(address, port), is_running_(false) {}

TcpServer::~TcpServer() {}

void TcpServer::Start() {
    is_running_ = true;
    // ToDo: run in thread
    BlockingRun();
}

void TcpServer::Stop() {
    is_running_ = false;
    // ToDo: join thread
}

void TcpServer::BlockingRun() {
    while (is_running_) {

    }
}
