#ifndef CONFIG_JSON_H_
#define CONFIG_JSON_H_

#include <nlohmann/json.hpp>
#include <string>

#include "config/implementation.hpp"

using json = nlohmann::json;

namespace cycleon {
namespace config {

class Json final : public ImplementationBase {
 public:
  explicit Json(const std::string& path);
  ~Json();
  void Open() override;
  std::string getString(const std::string& key) override;
  int getInt(const std::string& key) override;
  double getDouble(const std::string& key) override;
  bool getBool(const std::string& key) override;

 private:
  json parsed_data_;
};

}  // namespace config
}  // namespace cycleon

#endif  // CONFIG_JSON_H_
