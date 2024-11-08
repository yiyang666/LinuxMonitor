#pragma once

#include <string>
#include <unordered_map>

#include "monitor/monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class MemMonitor : public MonitorInter {
  struct MenInfo {
    int64_t total;    // 所有内存大小，除去一些预留空间
    int64_t free;     // 完全没用到的物理内存
    int64_t avail;    // 在不使用交换空间的情况下，启动一个新的应用最大可用内存的大小
    int64_t buffers;  // 块设备所占用的缓存页
    int64_t cached;   // 普通文件数据所占用的缓存页
    int64_t swap_cached; // 包含的是被确定要swapping换页，但是尚未写入物理交换区的匿名内存页
    int64_t active;
    int64_t in_active;
    int64_t active_anon;
    int64_t inactive_anon;
    int64_t active_file;
    int64_t inactive_file;
    int64_t dirty;
    int64_t writeback;
    int64_t anon_pages;
    int64_t mapped;
    int64_t kReclaimable;
    int64_t sReclaimable;
    int64_t sUnreclaim;
  };

 public:
  MemMonitor() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}
};

}  // namespace monitor