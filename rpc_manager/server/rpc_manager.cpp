#include "rpc_manager.h"  // 这里面包含了gRPC的服务

#include <iostream>

namespace monitor {
GrpcManagerImpl::GrpcManagerImpl() {}

GrpcManagerImpl::~GrpcManagerImpl() {}
// 响应客户端的请求，并把MonitorInfo存起来
::grpc::Status GrpcManagerImpl::SetMonitorInfo(
    ::grpc::ServerContext* context,
    const ::monitor::proto::MonitorInfo* request,
    ::google::protobuf::Empty* response) {
  monitor_infos_.Clear();     // 先清空上一次的消息
  monitor_infos_ = *request;  // 从传入参数解引用存起来

  return grpc::Status::OK;
}
// std::cout << "jinru" << request->soft_irq_size() << std::endl;
//    for (int i = 0; i < request->soft_irq_size(); i++) {
//      std::cout << request->soft_irq(i).cpu() << " " <<
//      request->soft_irq(i).hi()
//                << " " << request->soft_irq(i).timer() << " "
//                << request->soft_irq(i).net_tx() << " "
//                << request->soft_irq(i).net_rx() << " "
//                << request->soft_irq(i).block() << " "
//                << request->soft_irq(i).irq_poll() << std::endl;
//    }

::grpc::Status GrpcManagerImpl::GetMonitorInfo(
    ::grpc::ServerContext* context, const ::google::protobuf::Empty* request,
    ::monitor::proto::MonitorInfo* response) {
      
  *response = monitor_infos_;  //等价于response = &monitor_infos_
  return grpc::Status::OK;
}

//   monitor::proto::MonitorInfo monitor_info;
//   auto soft_irq = monitor_info.add_soft_irq();
//   soft_irq->set_cpu("cpu1");
//   soft_irq->set_hi(100);
//   soft_irq->set_timer(100);
//   soft_irq->set_net_tx(100);
//   soft_irq->set_net_rx(100);
//   auto soft_irq2 = monitor_info.add_soft_irq();
//   soft_irq2->set_cpu("cpu2");

//   for (int i = 0; i < monitor_infos_.soft_irq_size(); i++) {
//     std::cout << monitor_infos_.soft_irq(i).cpu() << " "
//               << monitor_infos_.soft_irq(i).hi() << " "
//               << monitor_infos_.soft_irq(i).timer() << " "
//               << monitor_infos_.soft_irq(i).net_tx() << " "
//               << monitor_infos_.soft_irq(i).net_rx() << " "
//               << monitor_infos_.soft_irq(i).block() << " "
//               << monitor_infos_.soft_irq(i).irq_poll() << std::endl;
//   }

}  // namespace monitor
