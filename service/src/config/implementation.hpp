#ifndef CONFIG_IMPL_H_
#define CONFIG_IMPL_H_

#include <string>

namespace cycleon {
namespace config {

class ImplementationBase {
 public:
  explicit ImplementationBase(const std::string& path) : path_(path) {}
  virtual ~ImplementationBase() {}
  virtual void Open() = 0;
  virtual std::string getString(const std::string& key) = 0;
  virtual int getInt(const std::string& key) = 0;
  virtual double getDouble(const std::string& key) = 0;
  virtual bool getBool(const std::string& key) = 0;

 protected:
  const std::string path_;
};

}  // namespace config
}  // namespace cycleon

#endif  // CONFIG_IMPL_H_
