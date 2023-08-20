#include "runner/child.hpp"

#include <boost/process/args.hpp>
#include <cstdlib>
#include <string>
#include <vector>

using namespace cycleon::runner;

Child::~Child() {}

void Child::Open() {
  std::vector<std::string> arguments;
  child_.reset(new bp::child(bp::args(arguments)));
}

void Child::Close() { child_->terminate(); }
