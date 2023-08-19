#include "config/config.hpp"

using namespace cycleon;

Config::~Config() {}

void Config::setImplementation(ImplPtr implementation) {
    implementation_ = implementation;
}

void Config::Open() {
    implementation_->Open();
}

std::string Config::getString(const std::string& key) {
    return implementation_->getString(key);
}
int Config::getInt(const std::string& key) {
    return implementation_->getInt(key);
}

double Config::getDouble(const std::string& key) {
    return implementation_->getDouble(key);
}

bool Config::getBool(const std::string& key) {
    return implementation_->getBool(key);
}
