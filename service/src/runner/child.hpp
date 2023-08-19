#ifndef RUNNER_CHILD_H_
#define RUNNER_CHILD_H_

#include <memory>
#include <boost/process/child.hpp>

#include "runner/module.hpp"

namespace bp = boost::process;
typedef std::shared_ptr<bp::child> childPtr;

namespace cycleon {
namespace runner {

class Child final : public ModuleBase {
 public:
  virtual ~Child();
  virtual void Open() override;
  virtual void Close() override;
 private:
    childPtr child_;
};

} // runner
} // cycleon

#endif  // RUNNER_CHILD_H_
