#pragma once

#include <string>
#include <unordered_map>
#include <boost/chrono.hpp>

#include "monitor/monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class NetMonitor : public MonitorInter {
  struct NetInfo {
    std::string name;
    int64_t rcv_bytes;    // 接口接收的数据的总字节数
    int64_t rcv_packets;  // 接口接收的数据包总数
    int64_t err_in;       // 由设备驱动程序检测到的接收错误的总数
    int64_t drop_in;      // 设备驱动程序丢弃的接收数据包总数
    int64_t snd_bytes;    // 接口发送的数据的总字节数
    int64_t snd_packets;  // 接口发送的数据包总数
    int64_t err_out;      // 由设备驱动程序检测到的发送错误的总数
    int64_t drop_out;     // 设备驱动程序丢弃的发送数据包总数
    boost::chrono::steady_clock::time_point timepoint;
  };

 public:
  NetMonitor() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}

 private:
  std::unordered_map<std::string, struct NetInfo> net_info_;
};

}  // namespace monitor