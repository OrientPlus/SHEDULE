// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: schedule.proto
#ifndef GRPC_schedule_2eproto__INCLUDED
#define GRPC_schedule_2eproto__INCLUDED

#include "schedule.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace schedule {

class SheduleService final {
 public:
  static constexpr char const* service_full_name() {
    return "schedule.SheduleService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::schedule::ScheduleResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::schedule::ScheduleResponse>> AsyncGetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::schedule::ScheduleResponse>>(AsyncGetScheduleRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::schedule::ScheduleResponse>> PrepareAsyncGetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::schedule::ScheduleResponse>>(PrepareAsyncGetScheduleRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::schedule::ScheduleResponse>* AsyncGetScheduleRaw(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::schedule::ScheduleResponse>* PrepareAsyncGetScheduleRaw(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::schedule::ScheduleResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>> AsyncGetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>>(AsyncGetScheduleRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>> PrepareAsyncGetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>>(PrepareAsyncGetScheduleRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response, std::function<void(::grpc::Status)>) override;
      void GetSchedule(::grpc::ClientContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>* AsyncGetScheduleRaw(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::schedule::ScheduleResponse>* PrepareAsyncGetScheduleRaw(::grpc::ClientContext* context, const ::schedule::ScheduleRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetSchedule_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status GetSchedule(::grpc::ServerContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetSchedule : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetSchedule() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetSchedule() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetSchedule(::grpc::ServerContext* /*context*/, const ::schedule::ScheduleRequest* /*request*/, ::schedule::ScheduleResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetSchedule(::grpc::ServerContext* context, ::schedule::ScheduleRequest* request, ::grpc::ServerAsyncResponseWriter< ::schedule::ScheduleResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetSchedule<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_GetSchedule : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetSchedule() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::schedule::ScheduleRequest, ::schedule::ScheduleResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::schedule::ScheduleRequest* request, ::schedule::ScheduleResponse* response) { return this->GetSchedule(context, request, response); }));}
    void SetMessageAllocatorFor_GetSchedule(
        ::grpc::MessageAllocator< ::schedule::ScheduleRequest, ::schedule::ScheduleResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::schedule::ScheduleRequest, ::schedule::ScheduleResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_GetSchedule() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetSchedule(::grpc::ServerContext* /*context*/, const ::schedule::ScheduleRequest* /*request*/, ::schedule::ScheduleResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetSchedule(
      ::grpc::CallbackServerContext* /*context*/, const ::schedule::ScheduleRequest* /*request*/, ::schedule::ScheduleResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_GetSchedule<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetSchedule : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetSchedule() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetSchedule() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetSchedule(::grpc::ServerContext* /*context*/, const ::schedule::ScheduleRequest* /*request*/, ::schedule::ScheduleResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetSchedule : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetSchedule() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetSchedule() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetSchedule(::grpc::ServerContext* /*context*/, const ::schedule::ScheduleRequest* /*request*/, ::schedule::ScheduleResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetSchedule(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetSchedule : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetSchedule() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetSchedule(context, request, response); }));
    }
    ~WithRawCallbackMethod_GetSchedule() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetSchedule(::grpc::ServerContext* /*context*/, const ::schedule::ScheduleRequest* /*request*/, ::schedule::ScheduleResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetSchedule(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetSchedule : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetSchedule() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::schedule::ScheduleRequest, ::schedule::ScheduleResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::schedule::ScheduleRequest, ::schedule::ScheduleResponse>* streamer) {
                       return this->StreamedGetSchedule(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GetSchedule() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetSchedule(::grpc::ServerContext* /*context*/, const ::schedule::ScheduleRequest* /*request*/, ::schedule::ScheduleResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetSchedule(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::schedule::ScheduleRequest,::schedule::ScheduleResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GetSchedule<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_GetSchedule<Service > StreamedService;
};

}  // namespace schedule


#endif  // GRPC_schedule_2eproto__INCLUDED
