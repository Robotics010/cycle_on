#include <cstdlib>
#include <vector>
#include <string>
#include <boost/process/args.hpp>

#include "runner/child.hpp"

using namespace cycleon::runner;

Child::~Child() {}

void Child::Open() {
    std::vector<std::string> arguments;
    child_.reset(new bp::child(bp::args (arguments)));
}

void Child::Close() {
    child_->terminate();
}
