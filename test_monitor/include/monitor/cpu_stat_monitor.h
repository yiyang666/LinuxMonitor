#pragma once

#include <string>
#include <unordered_map>

#include "monitor/monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class CpuStatMonitor : public MonitorInter {
  struct CpuStat {
    std::string cpu_name;
    float user;   // 用户态cpu时间
    float system; // 代表内核态CPU时间
    float idle;   // 代表空闲时间
    float nice;   // 低优先级用户态CPU时间
    float io_wait;// 代表等待 I/O 的CPU时间
    float irq;    // 处理硬中断的 CPU 时间
    float soft_irq;// 处理软中断的 CPU 时间
    float steal;    // 代表当系统运行在虚拟机中的时候，被其他虚拟机占用的 CPU 时间。
    float guest;    // 代表通过虚拟化运行其他操作系统的时间，也就是运行虚拟机的 CPU 时间。
    float guest_nice;// 代表以低优先级运行虚拟机的时间
  };

 public:
  CpuStatMonitor() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}

 private:
  std::unordered_map<std::string, struct CpuStat> cpu_stat_map_;
};

}  // namespace monitor
