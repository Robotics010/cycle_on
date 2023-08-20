#include "server.hpp"

using namespace cycleon;

void Server::addRunner(ModuleBasePtr runner) { runners_.push_back(runner); }

void Server::startAllRunners() {
  for (const auto& runner : runners_) {
    runner->Launch();
  }
}

void Server::stopAllRunners() {
  for (const auto& runner : runners_) {
    runner->Shutdown();
  }
}
