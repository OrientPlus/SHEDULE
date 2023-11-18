// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: schedule.proto

#include "schedule.pb.h"
#include "schedule.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace schedule {

static const char* SheduleService_method_names[] = {
  "/schedule.SheduleService/GetSchedule",
};

std::unique_ptr< SheduleService::Stub> SheduleService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SheduleService::Stub> stub(new SheduleService::Stub(channel, options));
  return stub;
}

SheduleService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetSchedule_(SheduleService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status SheduleService::Stub::GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::schedule::ScheduleResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::schedule::ScheduleRequest, ::schedule::ScheduleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetSchedule_, context, request, response);
}

void SheduleService::Stub::async::GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::schedule::ScheduleRequest, ::schedule::ScheduleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetSchedule_, context, request, response, std::move(f));
}

void SheduleService::Stub::async::GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetSchedule_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>* SheduleService::Stub::PrepareAsyncGetScheduleRaw(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::schedule::ScheduleResponse, ::schedule::ScheduleRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetSchedule_, context, request);
}

::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>* SheduleService::Stub::AsyncGetScheduleRaw(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetScheduleRaw(context, request, cq);
  result->StartCall();
  return result;
}

SheduleService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SheduleService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SheduleService::Service, ::schedule::ScheduleRequest, ::schedule::ScheduleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SheduleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::schedule::ScheduleRequest* req,
             ::schedule::ScheduleResponse* resp) {
               return service->GetSchedule(ctx, req, resp);
             }, this)));
}

SheduleService::Service::~Service() {
}

::grpc::Status SheduleService::Service::GetSchedule(::grpc::ServerContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace schedule

