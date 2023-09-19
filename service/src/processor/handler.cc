#include "processor/handler.hpp"

#include <algorithm>

using namespace cycleon::processor;
using namespace cycleon::message;

std::vector<unsigned char> Handler::Process(
    const std::vector<unsigned char>& raw_request) {
  auto request = json_over_tcp_adapter_.GetRequest(raw_request);
  auto response = ProcessRequest(request);
  auto raw_response = json_over_tcp_adapter_.CreateResponse(response);
  return raw_response;
}

Response Handler::ProcessRequest(const Request& request) {
  Response response;

  switch (request.type)
  {
  case REQUEST_ADD_ACTION:
    AddAction(request, &response);
    break;
  case REQUEST_REMOVE_ACTION:
    RemoveAction(request, &response);
    break;
  case REQUEST_GET_ACTION_STATUS:
    GetActionStatus(request, &response);
    break;
  case REQUEST_GET_ACTION_RESULT:
    GetActionResult(request, &response);
    break;
  
  case REQUEST_INVALID:
  default:
    Invalid(request, &response);
    break;
  }

  return response;
}

void Handler::AddAction(const Request& request, Response* response) {
  request.action;
  
  response->action_id;
  response->type = RESPONSE_ADD_ACTION;
}

void Handler::RemoveAction(const Request& request, Response* response) {

}

void Handler::GetActionStatus(const Request& request, Response* response) {

}

void Handler::GetActionResult(const Request& request, Response* response) {

}

void Handler::Invalid(const Request& request, Response* response) {

}
