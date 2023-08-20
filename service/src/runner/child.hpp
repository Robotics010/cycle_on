#ifndef RUNNER_CHILD_H_
#define RUNNER_CHILD_H_

#include <boost/process/child.hpp>
#include <memory>

#include "runner/module.hpp"

namespace bp = boost::process;
typedef std::shared_ptr<bp::child> childPtr;

namespace cycleon {
namespace runner {

class Child final : public ModuleBase {
 public:
  virtual ~Child();
  void Open() override;
  void Close() override;

 private:
  childPtr child_;
};

}  // namespace runner
}  // namespace cycleon

#endif  // RUNNER_CHILD_H_
