#include "monitor/cpu_load_monitor.h"

#include "utils/read_file.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
void CpuLoadMonitor::UpdateOnce(monitor::proto::MonitorInfo* monitor_info) {
  
  // 初始化ReadFile对象，得到对应的文件流，目的是获取对应的状态数值
  ReadFile cpu_load_file(std::string("/proc/loadavg"));
  std::vector<std::string> cpu_load;  // 传出数组
  cpu_load_file.ReadLine(&cpu_load);  // 获取到这些数值
  load_avg_1_ = std::stof(cpu_load[0]); // 进行转换string to float
  load_avg_3_ = std::stof(cpu_load[1]);
  load_avg_15_ = std::stof(cpu_load[2]);

  // 创建protobuf对象，并赋值
  auto cpu_load_msg = monitor_info->mutable_cpu_load();
  cpu_load_msg->set_load_avg_1(load_avg_1_);
  cpu_load_msg->set_load_avg_3(load_avg_3_);
  cpu_load_msg->set_load_avg_15(load_avg_15_);

  // 最后通过UpdateOnce函数将monitor_info传出
  // monitor_info（proto文件中定义的类）
  return;
}

}  // namespace monitor