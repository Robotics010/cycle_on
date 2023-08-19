#ifndef CONFIG_CONFIG_H_
#define CONFIG_CONFIG_H_

#include <memory>
#include <string>

#include "config/config.hpp"
#include "config/implementation.hpp"

typedef std::shared_ptr<cycleon::config::ImplementationBase> ImplPtr;

namespace cycleon {

class Config {
 public:
  ~Config();
  void setImplementation(ImplPtr implementation);
  void Open();
  std::string getString(const std::string& key);
  int getInt(const std::string& key);
  double getDouble(const std::string& key);
  bool getBool(const std::string& key);
 private:
  ImplPtr implementation_;
};

}

#endif  // CONFIG_CONFIG_H_
