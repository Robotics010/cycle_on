#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <memory>
#include <vector>

#include "runner/module.hpp"

namespace cycleon {

typedef std::shared_ptr<runner::ModuleBase> ModuleBasePtr;

class Server {
 public:
  void addRunner(ModuleBasePtr runner);
  void startAllRunners();
  void stopAllRunners();

 private:
  std::vector<ModuleBasePtr> runners_;
};

}  // namespace cycleon

#endif  // SERVER_SERVER_H_
