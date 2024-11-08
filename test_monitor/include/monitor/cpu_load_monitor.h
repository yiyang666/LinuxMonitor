#pragma once

#include <string>

#include "monitor/monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class CpuLoadMonitor : public MonitorInter {
 public:
  CpuLoadMonitor() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}

 private:
  float load_avg_1_; // 1分钟平均负载
  float load_avg_3_; // 5 分钟平均负载
  float load_avg_15_;// 15 分钟平均负载
};

}  // namespace monitor
