#pragma once
#include <memory>
#include <thread>
#include <vector>

#include "client/rpc_client.h"
#include "monitor/cpu_load_monitor.h"
#include "monitor/cpu_softirq_monitor.h"
#include "monitor/cpu_stat_monitor.h"
#include "monitor/mem_monitor.h"
#include "monitor/monitor_inter.h"
#include "monitor/net_monitor.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

int main() {

  // 创建基类智能指针数组，让基类的智能指针指向子类对象，实现多态
  std::vector<std::shared_ptr<monitor::MonitorInter>> runners_;
  runners_.emplace_back(new monitor::CpuSoftIrqMonitor());
  runners_.emplace_back(new monitor::CpuLoadMonitor());
  runners_.emplace_back(new monitor::CpuStatMonitor());
  runners_.emplace_back(new monitor::MemMonitor());
  runners_.emplace_back(new monitor::NetMonitor());

  monitor::RpcClient rpc_client_;
  char *name = getenv("USER");
  std::unique_ptr<std::thread> thread_ = nullptr;
  // 这里是通过lambda函数实现线程的回调函数，让代码更紧凑
  thread_ = std::make_unique<std::thread>([&]() {
    while (true) {
      monitor::proto::MonitorInfo monitor_info;
      monitor_info.set_name(std::string(name));
      for (auto& runner : runners_) {
        // 不同对象调用同一个函数，实现不同的更新操作，将monitor_info传出
        // monitor_info类嵌套了不同的消息类，在里面创建出来被赋值后传出
        runner->UpdateOnce(&monitor_info);
      }

      // 一次把所有状态参数更新后，传给grpc，它负责传输protobuf数据
      rpc_client_.SetMonitorInfo(monitor_info);
      // 每三秒调用一次，进行更新
      std::this_thread::sleep_for(std::chrono::seconds(3));
    }
  });

  // 交给父线程管理生存周期
  thread_->join();
  return 0;
}
