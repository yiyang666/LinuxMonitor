#pragma once

#include <grpcpp/support/status.h>

#include <unordered_map>
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
  // 需要继承proto中定义的gRPC服务
class GrpcManagerImpl : public monitor::proto::GrpcManager::Service {
 public:
  GrpcManagerImpl();

  virtual ~GrpcManagerImpl();

  ::grpc::Status SetMonitorInfo(::grpc::ServerContext* context,
                                const ::monitor::proto::MonitorInfo* request,
                                ::google::protobuf::Empty* response);
  ::grpc::Status GetMonitorInfo(::grpc::ServerContext* context,
                                const ::google::protobuf::Empty* request,
                                ::monitor::proto::MonitorInfo* response);

 private:
  monitor::proto::MonitorInfo monitor_infos_;
};

}  // namespace monitor
