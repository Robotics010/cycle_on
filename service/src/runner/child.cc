#include "runner/child.hpp"

#include <boost/process/args.hpp>
#include <cstdlib>
#include <string>
#include <vector>

using namespace cycleon::runner;

Child::Child(const std::vector<std::string>& arguments)
    : arguments_(arguments) {}

void Child::Open() { child_.reset(new bp::child(bp::args(arguments_))); }

void Child::Close() { child_->terminate(); }
