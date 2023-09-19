#ifndef PROCESSOR_HANDLER_H_
#define PROCESSOR_HANDLER_H_

#include "processor/processor.hpp"

#include "network/adapter/json_over_tcp.hpp"
#include "message/response.hpp"
#include "message/request.hpp"


namespace cycleon {
namespace processor {

class Handler : public ProcessorBase {
 public:
  std::vector<unsigned char> Process(
      const std::vector<unsigned char>& raw_request) override;
  private:
    message::Response ProcessRequest(const message::Request& request);
    void AddAction(const message::Request& request, message::Response* response);
    void RemoveAction(const message::Request& request, message::Response* response);
    void GetActionStatus(const message::Request& request, message::Response* response);
    void GetActionResult(const message::Request& request, message::Response* response);
    void Invalid(const message::Request& request, message::Response* response);
    
    adapter::JsonOverTcp json_over_tcp_adapter_;
};

}  // namespace processor
}  // namespace cycleon

#endif  // PROCESSOR_HANDLER_H_
