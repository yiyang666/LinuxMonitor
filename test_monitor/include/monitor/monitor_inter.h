#pragma once

#include <string>

#include "monitor/monitor_inter.h"
#include "monitor_info.grpc.pb.h"

// 工厂模式
namespace monitor {
class MonitorInter {
 public:
  MonitorInter() {}
  virtual ~MonitorInter() {}
  // 纯虚函数：更新数值，停止，子类必须重写纯虚函数
  virtual void UpdateOnce(monitor::proto::MonitorInfo* monitor_info) = 0;
  virtual void Stop() = 0;
};
}  // namespace monitor