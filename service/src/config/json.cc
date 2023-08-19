#include <fstream>
#include <boost/filesystem.hpp>

#include "config/json.hpp"

using namespace cycleon::config;
namespace bf = boost::filesystem;

Json::Json (const std::string& path): ImplementationBase(path) {
    
}

Json::~Json() {}

void Json::Open() {
    std::ifstream f(path_);
    parsed_data_ = json::parse(f);
};

std::string Json::getString(const std::string& key) {
    return parsed_data_[key].get<std::string>();
}

int Json::getInt(const std::string& key) {
    return parsed_data_[key].get<int>();
}

double Json::getDouble(const std::string& key) {
    return parsed_data_[key].get<double>();
}

bool Json::getBool(const std::string& key) {
    return parsed_data_[key].get<bool>();
}
